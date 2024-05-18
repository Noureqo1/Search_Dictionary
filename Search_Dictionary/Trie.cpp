#include "TRIE.h"

// Function to compute Levenshtein distance between two strings
int levenshteinDistance(const std::string& word1, const std::string& word2) {
    int m = word1.length();
    int n = word2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;

    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
        }
    }

    return dp[m][n];
}

Trie::Trie() {
    root = new TrieNode();
    for (int i = 0; i < 26; i++) {
        root->children[i] = nullptr;
    }
    root->isEndOfWord = false;
}

void Trie::insert(const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (curr->children[index] == nullptr) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (curr->children[index] == nullptr) {
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

void Trie::remove(const std::string& word) {
    DELETE(root, word, 0);
}

void Trie::DELETE(TrieNode* node, const std::string& word, int depth) {
    if (node == nullptr) {
        return;
    }
    if (depth == word.length()) {
        node->isEndOfWord = false;
        return;
    }
    int index = word[depth] - 'a';
    DELETE(node->children[index], word, depth + 1);
    if (node->isEndOfWord) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            return;
        }
    }
    delete node;
    node = nullptr;
}

void Trie::printAllWords() {
    std::cout << "All words in the Trie:" << std::endl;
    getAll(root, "");
}

void Trie::getAll(TrieNode* node, std::string currWord) {
    if (node->isEndOfWord) {
        std::cout << currWord << std::endl;
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            char c = 'a' + i;
            getAll(node->children[i], currWord + c);
        }
    }
}

bool Trie::singleWordSearch(const std::string& word) {
    return search(word);
}

bool Trie::searchMultipleWords(const std::string words[], int count, bool results[]) {
    for (int i = 0; i < count; i++) {
        results[i] = search(words[i]);
    }
    return true;
}

std::vector<std::string> Trie::searchMisspelledWord(const std::string& word, int maxDistance) {
    std::vector<std::string> similarWords;
    fuzzySearch(word, maxDistance, root, "", similarWords);
    return similarWords;
}

void Trie::fuzzySearch(const std::string& word, int maxDistance, TrieNode* node, std::string currWord, std::vector<std::string>& similarWords) {
    if (node->isEndOfWord && levenshteinDistance(word, currWord) <= maxDistance) {
        similarWords.push_back(currWord);
    }

    for (int i = 0; i < 26; ++i) {
        if (node->children[i] != nullptr) {
            char c = 'a' + i;
            fuzzySearch(word, maxDistance, node->children[i], currWord + c, similarWords);
        }
    }
}

void Trie::wildcardSearch(const std::string& pattern, int patternIndex, TrieNode* node, std::string currWord, std::vector<std::string>& matches) {
    if (node == nullptr)
        return;

    if (patternIndex == pattern.length()) {
        if (node->isEndOfWord)
            matches.push_back(currWord);
        return;
    }

    if (pattern[patternIndex] == '*') {
        // Match any character
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char c = 'a' + i;
                wildcardSearch(pattern, patternIndex + 1, node->children[i], currWord + c, matches);
            }
        }
    }
    else {
        int index = pattern[patternIndex] - 'a';
        if (node->children[index] != nullptr) {
            wildcardSearch(pattern, patternIndex + 1, node->children[index], currWord + pattern[patternIndex], matches);
        }
    }
}

void Trie::suffixSearch(TrieNode* node, std::string suffix, std::string currWord, std::vector<std::string>& matches) {
    if (node == nullptr)
        return;

    if (suffix.empty()) {
        if (node->isEndOfWord)
            matches.push_back(currWord);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            char c = 'a' + i;
            suffixSearch(node->children[i], suffix, currWord + c, matches);
        }
    }
}

std::vector<std::string> Trie::suffixPatternSearch(const std::string& suffix) {
    std::vector<std::string> matches;
    suffixSearch(root, suffix, "", matches);
    return matches;
}

std::vector<std::string> Trie::prefixPatternSearch(const std::string& prefix) {
    std::vector<std::string> matches;
    prefixSearch(root, prefix, "", matches);
    return matches;
}

void Trie::prefixSearch(TrieNode* node, std::string prefix, std::string currWord, std::vector<std::string>& matches) {
    if (node == nullptr)
        return;

    if (prefix.empty()) {
        if (node->isEndOfWord)
            matches.push_back(currWord);
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char c = 'a' + i;
                prefixSearch(node->children[i], prefix, currWord + c, matches);
            }
        }
    }
    else {
        int index = prefix[0] - 'a';
        if (node->children[index] != nullptr) {
            prefixSearch(node->children[index], prefix.substr(1), currWord + prefix[0], matches);
        }
    }
}

