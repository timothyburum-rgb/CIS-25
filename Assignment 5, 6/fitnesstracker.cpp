#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//class to store each entry
class Entry {
public:
    int id;
    string name;
    string type;
    int duration;
};

//display menu
void showMenu() {
    cout << "\n==== FITNESS & HABIT TRACKER ====\n";
    cout << "1. Add Entry\n";
    cout << "2. View All Entries\n";
    cout << "3. Update Entry\n";
    cout << "4. Delete Entry\n";
    cout << "5. Display Total Workout Time\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
}

//add new entry
void addEntry(Entry* entries, int& count) {
    cout << "Enter ID: ";
    cin >> entries[count].id;
    cout << "Enter habit/workout name: ";
    cin >> entries[count].name;
    cout << "Enter type (Running, Weightlifting, Stretching, etc): ";
    cin >> entries[count].type;
    cout << "Enter duration (minutes): ";
    cin >> entries[count].duration;
    count++;
    cout << "Entry added.\n";
}

//display entries
void viewEntries(Entry* entries, int count) {
    if (count == 0) {
        cout << "No entries on record.\n";
        return;
    }
    cout << "\n==== ALL ENTRIES ====\n";
    for (int i = 0; i < count; i++) {
        cout << "\nID: " << entries[i].id << "\n";
        cout << "Name: " << entries[i].name << "\n";
        cout << "Type: " << entries[i].type << "\n";
        cout << "Duration: " << entries[i].duration << " minutes\n";
    }
}

//update entry
void updateEntry(Entry* entries, int count) {
    int searchID;
    cout << "Enter ID to update: ";
    cin >> searchID;
    for (int i = 0; i < count; i++) {
        if (entries[i].id == searchID) {
            cout << "Enter new duration (minutes): ";
            cin >> entries[i].duration;
            cout << "Entry updated.\n";
            return;
        }
    }
    cout << "Entry not found.\n";
}

//delete entry
void deleteEntry(Entry* entries, int& count) {
    int searchID;
    cout << "Enter ID to delete: ";
    cin >> searchID;
    for (int i = 0; i < count; i++) {
        if (entries[i].id == searchID) {
            for (int j = i; j < count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            count--;
            cout << "Entry deleted.\n";
            return;
        }
    }
    cout << "Entry not found.\n";
}

//display total time
void totalWorkoutTime(Entry* entries, int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += entries[i].duration;
    }
    cout << "Total workout time: " << total << " minutes\n";
}

//save entries to .txt file
void saveEntries(Entry* entries, int count) {
    ofstream file("C:\\Users\\timot\\fitness.txt");
    for (int i = 0; i < count; i++) {
        file << entries[i].id << " "
            << entries[i].name << " "
            << entries[i].type << " "
            << entries[i].duration << "\n";
    }
    file.close();
}

//load entries from .txt file
void loadEntries(Entry* entries, int& count) {
    ifstream file("C:\\Users\\timot\\fitness.txt");
    if (!file)
        return;
    while (file >> entries[count].id
        >> entries[count].name
        >> entries[count].type
        >> entries[count].duration) {
        count++;
    }
    file.close();
}

int main() {
    //dynamic array
    Entry* entries = new Entry[100];
    int count = 0;

    //load entries on startup
    loadEntries(entries, count);

    int choice;
    do {
        showMenu();
        cin >> choice;
        if (choice == 1) {
            addEntry(entries, count);
            saveEntries(entries, count);
        }
        if (choice == 2)
            viewEntries(entries, count);
        if (choice == 3) {
            updateEntry(entries, count);
            saveEntries(entries, count);
        }
        if (choice == 4) {
            deleteEntry(entries, count);
            saveEntries(entries, count);
        }
        if (choice == 5)
            totalWorkoutTime(entries, count);
        if (choice == 6)
            cout << "Goodbye!\n";
    } while (choice != 6);

    delete[] entries;
    return 0;
}
