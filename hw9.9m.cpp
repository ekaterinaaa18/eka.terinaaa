#include <iostream>
#include <vector>


void deleteColumns(std::vector<std::vector<int>>& matrix, int k1, int k2) {
    k1 -= 1;
    k2 -= 1;
    if (matrix.empty() || k1 < 0 || k2 >= matrix[0].size() || k1 > k2) {
        std::cout << "Invalid input for deletion." << std::endl;
        return;
    }

    for (auto& row : matrix) {
        row.erase(row.begin() + k1, row.begin() + k2 + 1);
    }
}


void printMatrix(std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m, k1, k2;
    std::cout << "Enter the dimensions: ";
    std::cin >> n >> m;
    std::vector<std::vector<int>> A(n, std::vector<int>(m));
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
        }
    }
    printMatrix(A);
    std::cout << "k1: ";
    std::cin >> k1;
    std::cout << "k2: ";
    std::cin >> k2;
    deleteColumns(A, k1, k2);
    printMatrix(A);
    return 0;
}
