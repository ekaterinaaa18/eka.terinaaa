#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>


std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream iss(s);
    std::string token;

    while (std::getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}


int main() {
    std::string filename = "test.txt";
    std::ifstream inputFile(filename);
    std::vector<double> numbers;
    std::vector<int> precision;
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string fileContent = buffer.str();
    inputFile.close();
    std::vector<std::string> parts = split(fileContent, ';');

    int maxPrecision = 0;
    for (const auto& part : parts) {
        std::vector<std::string> numberParts = split(part, '.');
        if (numberParts.size() > 1) {
            precision.push_back(static_cast<int>(numberParts[1].length()));
            maxPrecision = std::max(maxPrecision, static_cast<int>(numberParts[1].length()));
        }
        else {
            precision.push_back(0);
        }
        numbers.push_back(std::stod(part));
    }
    int index = 0;
    std::ofstream outputFile(filename);
    for (const double& num : numbers) {
        std::ostringstream oss1;
        oss1 << std::fixed;
        oss1 << std::setprecision(num < 0 ? maxPrecision : precision[index]) << static_cast<double>(std::fabs(num)) << (num < 0 ? '\n' : ';');
        outputFile << oss1.str();
        index++;
    }
    outputFile.close();
    return 0;
}
