#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_set>

class CustomString {
private:
    std::vector<char> validChars;
    std::vector<char> enteredChars;

public:
    CustomString(const char validChars[], size_t validCharsLength)
        : validChars(validChars, validChars + validCharsLength) {}

    void readFromConsole();
    void writeToConsole() const;
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;

    void addValidCharacters(const char chars[], size_t charsLength);
    void removeValidCharacters(const char chars[], size_t charsLength);

    size_t length() const;

    void concatenate(const CustomString& other);

    size_t hash() const;

    bool isValidCharacter(char c) const {
        return std::find(validChars.begin(), validChars.end(), c) != validChars.end();
    }
};


void CustomString::readFromConsole() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    enteredChars.clear();
    for (char c : input) {
        if (isValidCharacter(c)) {
            enteredChars.push_back(c);
        }
        else {
            std::cerr << "Error: Invalid character entered: " << c << std::endl;
        }
    }
}

void CustomString::writeToConsole() const {
    std::cout << "Entered String: ";
    for (char c : enteredChars) {
        std::cout << c;
    }
    std::cout << std::endl;
}

void CustomString::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
    std::string input;
    std::getline(file, input);

    enteredChars.clear();
    for (char c : input) {
        if (isValidCharacter(c)) {
            enteredChars.push_back(c);
        }
        else {
            std::cerr << "Error: Invalid character read from file: " << c << std::endl;
        }
    }

    file.close();
}

void CustomString::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing" << std::endl;
        return;
    }

    for (char c : enteredChars) {
        file << c;
    }

    file.close();
}

void CustomString::addValidCharacters(const char chars[], size_t charsLength) {
    validChars.insert(validChars.end(), chars, chars + charsLength);
    std::sort(validChars.begin(), validChars.end());
    validChars.erase(std::unique(validChars.begin(), validChars.end()), validChars.end());
}

void CustomString::removeValidCharacters(const char chars[], size_t charsLength) {
    for (size_t i = 0; i < charsLength; ++i) {
        char c = chars[i];
        validChars.erase(std::remove(validChars.begin(), validChars.end(), c), validChars.end());
    }
}

size_t CustomString::length() const {
    return enteredChars.size();
}

void CustomString::concatenate(const CustomString& other) {
    validChars.insert(validChars.end(), other.validChars.begin(), other.validChars.end());
    std::vector<char> result;
    std::set_intersection(
        enteredChars.begin(), enteredChars.end(),
        other.enteredChars.begin(), other.enteredChars.end(),
        std::back_inserter(result)
    );
    enteredChars = result;
    std::unordered_set<char> validCharsSet(validChars.begin(), validChars.end());
    enteredChars.erase(std::remove_if(enteredChars.begin(), enteredChars.end(),
        [&validCharsSet](char c) { return validCharsSet.find(c) == validCharsSet.end(); }),
        enteredChars.end());
}

size_t CustomString::hash() const {
    std::hash<char> charHash;
    size_t result = 0;
    for (char c : enteredChars) {
        result ^= charHash(c) + 0x9e3779b9 + (result << 6) + (result >> 2);
    }
    return result;
}

int main() {
    const char validChars[] = { 'a', 'b', 'c', 'd', 'e', '1', '2', '3', '4', '5' };
    CustomString myString(validChars, sizeof(validChars) / sizeof(validChars[0]));

    myString.readFromConsole();
    myString.writeToConsole();

    myString.readFromFile("input.txt");
    myString.writeToFile("output.txt");

    const char additionalChars[] = { 'f', 'g', 'h' };
    myString.addValidCharacters(additionalChars, sizeof(additionalChars) / sizeof(additionalChars[0]));

    const char charsToRemove[] = { '1', '2', '3' };
    myString.removeValidCharacters(charsToRemove, sizeof(charsToRemove) / sizeof(charsToRemove[0]));

    std::cout << "String Length: " << myString.length() << std::endl;

    CustomString otherString(validChars, sizeof(validChars) / sizeof(validChars[0]));
    otherString.readFromFile("otherInput.txt");
    otherString.concatenate(myString);

    std::cout << "Concatenated String: ";
    otherString.writeToConsole();

    std::cout << "Hash: " << myString.hash() << std::endl;

    return 0;
}
