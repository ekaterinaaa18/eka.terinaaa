#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>


struct Point {
    int x;
    int y;
    double mass;
};

bool compareForces(const Point& p1, const Point& p2) {
    return std::fabs(p1.mass * static_cast<double>(p1.x + p1.y)) > std::fabs(p2.mass * static_cast<double>(p2.x + p2.y));
}


int main() {
    std::ifstream inputFile("points.txt");

    std::vector<Point> points;
    std::string line;

    while (std::getline(inputFile, line, ']')) {
        std::replace(line.begin(), line.end(), '[', ' ');
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream ss(line);
        Point point;
        if (ss >> point.x >> point.y >> point.mass) {
            points.push_back(point);
        }
    }
    inputFile.close();

    if (points.size() < 2) {
        std::cerr << "Insufficient points in the file." << std::endl;
        return 1;
    }
    std::sort(points.begin(), points.end(), compareForces);
    std::cout << "Two points with the highest force:\n";
    for (int i = 0; i < 2; i++) {
        std::cout << "[" << points[i].x << ", " << points[i].y << ", " << points[i].mass << "]\n";
    }

    return 0;
}
