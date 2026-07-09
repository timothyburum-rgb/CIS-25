#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//struct to store patient data
struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

//binary search by patient ID
int binarySearch(Patient* patients, int count, int searchID) {
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (patients[mid].id == searchID)
            return mid;
        if (patients[mid].id < searchID)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

//display menu
void showMenu() {
    cout << "\nHospital Patient System\n";
    cout << "1. Add Patient\n";
    cout << "2. Display Patients\n";
    cout << "3. Search Patient\n";
    cout << "4. Update Patient\n";
    cout << "5. Save Patients\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
}

//add patient
void addPatient(Patient* patients, int &count) {
    cout << "Enter Patient ID: ";
    cin >> patients[count].id;
    cout << "Enter Name: ";
    cin >> patients[count].name;
    cout << "Enter Age: ";
    cin >> patients[count].age;
    cout << "Enter Gender: ";
    cin >> patients[count].gender;
    cout << "Enter Diagnosis: ";
    cin >> patients[count].diagnosis;
    count++;
    cout << "Patient added.\n";
}

//display patient
void displayPatients(Patient* patients, int count) {
    if (count == 0) {
        cout << "No patients on record.\n";
        return;
    }
    cout << "\nPatient Records\n";
    for (int i = 0; i < count; i++) {
        cout << "\nID: " << patients[i].id << "\n";
        cout << "Name: " << patients[i].name << "\n";
        cout << "Age: " << patients[i].age << "\n";
        cout << "Gender: " << patients[i].gender << "\n";
        cout << "Diagnosis: " << patients[i].diagnosis << "\n";
    }
}

//search for patient
void searchPatient(Patient* patients, int count) {
    int searchID;
    cout << "Enter patient ID to search: ";
    cin >> searchID;
    int result = binarySearch(patients, count, searchID);
    if (result != -1) {
        cout << "Patient Found\n";
        cout << "Name: " << patients[result].name << "\n";
        cout << "Age: " << patients[result].age << "\n";
        cout << "Diagnosis: " << patients[result].diagnosis << "\n";
    } else {
        cout << "Patient not found.\n";
    }
}

//update patient diagnosis
void updatePatient(Patient* patients, int count) {
    int searchID;
    cout << "Enter patient ID to update: ";
    cin >> searchID;
    int result = binarySearch(patients, count, searchID);
    if (result != -1) {
        cout << "Enter new diagnosis: ";
        cin >> patients[result].diagnosis;
        cout << "Patient updated.\n";
    } else {
        cout << "Patient not found.\n";
    }
}

//save patient to patients.txt file
void savePatients(Patient* patients, int count) {
    ofstream file("C:\\Users\\timot\\patients.txt");
    for (int i = 0; i < count; i++) {
        file << patients[i].id << " "
             << patients[i].name << " "
             << patients[i].age << " "
             << patients[i].gender << " "
             << patients[i].diagnosis << "\n";
    }
    file.close();
    cout << "Patients saved to patients.txt\n";
}

int main() {
    //store up to 100 patients
    Patient* patients = new Patient[100];
    int count = 0;

    int choice;
    do {
        showMenu();
        cin >> choice;
        if (choice == 1)
            addPatient(patients, count);
        if (choice == 2)
            displayPatients(patients, count);
        if (choice == 3)
            searchPatient(patients, count);
        if (choice == 4)
            updatePatient(patients, count);
        if (choice == 5)
            savePatients(patients, count);
        if (choice == 6)
            cout << "Good Bye!\n";
    } while (choice != 6);

    delete[] patients;
    return 0;
}
