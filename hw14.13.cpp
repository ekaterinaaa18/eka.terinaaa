#include <iostream>
#include <fstream>
#include <cctype>

void encryptFile(const std::string& inputFileName, const std::string& outputFileName, int shift) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift) % 26 + base);
        }
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Encryption completed successfully." << std::endl;
}

int main() {
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";
    int shift;
    std::cin>>shift;

    encryptFile(inputFileName, outputFileName, shift);

    return 0;
}
