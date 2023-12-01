#include <iostream>
#include <string>

struct Book {
    int code;
    std::string author;
    std::string title;

    void inputBookInfo() {
        std::cout << "Enter book code: ";
        std::cin >> code;
        std::cout << "Enter author: ";
        std::cin.ignore();
        std::getline(std::cin, author);

        std::cout << "Enter title: ";
        std::getline(std::cin, title);
    }

    void outputBookInfo() const {
        std::cout << "Book Code: " << code << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Title: " << title << std::endl;
    }
};

struct Reader {
    int libraryCardNumber;
    std::string name;
    std::string dateOfFilling;

    void inputReaderInfo() {
        std::cout << "Enter library card number: ";
        std::cin >> libraryCardNumber;

        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter date of filling: ";
        std::getline(std::cin, dateOfFilling);
    }

    void outputReaderInfo() const {
        std::cout << "Library Card Number: " << libraryCardNumber << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Date of Filling: " << dateOfFilling << std::endl;
    }
};

struct BookRequestForm {
    Book bookInfo;
    Reader readerInfo;

    BookRequestForm() {
        inputBookRequestForm();
    }

    void inputBookRequestForm() {
        std::cout << "Enter Book Information" << std::endl;
        bookInfo.inputBookInfo();

        std::cout << "\nEnter Reader Information" << std::endl;
        readerInfo.inputReaderInfo();
    }

    void outputBookRequestForm() const {
        std::cout << "\nBook Information" << std::endl;
        bookInfo.outputBookInfo();

        std::cout << "\nReader Information" << std::endl;
        readerInfo.outputReaderInfo();
    }
};

int main() {
    BookRequestForm requestForm;
    //requestForm.inputBookRequestForm();
    requestForm.outputBookRequestForm();

    return 0;
}
