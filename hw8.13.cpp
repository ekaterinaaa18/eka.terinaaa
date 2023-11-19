#include <iostream>
#include <vector>


std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int k = B[0].size();

    std::vector<std::vector<int>> C(n, std::vector<int>(k, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int l = 0; l < m; ++l) {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }

    return C;
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
    int n, m, k;
    std::cout << "Enter the dimensions: ";
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> A(n, std::vector<int>(m));
    std::cout << "Enter the elements of the first matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
        }
    }
    std::vector<std::vector<int>> B(m, std::vector<int>(k));
    std::cout << "Enter the elements of the second matrix:" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            std::cin >> B[i][j];
        }
    }
    std::vector<std::vector<int>> result = multiplyMatrices(A, B);
    printMatrix(result);
    return 0;
}
