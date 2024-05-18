#include <string>
#include <iostream>
#include <vector>

class TrieNode 
{
public:
    TrieNode* children[26];
    bool isEndOfWord;
};

class Trie 
{
public:

    Trie();

    void insert(const std::string& word);
    bool search(const std::string& word);
    void remove(const std::string& word);

    void printAllWords();

    bool singleWordSearch(const std::string& word);
    bool searchMultipleWords(const std::string words[], int count, bool results[]);

    std::vector<std::string> searchMisspelledWord(const std::string& word, int maxDistance);
    void fuzzySearch(const std::string& word, int maxDistance, TrieNode* node, std::string currWord, std::vector<std::string>& similarWords);

    void wildcardSearch(const std::string& pattern, int patternIndex, TrieNode* node, std::string currWord, std::vector<std::string>& matches);

    std::vector<std::string> suffixPatternSearch(const std::string& suffix);
    void suffixSearch(TrieNode* node, std::string suffix, std::string currWord, std::vector<std::string>& matches);

    std::vector<std::string> prefixPatternSearch(const std::string& prefix);
    void prefixSearch(TrieNode* node, std::string prefix, std::string currWord, std::vector<std::string>& matches);

private:

    TrieNode* root;

    void DELETE(TrieNode* node, const std::string& word, int depth);
    void getAll(TrieNode* node, std::string currWord);

};

