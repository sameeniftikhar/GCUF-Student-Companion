#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// --- MODULE 1: GPA (Your existing logic) ---
void gpaModule() {
    float obtained, total;
    cout << "\n--- GPA Calculator ---\n";
    cout << "Enter Obtained Marks: ";
    cin >> obtained;
    cout << "Enter Total Marks: ";
    cin >> total;
    if (total > 0) {
        float percent = (obtained / total) * 100;
        cout << "Your Percentage: " << percent << "%\n";
        if (percent >= 85) cout << "Grade: A - Excellent!\n";
        else if (percent >= 70) cout << "Grade: B - Good!\n";
        else cout << "Grade: C - Keep working!\n";
    }
}

// --- MODULE 2: BUDGET TRACKER (New + File Handling) ---
void addExpense() {
    string item;
    float amount;
    cout << "\nEnter Expense Name (e.g., Mess, Books): ";
    cin >> item;
    cout << "Enter Amount Rs: ";
    cin >> amount;

    // Saving to file - PRO feature
    ofstream file("budget.txt", ios::app);
    file << item << " - Rs " << amount << endl;
    file.close();
    cout << "Saved! Expense added to budget.txt\n";
}

void viewBudget() {
    cout << "\n--- Your Monthly Budget Report ---\n";
    ifstream file("budget.txt");
    string line;
    bool empty = true;
    while (getline(file, line)) {
        cout << line << endl;
        empty = false;
    }
    if (empty) cout << "No expenses yet. Add some!\n";
    file.close();
}

// --- MAIN MENU ---
int main() {
    int choice;
    do {
        cout << "\n===============================\n";
        cout << " GCUF STUDENT COMPANION v1.0 \n";
        cout << "===============================\n";
        cout << "1. GPA Calculator\n";
        cout << "2. Add Daily Expense\n";
        cout << "3. View Budget Report\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) gpaModule();
        else if (choice == 2) addExpense();
        else if (choice == 3) viewBudget();
        else if (choice == 4) cout << "Allah Hafiz! See you soon Sameen!\n";
        else cout << "Invalid choice, try again!\n";

    } while (choice != 4);

    return 0;
}
