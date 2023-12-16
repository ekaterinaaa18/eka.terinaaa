#include <iostream>
#include <vector>
#include <string>

class Move {
private:
    int startX;
    int startY;
    int endX;
    int endY;

public:
    Move(int startX, int startY, int endX, int endY)
        : startX(startX), startY(startY), endX(endX), endY(endY) {}

    int getStartX() const {
        return startX;
    }

    int getStartY() const {
        return startY;
    }

    int getEndX() const {
        return endX;
    }

    int getEndY() const {
        return endY;
    }
};

class Figure {
private:
    std::string figureName;
    std::string gameName;
    std::vector<Move> validMoves;

public:
    Figure(const std::string& figureName, const std::string& gameName, const std::vector<Move>& validMoves)
        : figureName(figureName), gameName(gameName), validMoves(validMoves) {}

    std::string getFigureName() const {
        return figureName;
    }

    std::string getGameName() const {
        return gameName;
    }

    std::vector<Move> getValidMoves() const {
        return validMoves;
    }

    void setValidMoves(const std::vector<Move>& newValidMoves) {
        validMoves = newValidMoves;
    }
};


class Board {
private:
    int height;
    int length;
    std::string gameName;
    std::vector<std::vector<Figure*>> boardGrid;

public:
    Board(int height, int length, const std::string& gameName) : height(height), length(length), gameName(gameName) {
        boardGrid.resize(height, std::vector<Figure*>(length, nullptr));
    }

    int getHeight() const {
        return height;
    }

    int getLength() const {
        return length;
    }

    std::string getGameName() const {
        return gameName;
    }

    void addFigure(Figure& figure, int row, int col) {
        if (row >= 0 && row < height && col >= 0 && col < length) {
            if (boardGrid[row][col] == nullptr) {
                boardGrid[row][col] = &figure;
                std::cout << "Figure " << figure.getFigureName() << " added to the board at position (" << row << ", " << col << ").\n";
            }
            else {
                std::cout << "Error: Cell at position (" << row << ", " << col << ") is occupied.\n";
            }
        }
        else {
            std::cout << "Error: Invalid position (" << row << ", " << col << ").\n";
        }
    }

    void moveFigure(const Move& move, bool ignoreNotEmptyDestination=false) {
        int startX = move.getStartX();
        int startY = move.getStartY();
        int endX = move.getEndX();
        int endY = move.getEndY();

        if (startX >= 0 && startX < height && startY >= 0 && startY < length &&
            endX >= 0 && endX < height && endY >= 0 && endY < length) {
            if (boardGrid[startX][startY] != nullptr) {
                if (boardGrid[endX][endY] == nullptr || ignoreNotEmptyDestination) {
                    boardGrid[endX][endY] = boardGrid[startX][startY];
                    boardGrid[startX][startY] = nullptr;
                    std::cout << "Figure moved from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ").\n";
                }
                else {
                    std::cout << "Error: Destination cell at (" << endX << ", " << endY << ") is occupied.\n";
                }
            }
            else {
                std::cout << "Error: No figure found at the starting position (" << startX << ", " << startY << ").\n";
            }
        }
        else {
            std::cout << "Error: Invalid positions in the move.\n";
        }
    }

    void displayBoard() {
        std::cout << "Current Board State:\n";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < length; ++j) {
                if (boardGrid[i][j] != nullptr) {
                    std::cout << boardGrid[i][j]->getFigureName()[0] << " ";
                }
                else {
                    std::cout << "- ";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
};


int main() {
    Board chessBoard(8, 8, "Chess");
    Move move(3, 4, 5, 6);
    Figure king("King", "Chess", { move });
    chessBoard.addFigure(king, 3, 4);
    chessBoard.displayBoard();


    chessBoard.moveFigure(king.getValidMoves()[0]);
    chessBoard.displayBoard();

    return 0;
}
