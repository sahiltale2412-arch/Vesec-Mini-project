#include <iostream>
#include <queue>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;
 
struct Patient {
    int    token;
    string name;
    int    age;
    string problem;
};
 
queue<Patient> q;      // waiting line (FIFO)
int lastToken = 0;     // last token number issued
 
void registerPatient() {
    Patient p;
    cout << "Enter patient name   : ";
    cin >> ws;
    getline(cin, p.name);
    cout << "Enter age            : ";
    while (!(cin >> p.age) || p.age <= 0 || p.age > 120) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid age. Enter age again: ";
    }
    cout << "Enter problem        : ";
    cin >> ws;
    getline(cin, p.problem);
 
    p.token = ++lastToken;
    q.push(p);                                   // enqueue
    cout << "Token T" << p.token << " issued to " << p.name << "\n";
    cout << "Patients waiting: " << q.size() << "\n";
}
 
void callNext() {
    if (q.empty()) {
        cout << "No patients waiting\n";
        return;
    }
    Patient p = q.front();                       // peek
    q.pop();                                     // dequeue
    cout << "Now serving: T" << p.token << " " << p.name << "\n";
    cout << "Waiting: " << q.size() << " patient(s)\n";
}
 
void showNext() {
    if (q.empty()) {
        cout << "No patients waiting\n";
        return;
    }
    cout << "Next patient: T" << q.front().token << " "
         << q.front().name << " (" << q.front().problem << ")\n";
}
 
void displayList() {
    if (q.empty()) {
        cout << "No patients waiting\n";
        return;
    }
    queue<Patient> temp = q;                     // copy; real queue stays intact
    cout << left << setw(8) << "Token" << setw(14) << "Name"
         << setw(6) << "Age" << "Problem\n";
    cout << "------------------------------------------\n";
    while (!temp.empty()) {
        Patient p = temp.front();
        temp.pop();
        cout << left << setw(8) << ("T" + to_string(p.token))
             << setw(14) << p.name << setw(6) << p.age
             << p.problem << "\n";
    }
}
 
void countWaiting() {
    cout << "Patients waiting: " << q.size() << "\n";
}
 
int main() {
    int choice;
    do {
        cout << "\n===== HOSPITAL TOKEN SYSTEM =====\n"
             << "1. Register new patient\n"
             << "2. Call next patient\n"
             << "3. Show next patient\n"
             << "4. Display waiting list\n"
             << "5. Count waiting patients\n"
             << "6. Exit\n"
             << "Enter choice: ";
        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
        }
        switch (choice) {
            case 1: registerPatient(); break;
            case 2: callNext();        break;
            case 3: showNext();        break;
            case 4: displayList();     break;
            case 5: countWaiting();    break;
            case 6: cout << "Thank you. Exiting.\n"; break;
            default: cout << "Invalid choice. Please enter 1-6.\n";
        }
    } while (choice != 6);
    return 0;
}