#pragma once
#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string title;
    int id;
    bool available;
public:
    Item(string t = "", int i = 0,bool avail=true) : title(t), id(i),available(avail) {}
    virtual void displayDetails()=0; // Pure virtual function
    int getId() { return id; }
    string gettitle(){return title;}
    void setstatus(bool s){available=s;}
    bool getstatus(){return available;}
    virtual ~Item() {}
    virtual string getauthor()=0;   //pure virtual funnction
};
