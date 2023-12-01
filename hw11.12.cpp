#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

struct Toy {
    std::string name;
    double cost;
    int minAge;
    int maxAge;
};


std::vector<Toy> readToyData(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::vector<Toy> toys;

    Toy toy;
    while (inputFile >> toy.name >> toy.cost >> toy.minAge >> toy.maxAge) {
        toys.push_back(toy);
    }

    inputFile.close();
    return toys;
}

std::vector<double> findPricesForToy(const std::vector<Toy>& toys, const std::string& targetName) {
    std::vector<double> prices;

    for (const Toy& toy : toys) {
        if (toy.name == targetName) {
            prices.push_back(toy.cost);
        }
    }
    return prices;
}

int main() {
    std::vector<Toy> toys = readToyData("toys.txt");

    if (toys.empty()) {
        std::cout << "No toy data available." << std::endl;
        return 1;
    }

    std::string targetToyName;
    std::cout << "Enter the name of the target toy: ";
    std::cin >> targetToyName;
    std::vector<double> prices = findPricesForToy(toys, targetToyName);
    if (prices.empty()) {
        std::cout << "No prices found for toy: " << targetToyName << std::endl;
    }
    else {
        std::cout << "Prices for toy " << targetToyName << ":\n";
        std::cout << std::fixed << std::showpoint;
        for (double price : prices) {
            std::cout << std::setprecision(2) << price << std::endl;
        }
    }

    return 0;
}
