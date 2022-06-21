#include <iostream>
#include <cstring>
using namespace std;

class Book{
    private:
        char * title;
        char * isbn;
        int price;
    public:
        Book(char * title, char * isbn, int price) {
            this->price = price;
            this->title = new char[strlen(title)+1];
            this->isbn = new char[strlen(isbn)+1];
            strcpy(this->title, title);
            strcpy(this->isbn, isbn);
        }
        void ShowBookInfo() {
            cout << "title: " << title << endl;
            cout << "ISBN: " << isbn << endl;
            cout << "Price: " << price << endl;
        }
        ~Book() {
            delete []title;
            delete []isbn;
        }
        Book &operator=(const Book &ref) {
            cout << "Book &opeartor=()" << endl;
            delete []title;
            delete []isbn;
            title = new char[strlen(ref.title)+1];
            isbn = new char[strlen(ref.isbn)+1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
        }
};

class EBook : public Book {
    private:
        char * DRMKey;
    public:
        EBook(char * title, char * isbn, int price, char * DRMKey) : Book(title, isbn, price) {
            this->DRMKey = new char[strlen(DRMKey)+1];
            strcpy(this->DRMKey, DRMKey);
        }
        void ShowEBookInfo() {
            ShowBookInfo();
            cout << "Pkey: " << DRMKey << endl;
        }
        ~EBook() {
            delete []DRMKey;
        }
        EBook &operator=(const EBook &ref) {
            cout << "Ebook &operator=()" << endl;
            Book::operator=(ref);
            delete []DRMKey;
            DRMKey = new char[strlen(ref.DRMKey)+1];
            strcpy(DRMKey, ref.DRMKey);
        }
};

int main(void) {
    EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx920i8kiw");
    ebook.ShowEBookInfo();
    EBook cpyebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx920i8kiw");

    cpyebook = ebook;
    cpyebook.ShowEBookInfo();

    return 0;
}