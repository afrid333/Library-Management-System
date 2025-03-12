#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
    Book(int bookId, string bookTitle, string bookAuthor)
        : id(bookId), title(bookTitle), author(bookAuthor), isIssued(false) {}

    void displayDetails() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author
             << ", Issued: " << (isIssued ? "Yes" : "No") << endl;
    }

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIssuedStatus() const { return isIssued; }

    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book &book) {
        books.push_back(book);
    }

    void displayBooks() const {
        for (const auto &book : books) {
            book.displayDetails();
        }
    }

    void issueBook(int bookId) {
        for (auto &book : books) {
            if (book.getId() == bookId && !book.getIssuedStatus()) {
                book.issueBook();
                cout << "Book issued successfully." << endl;
                return;
            }
        }
        cout << "Book not found or already issued." << endl;
    }

    void returnBook(int bookId) {
        for (auto &book : books) {
            if (book.getId() == bookId && book.getIssuedStatus()) {
                book.returnBook();
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found or not issued." << endl;
    }
};

int main() {
    Library library;

    library.addBook(Book(1, "The Alchemist", "Paulo Coelho"));
    library.addBook(Book(2, "1984", "George Orwell"));
    library.addBook(Book(3, "Clean Code", "Robert C. Martin"));

    int choice, bookId;
    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Display Books" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.displayBooks();
            break;
        case 2:
            cout << "Enter book ID to issue: ";
            cin >> bookId;
            library.issueBook(bookId);
            break;
        case 3:
            cout << "Enter book ID to return: ";
            cin >> bookId;
            library.returnBook(bookId);
            break;
        case 4:
            cout << "Exiting the system." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
