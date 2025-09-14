#include "ProductClass.h"

Product::Product(int i, string n, double p, int q)
    : id(i), name(n), price(p), quantity(q) {}

int Product::getId() const { return id; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
   void Product::Input(){
     cout<<"Enter Product ID : ";cin>>id;
     cout<<"Enter Product Name : ";getline(cin,name);
     cout<<"Enter Price : ";cin>>price;
     cout<<"Enter Quantity : ";cin>>quantity;
  }
