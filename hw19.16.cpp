#include <iostream>
#include <vector>
#include <deque>

void fillDeque(std::vector<int>& numbers, std::deque<int>& dequeB) {
    size_t middleIndex = numbers.size() / 2;
    size_t doPlusOne = numbers.size() % 2;
    dequeB.insert(dequeB.end(), numbers.begin(), numbers.begin() + middleIndex);
    dequeB.insert(dequeB.end(), numbers.rbegin(), numbers.rbegin() + middleIndex+doPlusOne);
}

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8};
    std::deque<int> dequeB;

    fillDeque(numbers, dequeB);

    // Print the deque
    std::cout << "Deque B: ";
    for (const auto& num : dequeB) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}