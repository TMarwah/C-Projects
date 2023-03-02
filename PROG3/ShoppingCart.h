using namespace std;
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "ItemToPurchase.h"
#include <vector>
#include <string>
class ShoppingCart {

 public:
    ShoppingCart();
    ShoppingCart(string name, string date);
    string customerName() const;
    string date() const;
    void addItem(ItemToPurchase item);
    void removeItem(string name);
    void modifyItem(ItemToPurchase item);
    unsigned numItemsInCart();
    unsigned costOfCart();
    void printTotal();
    void printDescriptions();

 private:
    string _customerName;
    string _currentDate;
    vector < ItemToPurchase > _cartItems;
    unsigned _quantity;
};

#endif