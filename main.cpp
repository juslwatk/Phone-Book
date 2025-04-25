#include "phonebook.h"
#include <iostream>

int main() {
    Phonebook pb;
    int choice;
    std::string fname, lname, phone, filename, query;

    do {
        std::cout << "\nWelcome to the UTM Phonebook!\n"
                  << "1. Read a phonebook from a file\n"
                  << "2. Write the phonebook to a file\n"
                  << "3. Print the phonebook\n"
                  << "4. Search for a user's phone number\n"
                  << "5. Reverse lookup by phone number\n"
                  << "6. Add a user\n"
                  << "7. Delete a user\n"
                  << "8. Exit\n"
                  << "Please enter your choice: ";
        std::cin >> choice;

        std::cin.ignore(); // clear newline
        switch (choice) {
            case 1:
                std::cout << "Enter file name: ";
                std::getline(std::cin, filename);
                pb.read_from_file(filename);
                break;
            case 2:
                std::cout << "Enter file name to write to: ";
                std::getline(std::cin, filename);
                pb.write_to_file(filename);
                break;
            case 3:
                pb.print();
                break;
            case 4:
                std::cout << "Enter full name to search: ";
                std::getline(std::cin, query);
                std::cout << pb.lookup(query) << "\n";
                break;
            case 5:
                std::cout << "Enter phone number to search: ";
                std::getline(std::cin, query);
                std::cout << pb.reverse_lookup(query) << "\n";
                break;
            case 6:
                std::cout << "Enter first name: ";
                std::getline(std::cin, fname);
                std::cout << "Enter last name: ";
                std::getline(std::cin, lname);
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phone);
                pb.insert_sorted(fname, lname, phone);
                break;
            case 7:
                std::cout << "Enter full name to delete: ";
                std::getline(std::cin, query);
                pb.delete_user(query);
                break;
            case 8:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 8);

    return 0;
}
