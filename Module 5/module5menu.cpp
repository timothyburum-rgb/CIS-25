
#include <iostream>
#include <string>
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

void viewInventory() {
  cout << "Viewing inventory...\n";
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
      viewInventory();
    }
  } while (option != 3);
  return 0;
}
