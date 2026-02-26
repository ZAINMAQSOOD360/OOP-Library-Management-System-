#include "Library.h"

int main() {
    Library myLibrary;
    int choice, id;

    do {
        cout << "Library Management System \n";
        cout << "1. Add Book\n  2.Show All Books\n 3.Borrow Book\n 4. Return Book\n 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                
                string t, a;
                cout << "Enter ID: ";cin >> id;
                cin.ignore();
                cout << "Enter Title: ";getline(cin, t);
                cout << "Enter Author: ";getline(cin, a);
                myLibrary.addBook(t, id, a,true);
                break;
            }
            case 2:
                myLibrary.showAllItems();
                break;
            case 3:
                cout << "Enter Book ID to borrow: ";
                cin >> id;
                myLibrary.borrowbook(id);
                break;
            case 4:
                cout << "Enter Book ID to return: ";
                
                cin >> id;
                myLibrary.returnbook(id);

                
                break;
        }
    } while (choice != 5);


    return 0;
}
