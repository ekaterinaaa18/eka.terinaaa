#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Person {
    std::string name;
    unsigned byear;

public:
    int input() {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter birth year: ";
        std::cin >> byear;
        return 0;
    }

    const std::string& getName() const {
        return name;
    }

    void show() {
        std::cout << "Name: " << name << ", Birth Year: " << byear << std::endl;
    }

    friend std::istream& operator>>(std::istream& is, Person& person) {
        is >> person.name >> person.byear;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Birth Year: " << person.byear;
        return os;
    }
};

class Student : public Person {
    std::vector<int> grades5;
    std::vector<int> grades100;

public:
    int input() {
        Person::input();

        std::cout << "Enter grades (5-point scale): ";
        grades5.resize(5);
        for (int& grade : grades5) {
            std::cin >> grade;
        }

        std::cout << "Enter grades (100-point scale): ";
        grades100.resize(5);
        for (int& grade : grades100) {
            std::cin >> grade;
        }

        return 0;
    }

    double calculateAverage() const {
        return std::accumulate(grades5.begin(), grades5.end(), 0.0) / grades5.size();
    }
    double calculateAverageNewApproach() const {
        return std::accumulate(grades100.begin(), grades100.end(), 0.0) / grades100.size();
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << static_cast<const Person&>(student) << std::endl;
        os << "Grades (5-point scale): ";
        for (const int& grade : student.grades5) {
            os << grade << " ";
        }
        os << std::endl;
        os << "Grades (100-point scale): ";
        for (const int& grade : student.grades100) {
            os << grade << " ";
        }
        os << std::endl;
        return os;
    }
};

int main() {
    int totalStudents;
    std::cin >> totalStudents;
    std::vector<Student> students(totalStudents);

    for (int i = 0; i < totalStudents; i++) {
        std::cout << "Enter information for student " << i + 1 << ":" << std::endl;
        students[i].input();
    }

    std::cout << "Scholarships based on the old approach:" << std::endl;
    for (const Student& student : students) {
        if (student.calculateAverage() >= 4.0) {
            std::cout << student.getName() << std::endl;
        }
    }

    std::cout << "\nScholarships based on the new approach:" << std::endl;
    int topStudentsCount = static_cast<int>(totalStudents * 0.4);
    std::vector<Student> topStudents(students.begin(), students.end());
    std::partial_sort(topStudents.begin(), topStudents.begin() + topStudentsCount, topStudents.end(),
        [](const Student& a, const Student& b) {
            return a.calculateAverageNewApproach() > b.calculateAverageNewApproach();
        });

    for (int i = 0; i < topStudentsCount; i++) {
        std::cout << topStudents[i].getName() << std::endl;
    }

    return 0;
}
