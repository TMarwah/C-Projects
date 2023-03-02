#include <iostream>
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
using namespace std;

class ItemToPurchase {

 public:
    ItemToPurchase();
    ItemToPurchase(string name, string desc, unsigned price, unsigned quantity);
    void setName(string name);
    string name() const;
    void setPrice(unsigned price);
    unsigned price() const;
    void setQuantity(unsigned quantity);
    unsigned quantity() const;
    void setDescription(string desc);
    string description() const;
    void printItemCost() const;
    void printItemDescription() const;

 private:
    string _name;
    string _description;
    unsigned _price;
    unsigned _quantity;

    
    
};

#endif