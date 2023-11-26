#include <iostream>
#include <vector>
#include <sstream>


std::vector<std::string> getLongestWords(const std::string& sentence) {
    std::istringstream iss(sentence);
    std::string word;
    std::vector<std::string> longestWords;
    size_t maxWordLength = 0;

    while (iss >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

        if (word.length() > maxWordLength) {
            longestWords = { word };
            maxWordLength = word.length();
        }
        else if (word.length() == maxWordLength) {
            longestWords.push_back(word);
        }
    }

    return longestWords;
}


int main() {
    std::string sentence;
    std::cout << "Enter a sentence:\n";
    std::getline(std::cin, sentence);

    std::vector<std::string> longestWords = getLongestWords(sentence);

    if (longestWords.empty()) {
        std::cout << "No words found in the sentence." << std::endl;
    }
    else {
        std::cout << "Longest word";
        if (longestWords.size() >1) {
            std::cout << "s";
        }
        std::cout << ":\n";
        for (const auto& word : longestWords) {
            std::cout << word << std::endl;
        }
    }
    return 0;
}
