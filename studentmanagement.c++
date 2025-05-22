#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string grade;
    float marks;

    void input() {
        cout << "Enter ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Age: "; cin >> age;
        cin.ignore();
        cout << "Enter Grade: "; getline(cin, grade);
        cout << "Enter Marks: "; cin >> marks;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Age: " << age << ", Grade: " << grade
             << ", Marks: " << marks << endl;
    }

    string toString() const {
        return to_string(id) + "," + name + "," + to_string(age) + "," + grade + "," + to_string(marks);
    }
};

vector<Student> students;

void loadFromFile() {
    students.clear();
    ifstream file("students.txt");
    string line;
    while (getline(file, line)) {
        Student s;
        stringstream ss(line);
        string item;

        getline(ss, item, ','); s.id = stoi(item);
        getline(ss, s.name, ',');
        getline(ss, item, ','); s.age = stoi(item);
        getline(ss, s.grade, ',');
        getline(ss, item, ','); s.marks = stof(item);

        students.push_back(s);
    }
    file.close();
}

void saveToFile() {
    ofstream file("students.txt");
    for (const Student& s : students) {
        file << s.toString() << endl;
    }
    file.close();
}

void addStudent() {
    Student s;
    s.input();
    students.push_back(s);
    cout << "Student added successfully.\n";
}

void viewAllStudents() {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }
    for (const Student& s : students) {
        s.display();
    }
}

void searchStudent() {
    int searchId;
    cout << "Enter Student ID to search: ";
    cin >> searchId;
    bool found = false;
    for (const Student& s : students) {
        if (s.id == searchId) {
            s.display();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student with ID " << searchId << " not found.\n";
}

void updateStudent() {
    int updateId;
    cout << "Enter Student ID to update: ";
    cin >> updateId;
    bool found = false;
    for (Student& s : students) {
        if (s.id == updateId) {
            cout << "Current details:\n";
            s.display();
            cout << "Enter new details:\n";
            s.input();
            cout << "Record updated.\n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student not found.\n";
}

void deleteStudent() {
    int deleteId;
    cout << "Enter Student ID to delete: ";
    cin >> deleteId;
    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == deleteId) {
            students.erase(it);
            cout << "Student deleted.\n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student not found.\n";
}

void showMenu() {
    cout << "\n===== Student Management System =====\n";
    cout << "1. Add Student\n";
    cout << "2. View All Students\n";
    cout << "3. Search Student by ID\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Save to File\n";
    cout << "7. Load from File\n";
    cout << "8. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    loadFromFile(); // Optional: auto-load on start

    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: saveToFile(); break;
            case 7: loadFromFile(); break;
            case 8: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
