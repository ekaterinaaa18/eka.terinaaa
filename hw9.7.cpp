#include <iostream>
#include <cmath>

int main() {
    unsigned long n;
    std::cout << "n: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Please enter a natural number greater than 0." << std::endl;
        return 1;
    }

    unsigned long* arr = new unsigned long[n];
    for (unsigned long i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int countPowerOfTwo = 0;
    int countPowerOfThree = 0;
    for (unsigned long i = 0; i < n; i++) {
        if (arr[i] > 0 && (arr[i] & (arr[i] - 1)) == 0) {
            countPowerOfTwo++;
        }
        if (arr[i] > 0 && pow(3, static_cast<int>(log(arr[i]) / log(3))) == arr[i]) {
            countPowerOfThree++;
        }
    }

    std::cout << "Number of powers of two in the array: " << countPowerOfTwo << std::endl;
    std::cout << "Number of powers of three in the array: " << countPowerOfThree << std::endl;
    delete[] arr;

    return 0;
}
