
#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

void showMenu() {
  cout << "1. Add\n2. View\n3. Exit\n";
}

void addItem() {
  string itemName;
  cout << "Enter item name: ";
  cin >> itemName;
  cout << itemName << " added.\n";
}

void viewCart() {
  cout << "Viewing cart...\n";
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
      viewCart();
    }
  } while (option != 3);
  return 0;
}
