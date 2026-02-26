#pragma once
#include "item.h"

class Book : public Item {
private:
    string author;
public:
    Book();
    Book(string t, int i,string a,bool stat);
    void displayDetails() override;
    string getauthor()override;
};

Book::Book() : Item("", 0), author("") {
    available=true;
}

Book::Book(string t, int i,string a,bool stat) : Item(t, i,stat), author(a) {
    
}

void Book::displayDetails() {
    cout << "ID: " << id << " ,Book: " << title << " ,Author: "
    << author << " ,Status: "<<(available? "available" : "not available ")<<endl;
}
string Book::getauthor(){return author;}
