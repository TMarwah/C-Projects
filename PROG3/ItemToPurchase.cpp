#include <cstdlib>
#include <cmath>
#include "ShoppingCart.h"

ItemToPurchase::ItemToPurchase(){
    _name = "none";
    _description = "none";
    _price = 0;
    _quantity = 0;
}


ItemToPurchase::ItemToPurchase(string name, string desc, unsigned price, unsigned quantity){
    _name = name;
    _description = desc;
    _price = price;
    _quantity = quantity;
}

void ItemToPurchase::setName(string name){
    _name = name;
}
string ItemToPurchase::name() const{

    return _name;
}
void ItemToPurchase::setPrice(unsigned price){
    _price = price;
}
unsigned ItemToPurchase::price() const{
    return _price;
}
void ItemToPurchase::setQuantity(unsigned quantity){
    _quantity = quantity;
}
unsigned ItemToPurchase::quantity() const{
    return _quantity;
}
void ItemToPurchase::setDescription(string desc){
    _description = desc;
}
string ItemToPurchase::description() const{
    return _description;
}
void ItemToPurchase::printItemCost() const{
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << _quantity * _price << endl;
}
void ItemToPurchase::printItemDescription() const{
    cout << _name << ": " << _description << endl;
}