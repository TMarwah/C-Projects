#include <iostream>
using namespace std;
#include "ShoppingCart.h"
void menuDisplay(){
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
}
void printMenu(ShoppingCart &userCart){
    char userOption;
    bool cont = true;
    menuDisplay();
    while (cont){
        cout << "Choose an option: " << endl;
        cin >> userOption;

        if (userOption == 'q'){
            cont = false;
        }
        if (userOption == 'a'){
            
            string itemToAdd;
            string descriptionToAdd;
            unsigned int priceToAdd;
            unsigned int quantityToAdd;
            cout << endl;

            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: ";
            cin.ignore();
            getline(cin,itemToAdd);
            cout << endl;
            cout << "Enter the item description: ";
            getline(cin,descriptionToAdd);
            cout << endl;
            cout << "Enter the item price: ";
            cin >> priceToAdd;
            cout << endl;
            cout << "Enter the item quantity: ";
            cin >> quantityToAdd;
            cout << endl;
            cout << endl;

            ItemToPurchase newItemObj(itemToAdd,descriptionToAdd,priceToAdd,quantityToAdd);
            newItemObj.setName(itemToAdd);
            newItemObj.setDescription(descriptionToAdd);
            newItemObj.setPrice(priceToAdd);
            newItemObj.setQuantity(quantityToAdd);
            userCart.addItem(newItemObj);
            menuDisplay();
        }
        if (userOption == 'd'){
            string removalName;
            cout << endl;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: " << endl;
            cin.ignore();
            getline(cin, removalName);
            userCart.removeItem(removalName);
            cout << endl;
            menuDisplay();
        }
        if (userOption == 'c'){
            string itemToChange;
            unsigned int newQuantity;
            cout << endl;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin, itemToChange);
            cout << "Enter the new quantity: " << endl;
            cin >> newQuantity;
            ItemToPurchase changedQuantity(itemToChange, "none", 0, newQuantity);
            userCart.modifyItem(changedQuantity);
            cout << endl;
            menuDisplay();
        }
        if (userOption == 'i'){
            cout << endl;
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cout << userCart.customerName() << "'s Shopping Cart - " << userCart.date() << endl;
            cout << endl;
            cout << "Item Descriptions" << endl;
            userCart.printDescriptions();
            cout << endl;
            menuDisplay();
            
        }
        if (userOption == 'o'){
            cout << endl;
            cout << "OUTPUT SHOPPING CART" << endl;
            cout << userCart.customerName() << "'s Shopping Cart - " << userCart.date() << endl;
            cout << "Number of Items: " << userCart.numItemsInCart() << endl;
            cout << endl;
            userCart.printTotal();
            cout << endl;
            menuDisplay();
        }
    }
}

int main() {
  string customerName;
  string currentDate;
  
  //take user inputs
  cout << "Enter customer's name: " << endl;
  getline(cin,customerName);
  cout << "Enter today's date: " << endl;
  getline(cin,currentDate);
  cout << endl;
  
  ShoppingCart userCart(customerName, currentDate);
  //show inputted vals
  cout << "Customer name: " << customerName << endl;
  cout << "Today's date: " << currentDate << endl;
  cout << endl;

  printMenu(userCart);



}
