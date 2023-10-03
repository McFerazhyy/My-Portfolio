#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;
};

struct User {
    int id;
    string name;
};
class Library {
public:
    Library() {
        nextBookId = 1;
        nextUserId = 1;
    }

    void addBook(string title, string author) {
        Book book;
        book.id = nextBookId++;
        book.title = title;
        book.author = author;
        book.isAvailable = true;
        books.push_back(book);
    }

    void addUser(string name) {
        User user;
        user.id = nextUserId++;
        user.name = name;
        users.push_back(user);
    }

    void searchBook(string query) {
        cout << "Search results for '" << query << "':" << endl;
        for (const Book& book : books) {
            if (book.title.find(query) != string::npos || book.author.find(query) != string::npos) {
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
            }
        }
    }

    // Implement functions for checking out and returning books

private:
    vector<Book> books;
    vector<User> users;
    int nextBookId;
    int nextUserId;
};
int main() {
    Library library;

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add User" << endl;
        cout << "3. Search Books" << endl;
        cout << "4. Check Out Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            }
            case 2: {
                string name;
                cout << "Enter user name: ";
                cin.ignore();
                getline(cin, name);
                library.addUser(name);
                break;
            }
            case 3: {
                string query;
                cout << "Enter search query: ";
                cin.ignore();
                getline(cin, query);
                library.searchBook(query);
                break;
            }
            // Implement other menu options (check out, return, etc.)
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
