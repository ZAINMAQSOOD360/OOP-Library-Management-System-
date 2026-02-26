#pragma once
#include "book.h"
#include <fstream>


class Library {
private:
    static const int MAX_CAPACITY = 100;
    Item* items[MAX_CAPACITY];
    int itemCount;

public:
    Library();
    ~Library();
    void addBook(string t, int i,string a,bool);
    void showAllItems();
    void findItem(int id);
    void borrowbook(int id);
    void returnbook(int id);
    
    void savefile();
    void loadfile();
};

Library::Library() : itemCount(0) {
    for (int i = 0; i < MAX_CAPACITY; i++) items[i] = nullptr;
    loadfile();
}

Library::~Library() {
    savefile();
    for (int i = 0; i < itemCount; i++) {
        delete items[i];
    }
}

void Library::addBook(string t, int i,string a,bool chek) {
    if (itemCount < MAX_CAPACITY) {
        items[itemCount] = new Book(t, i, a,chek);
        itemCount++;
    } else {
        cout << "Library is full!" << endl;
    }
}

void Library::showAllItems() {
    cout <<"showing Library details: "<<endl;
    for (int i = 0; i < itemCount; i++) {
        items[i]->displayDetails();
    }
}

void Library::findItem(int id) {
    bool isfound=false;
    for (int i = 0; i < itemCount; i++) {
       
        if (items[i]->getId() == id) {
            cout << "Item Found: ";
            items[i]->displayDetails();
            isfound=true;
        }
    }
    if(!isfound) {cout << "Item with ID " << id << " not found." <<endl;}
}
void Library::loadfile() {
    ifstream inFile("library_data.txt");
    if (!inFile){cout<<"error occured whie loading file\n";}

    int id,status;//0 and 1
    string title, author;
    

    while (itemCount < MAX_CAPACITY && inFile >> id) {
        inFile.ignore();
        getline(inFile, title);
        getline(inFile, author);
        inFile>>status;
        inFile.ignore();
        
        
        
        Book *newbook= new Book(title, id, author,status);
        items[itemCount]=newbook;
        itemCount++;
    }
    inFile.close();
}
void Library::savefile(){
    
    ofstream outFile("library_data.txt");
    if (!outFile){cout<<"error opening file to load\n";}

        for (int i = 0; i < itemCount; i++) {
           
            outFile << items[i]->getId() <<"\n";
            outFile<<items[i]->gettitle() << "\n";
            outFile<<items[i]->getauthor()<<"\n";
            outFile<<items[i]->getstatus() << "\n";
            
        }
        outFile.close();
    }
void Library::borrowbook(int id){
    bool find=false;
    for (int i = 0; i < itemCount; i++) {
            if (items[i]->getId() == id) {
                if (items[i]->getstatus()) {
                    items[i]->setstatus(false); // Mark as borrowed
                    cout << "Successfully borrowed: " << items[i]->gettitle() <<endl;
                
                } else {
                    cout << "Book is not available " <<endl;
                
                }
                find=true;
        
            }
        }
    if(find==0){
        cout << "Book ID not found." <<endl;}

    
}
void Library::returnbook(int id) {
    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (items[i]->getId() == id) {
            if (!items[i]->getstatus()) {
                items[i]->setstatus(true);
                cout << "Successfully returned: " << items[i]->gettitle() << endl;
            } else {
                cout << "Book was not borrowed." << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) cout << "Book ID " << id << " not found." << endl;
}
    
