#include <iostream>
#include <string>
#include <cstring> // For strcasecmp
using namespace std;

const int MAX_BOOKS = 100;

class Book {
    int bid;
    string bname;
    string aname;
    string category;
    float price;
    int rating;

public:
    Book() {
        bid = 0;           
        bname = "";     
        aname = "";       
        category = "";     
        price = 0.0;     
        rating = 0;      
    }

    Book(int id, string name, string author, string cat, float p, int r) {
        bid = id;         
        bname = name;      
        aname = author;
        category = cat;
        price = p;
        rating = r;
    }

    // Getters
    int getBid() { return bid; }
    string getBname() { return bname; }
    string getAname() { return aname; }
    string getCategory() { return category; }
    float getPrice() { return price; }
    int getRating() { return rating; }

    // Setters
    void setBid(int id) { bid = id; }
    void setBname(string name) { bname = name; }
    void setAname(string author) { aname = author; }
    void setCategory(string cat) { category = cat; }
    void setPrice(float p) { price = p; }
    void setRating(int r) { rating = r; }
};

class BookManagementSystem {
    Book books[MAX_BOOKS];
    int bookCount;

public:
    BookManagementSystem() {
        bookCount = 0;  
        storeInitialBooks(); 
    }

    void storeInitialBooks() {
        books[0] = Book(1, "Can't Hurt Me", "David Goggins", "motivational", 5000, 1);
        books[1] = Book(2, "One Piece", "Eichiro Oda", "Manga", 2000, 5);
        books[2] = Book(3, "42 Rules of Life", "Jordan Peterson", "Motivational", 11240, 1);
        books[3] = Book(4, "Hurt Me", "David Goggins", "motivational", 5000, 1);
        bookCount = 4;
    }

    void addBook() {
        if (bookCount >= MAX_BOOKS) {
            cout << "Cannot add more books, storage full!" << endl;
            return;
        }

        int id, rating;
        string name, author, cat;
        float price;

        cout << "Enter book id: ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter book name: ";
        getline(cin, name);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter book price: ";
        cin >> price;
        cin.ignore(); 
        cout << "Enter category of book: ";
        getline(cin, cat);
        cout << "Enter book rating (from 1 to 5): ";
        cin >> rating;

        books[bookCount++] = Book(id, name, author, cat, price, rating);
        cout << "Book added successfully.\n";
    }

    void removeBook() {
        int id;
        cout << "Enter Book ID to remove: ";
        cin >> id;

        for (int i = 0; i < bookCount; i++) {
            if (books[i].getBid() == id) {
                for (int j = i; j < bookCount - 1; j++) {
                    books[j] = books[j + 1]; // Shift books 
                }
                bookCount--;
                cout << "Book removed successfully.\n";
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void searchBook() {
        int choice;
        cout << "1. To search book by ID\n2. To search book by name\n";
        cin >> choice;

        if (choice == 1) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;
            for (int i = 0; i < bookCount; i++) {
                if (books[i].getBid() == id) {
                    displayBook(books[i]);
                    return;
                }
            }
            cout << "Book Not Found!\n";
        } else if (choice == 2) {
            string name;
            cout << "Enter name of book: ";
            cin.ignore();
            getline(cin, name);
            for (int i = 0; i < bookCount; i++) {
                if (strcasecmp(books[i].getBname().c_str(), name.c_str()) == 0) {
                    displayBook(books[i]);
                    return;
                }
            }
            cout << "Book Not Found!\n";
        } else {
            cout << "Invalid choice\n";
        }
    }

    void showByAuthor() {
        string aname;
        cout << "Enter author name of book: ";
        cin.ignore();
        getline(cin, aname);
        bool found = false;

        for (int i = 0; i < bookCount; i++) {
            if (strcasecmp(books[i].getAname().c_str(), aname.c_str()) == 0) {
                displayBook(books[i]);
                found = true;
            }
        }
        if (!found) {
            cout << "No books found for entered author name: " << aname << endl;
        }
    }

    void showByCategory() {
        string category;
        cout << "Enter category of book: ";
        cin.ignore();
        getline(cin, category);
        bool found = false;

        for (int i = 0; i < bookCount; i++) {
            if (strcasecmp(books[i].getCategory().c_str(), category.c_str()) == 0) {
                displayBook(books[i]);
                found = true;
            }
        }
        if (!found) {
            cout << "No books found for entered category: " << category << endl;
        }
    }

    void displayBook(Book& b) {
        cout << "\n==============================" << endl;
        cout << "Book ID: " << b.getBid() << endl;
        cout << "Book Name: " << b.getBname() << endl;
        cout << "Author Name: " << b.getAname() << endl;
        cout << "Category: " << b.getCategory() << endl;
        cout << "Price: ?" << b.getPrice() << endl;  // Added currency symbol
        cout << "Rating: " << b.getRating() << " / 5" << endl;  // Added rating format
        cout << "==============================" << endl;
    }

    void displayAllBooks() {
        if (bookCount == 0) {
            cout << "\nNo books available." << endl;
            return;
        }
        cout << "\n==============================" << endl;
        cout << "       List of Books          " << endl;
        cout << "==============================" << endl;
        for (int i = 0; i < bookCount; i++) {
            displayBook(books[i]);
        }
        
        cout << "==============================";
    }

    void sortByHighestPrice() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j].getPrice() < books[j + 1].getPrice()) {
                    swap(books[j], books[j + 1]);
                }
            }
        }
    }

    void sortByHighestRating() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j].getRating() < books[j + 1].getRating()) {
                    swap(books[j], books[j + 1]);
                }
            }
        }
    }

    void displaySortedBooks() {
        int choice;
        cout << "\nEnter 1 to sort by price (highest to lowest)\nEnter 2 to sort by rating (highest to lowest): ";
        cin >> choice;

        if (choice == 1) {
            sortByHighestPrice();
            cout << "\nBooks sorted by price:\n";
            displayAllBooks();
        } else if (choice == 2) {
            sortByHighestRating();
            cout << "\nBooks sorted by rating:\n";
            displayAllBooks();
        } else {
            cout << "Invalid choice\n";
        }
    }

    void displayTopThree() {
        int choice;
        cout << "\nEnter 1 to display top 3 by price (highest to lowest)\nEnter 2 to display top 3 by rating (highest to lowest): ";
        cin >> choice;

        if (choice == 1) {
            sortByHighestPrice();
            cout << "\nTop 3 books by price:\n";
            for (int i = 0; i < 3 && i < bookCount; i++) {
                displayBook(books[i]);
            }
        } else if (choice == 2) {
            sortByHighestRating();
            cout << "\nTop 3 books by rating:\n";
            for (int i = 0; i < 3 && i < bookCount; i++) {
                displayBook(books[i]);
            }
        } else {
            cout << "Invalid choice\n";
        }
    }

    void run() {
        int choice;
        do {
            cout <<"\n1. Add Book\n";
            cout << "2. Remove Book\n";
            cout << "3. Search Book\n";
            cout << "4. Show Books by Author\n";
            cout << "5. Show Books by Category\n";
            cout << "6. Display All Books\n";
            cout << "7. Display Sorted Books\n";
            cout << "8. Display Top 3 Books\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addBook(); break;
                case 2: removeBook(); break;
                case 3: searchBook(); break;
                case 4: showByAuthor(); break;
                case 5: showByCategory(); break;
                case 6: displayAllBooks(); break;
                case 7: displaySortedBooks(); break;
                case 8: displayTopThree(); break;
                case 9: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice! Please try again.\n"; break;
            }
        } while (choice != 9);
    }
};

int main() {
    BookManagementSystem bms;
    bms.run();
    return 0;
}
