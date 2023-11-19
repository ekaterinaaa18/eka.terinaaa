#include <iostream>
#include <cmath>
#include <vector>

int countNthPowerNumbers(const std::vector<int>& arr, int N) {
    int count = 0;

    for (int i = 0; i < N; ++i) {
        if (arr[i] <= 1) {
            continue;
        }
        bool isNthPower = false;
        int temp_var = 2;
        for (int base = 2; base <= sqrt(arr[i]); base++) {
            temp_var = base * base;
            while (temp_var <= arr[i]) {
                if (temp_var == arr[i]) {
                    isNthPower = true;
                    break;
                }
                temp_var *= base;
            }
            if (isNthPower) {
                break;
            }
        }
        count += (int)isNthPower;
    }

    return count;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    int result = countNthPowerNumbers(arr, N);

    std::cout << result << std::endl;

    return 0;
}

