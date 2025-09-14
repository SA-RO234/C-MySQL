#ifndef PRODUCTCLASS_H
#define PRODUCTCLASS_H
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    // constructor
    Product();
    Product(int id, string name, double price, int qty);
    void Output();
    void Input();
    // setters & getters
    void setId(int id);
    int getId() const;

    void setName(string name);
    string getName() const;

    void setPrice(double price);
    double getPrice() const;

    void setQuantity(int qty);
    int getQuantity() const;

};
#endif
