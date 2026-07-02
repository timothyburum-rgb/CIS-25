#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Item {
public:
    string name;
    double price;
    int quantity;
    float getTotalPrice() {
        return price * quantity;
    }
};
void showMenu() {
    cout << "==== SHOPPING CART MENU ====\n";
    cout << "1. Add item to cart\n";
    cout << "2. View checkout\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}
void addItem() {
    Item item;
    cout << "Enter item name: ";
    cin >> item.name;
    cout << "Enter item price: ";
    cin >> item.price;
    cout << "Enter item quantity: ";
    cin >> item.quantity;
    ofstream file("cart.txt", ios::app);
    file << item.name << " " << item.price << " " << item.quantity << "\n";
    file.close();
    cout << "Item added to cart.\n";
}
void viewCheckout() {
    Item item;
    float grandTotal = 0;
    ifstream file("cart.txt");
    cout << "==== CHECKOUT ====\n";
    while (file >> item.name >> item.price >> item.quantity) {
        cout << item.name << " - $" << item.price << " x " << item.quantity << " = $" << item.getTotalPrice() << "\n";
        grandTotal += item.getTotalPrice();
    }
    file.close();
    cout << "--------------------\n";
    cout << "Total: $" << grandTotal << "\n";
}
int main() {
    int option;
    do {
        showMenu();
        cin >> option;
        if (option == 1) {
            addItem();
        }
        if (option == 2) {
            viewCheckout();
        }
        if (option == 3) {
            cout << "Thank you for shopping!\n";
        }
    } while (option != 3);
    return 0;
}
