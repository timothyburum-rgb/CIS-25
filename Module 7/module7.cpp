#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//class to store patient data from the dataset
class Patient {
public:
    string id;
    string gender;
    string age;
    string hypertension;
    string heart_disease;
    string stroke;
};

int main() {
    ifstream file("C:\\Users\\timot\\healthcare-dataset-stroke-data.csv");

    //checks if file opened successfully
    if (!file) {
        cout << "File not found.\n";
        return 0;
    }

    string line;

    //ignores header row
    getline(file, line);

    cout << "==== STROKE DATASET ====\n\n";

    //reads and display 10 entries from the dataset
    int count = 0;
    while (getline(file, line) && count < 10) {
        Patient p;
        string field = "";
        int col = 0;

        //parse each comma-separated field
        for (int i = 0; i <= line.size(); i++) {
            if (i == line.size() || line[i] == ',') {
                if (col == 0) p.id            = field;
                if (col == 1) p.gender        = field;
                if (col == 2) p.age           = field;
                if (col == 3) p.hypertension  = field;
                if (col == 4) p.heart_disease = field;
                if (col == 11) p.stroke       = field;
                field = "";
                col++;
            } else {
                field += line[i];
            }
        }

        //display each patient's information
        cout << "ID: " << p.id << "\n";
        cout << "  Gender:        " << p.gender << "\n";
        cout << "  Age:           " << p.age << "\n";
        cout << "  Hypertension:  " << (p.hypertension == "1" ? "Yes" : "No") << "\n";
        cout << "  Heart Disease: " << (p.heart_disease == "1" ? "Yes" : "No") << "\n";
        cout << "  Stroke:        " << (p.stroke == "1" ? "Yes" : "No") << "\n";
        cout << "----------------------------\n";

        count++;
    }

    file.close();
    return 0;
}
