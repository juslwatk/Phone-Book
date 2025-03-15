#include <iostream>
#include "phonebook.h"

using namespace std;

int main() {
    Phonebook pb;
    int choice;
    string filename, first, last, phone, searchName, searchPhone;

    do {
        cout << "\nWelcome to the UTM Phonebook! You may select one of the following options:\n";
        cout << "1. Read a phonebook from a file\n";
        cout << "2. Write the phonebook to a file\n";
        cout << "3. Print the phonebook\n";
        cout << "4. Search for a user's phone number\n";
        cout << "5. Reverse lookup by phone number\n";
        cout << "6. Add a user\n";
        cout << "7. Delete a user\n";
        cout << "8. Exit this program\n";
        cout << "Please enter your choice now: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter filename to read from: ";
                cin >> filename;
                pb.read_from_file(filename);
                break;
            case 2:
                cout << "Enter filename to write to: ";
                cin >> filename;
                pb.write_to_file(filename);
                break;
            case 3:
                pb.print();
                break;
            case 4:
                cout << "Enter user's last name to search for: ";
                cin >> searchName;
                cout << "Phone number: " << pb.lookup(searchName) << endl;
                break;
            case 5:
                cout << "Enter phone number for reverse lookup: ";
                cin.ignore(); // clear newline from input buffer
                getline(cin, searchPhone);
                cout << "User: " << pb.reverse_lookup(searchPhone) << endl;
                break;
            case 6:
                cout << "Enter first name: ";
                cin >> first;
                cout << "Enter last name: ";
                cin >> last;
                cout << "Enter phone number: ";
                cin.ignore();
                getline(cin, phone);
                pb.insert_sorted(first, last, phone);
                break;
            case 7:
                cout << "Enter first name of user to delete: ";
                cin >> first;
                cout << "Enter last name of user to delete: ";
                cin >> last;
                pb.delete_user(first, last);
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 8);
    return 0;
}
