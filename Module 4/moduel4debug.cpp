
#include <iostream>
using namespace std;

int() main {
  //added commas between each variable and ended the line with a semicolon instead of a comma
  float n1, n2, n3;
  cout << "Enter three numbers: ";
  //changed > to >> and removed extra n1 variable, added n2
  cin >> n1 >> n2 >> n3;
  //n1=n2 says n1 and n2 are equal, changed to n1>=n2 to compare and closed with parentheses which was missing
  if (n1 >= n2 && n1 >= n3) {
    cout << "Largest number: " << n1;
  }
else {
  if (n2 >= n1 && n2 >= n3) {
    cout << "Largest number: " << n2;
  }
  else {
    cout << "Largest number: " << n3;
  }
}
  return 0;
}
