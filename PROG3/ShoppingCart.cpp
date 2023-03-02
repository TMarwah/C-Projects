#include "ShoppingCart.h"
#include <vector>
#include <iostream>
using namespace std;


ShoppingCart::ShoppingCart() {
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    _customerName = name;
    _currentDate = date;
}

string ShoppingCart::customerName() const {
    return _customerName;
}

string ShoppingCart::date() const {
    return _currentDate;
}

void ShoppingCart::addItem(ItemToPurchase item) {
    _cartItems.push_back(item);
}

void ShoppingCart::removeItem(string name){
    bool found = false;
    int index = 0;
    ItemToPurchase currItem;

    for (unsigned int i = 0 ; i < _cartItems.size() ; ++i){
        
        currItem =_cartItems.at(i);

        if (currItem.name() == name){
            found = true;
            index = i;
        }
    }
    if (found){
        _cartItems.erase(_cartItems.begin() + index);
    }
    else
    {
        std::cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::modifyItem(ItemToPurchase item) {
    bool found = false;
    int index = 0;
    ItemToPurchase currItem;

    for (unsigned int i = 0 ; i < _cartItems.size() ; ++i){
        
        currItem = _cartItems.at(i);

        if (currItem.name() == item.name()){
            found = true;
            index = i;
        }
    }
    if (found){
        if(!(item.description() == "none")){
            _cartItems[index].setDescription(item.description());
        }
        if(!(item.price() == 0)){
            _cartItems[index].setPrice(item.price());
        }
        if(!(item.quantity() == 0)){
            _cartItems[index].setQuantity(item.quantity());
        }
    }
    else
    {
        std::cout << "Item not found in cart. Nothing modified." << endl;
    }
}
unsigned ShoppingCart::numItemsInCart(){
    ItemToPurchase currItem;
    unsigned int totalQuantity = 0;

    for (unsigned int i = 0 ; i < _cartItems.size() ; ++i){
       currItem = _cartItems.at(i);

        totalQuantity += currItem.quantity();
    }
    return totalQuantity;
}

unsigned ShoppingCart::costOfCart(){
    ItemToPurchase currItem;
    unsigned int totalCost = 0;
    for (unsigned int i = 0 ; i < _cartItems.size() ; ++i){
        
       currItem = _cartItems.at(i);

        totalCost += currItem.price() * currItem.quantity();
    }
    return totalCost;
}

void ShoppingCart::printTotal(){
    ItemToPurchase currItem;
    if (_cartItems.size() == 0){
        cout << "SHOPPING CART IS EMPTY" << endl;
        cout << endl;
        cout << "Total: $" << costOfCart() <<endl;
    }
    else
    {
        for (unsigned int i = 0 ; i < _cartItems.size() ; ++i){
            currItem = _cartItems.at(i);
            currItem.printItemCost();
        }
        cout << endl;
    cout << "Total: $" << costOfCart() << endl;

    }   

}

void ShoppingCart::printDescriptions(){
    ItemToPurchase currItem;
    
    for (unsigned int i = 0 ; i < _cartItems.size() ; ++i){
        
        currItem = _cartItems.at(i);

        currItem.printItemDescription();
    }
    
}