#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct Student {
    std::string firstName;
    std::string lastName;
    std::string patronymic;
    char gender;
    int age;
    std::string course;
};

struct StudentDatabase {
    std::vector<Student> students;

    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void findMostPopularNames(const std::string& gender) {
        std::map<std::string, int> namesCounter;

        for (const auto& student : students) {
            if (gender.empty() || student.gender == gender[0]) {
                namesCounter[student.firstName]++;
            }
        }

        auto mostPopularName = std::max_element(
            namesCounter.begin(), namesCounter.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }
        );

        std::cout << "Most popular name";
        if (!gender.empty()) {
            std::cout << " for " << (gender[0] == 'M' ? "male" : "female");
        }
        std::cout << ": " << mostPopularName->first << std::endl;
    }

    void findStudentsWithMostPopularAge() {
        std::map<int, int> ageCounter;
        int mostPopularAge = 0;

        for (const auto& student : students) {
            ageCounter[student.age]++;
        }

        mostPopularAge = std::max_element(
            ageCounter.begin(), ageCounter.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }
        )->first;

        std::cout << "Most popular age: " << mostPopularAge << std::endl;

        std::cout << "Students with the most popular age:" << std::endl;
        for (const auto& student : students) {
            if (student.age == mostPopularAge) {
                std::cout << student.lastName << " " << student.firstName[0] << ". "<<student.patronymic[0]<<"." << std::endl;
            }
        }
    }
};


int main() {
    StudentDatabase database;

    database.addStudent({ "John", "Derkem", "K",'M', 22, "Computer Science"});
    database.addStudent({ "Jane", "Semul", "F",'F', 22, "Mathematics"});
    database.addStudent({ "Alice", "James", "L", 'F', 23, "Physics"});
    database.addStudent({ "Alice", "Jdf", "Ldf", 'F', 22, "Physics" });


    database.findMostPopularNames("M");
    database.findMostPopularNames("F");

    database.findStudentsWithMostPopularAge();
    

    return 0;
}
