#include <iostream>
using namespace std;

struct Patient {
int id;
string name;
int age;
};

int main() {
Patient patient1;
  patient1.id = 100;
  patient1.name = "John";
  patient1.age = 25;
  Patient*p = &patient1;

  cout<<"ID:"<<p->id<<endl;
  cout<<"Name:"<<p->name<<endl;
  cout<<"Age:"<<p->age<<endl;
  return 0;
}
