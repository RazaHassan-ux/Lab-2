#include <iostream>
#include <cstring>
using namespace std;

class LibraryItem {
protected:
    char title[100];
public:
    LibraryItem(const char* t) {
        strncpy(title, t, 100);
    }
    virtual void display() const = 0;
    const char* getTitle() const { return title; }
};

class Book : public LibraryItem {
    char author[100];
    int pages;
public:
    Book(const char* t, const char* a, int p) : LibraryItem(t), pages(p) {
        strncpy(author, a, 100);
    }
    void display() const override {
        cout << "Book: " << title << " by " << author << ", Pages: " << pages << endl;
    }
    int getPages() const { return pages; }
};

class Newspaper : public LibraryItem {
    char date[20];
    char edition[50];
public:
    Newspaper(const char* t, const char* d, const char* e) : LibraryItem(t) {
        strncpy(date, d, 20);
        strncpy(edition, e, 50);
    }
    void display() const override {
        cout << "Newspaper: " << title << ", Date: " << date << ", Edition: " << edition << endl;
    }
    const char* getEdition() const { return edition; }
};

class Library {
    Book* books[100];
    Newspaper* newspapers[100];
    int bookCount, newspaperCount;
public:
    Library() : bookCount(0), newspaperCount(0) {}

    void addBook(Book& book) {
        if (bookCount < 100)
            books[bookCount++] = &book;
    }
    void addNewspaper(Newspaper& newspaper) {
        if (newspaperCount < 100)
            newspapers[newspaperCount++] = &newspaper;
    }
    void displayCollection() const {
        for (int i = 0; i < bookCount; ++i) books[i]->display();
        for (int i = 0; i < newspaperCount; ++i) newspapers[i]->display();
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; ++i) {
            for (int j = 0; j < bookCount - i - 1; ++j) {
                if (books[j]->getPages() > books[j + 1]->getPages()) {
                    Book* temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; ++i) {
            for (int j = 0; j < newspaperCount - i - 1; ++j) {
                if (strcmp(newspapers[j]->getEdition(), newspapers[j + 1]->getEdition()) > 0) {
                    Newspaper* temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(const char* title) {
        for (int i = 0; i < bookCount; ++i) {
            if (strcmp(books[i]->getTitle(), title) == 0) {
                return books[i];
            }
        }
        return nullptr;
    }
    Newspaper* searchNewspaperByName(const char* name) {
        for (int i = 0; i < newspaperCount; ++i) {
            if (strcmp(newspapers[i]->getTitle(), name) == 0) {
                return newspapers[i];
            }
        }
        return nullptr;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);
    cout << "Before Sorting:\n";
    library.displayCollection();
    library.sortBooksByPages();
    library.sortNewspapersByEdition();
    cout << "\nAfter Sorting:\n";
    library.displayCollection();
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }
    return 0;
}
