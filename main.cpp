#include <iostream>
#include <string>
#include <iomanip>
#include "phonebook.h"

/**
 * @file main.cpp
 * @brief Driver for the phonebook class. Handles user interaction with the phonebook.
 */

void print_menu() {
    std::cout << "\nWelcome to the UTM Phonebook! You may select one of the following options:\n"
              << "1) Read a phonebook from a file\n"
              << "2) Write the phonebook to a file\n"
              << "3) Print the phonebook\n"
              << "4) Search for a user's phone number\n"
              << "5) Reverse lookup by phone number\n"
              << "6) Add a user\n"
              << "7) Delete a user\n"
              << "8) Exit this program\n\n"
              << "Please enter your choice now: ";
}

int main() {
    phonebook pb;  // create an empty phonebook

    int choice = 0;
    do {
        print_menu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush leftover

        switch (choice) {
        case 1: {
            // Read from file
            std::cout << "Enter filename to read from: ";
            std::string filename;
            std::getline(std::cin, filename);
            pb.read_from_file(filename);
            std::cout << "Done reading from file.\n";
            break;
        }
        case 2: {
            // Write to file
            std::cout << "Enter filename to write to: ";
            std::string filename;
            std::getline(std::cin, filename);
            pb.write_to_file(filename);
            std::cout << "Done writing to file.\n";
            break;
        }
        case 3: {
            // Print
            pb.print();
            break;
        }
        case 4: {
            // Lookup
            std::cout << "Enter name (\"FirstName LastName\"): ";
            std::string name;
            std::getline(std::cin, name);
            std::string phone = pb.lookup(name);
            if (!phone.empty()) {
                std::cout << "Phone number for " << name << " is: " << phone << "\n";
            } else {
                std::cout << "No entry found for " << name << "\n";
            }
            break;
        }
        case 5: {
            // Reverse lookup
            std::cout << "Enter phone number: ";
            std::string phone;
            std::getline(std::cin, phone);
            std::string name = pb.reverse_lookup(phone);
            if (!name.empty()) {
                std::cout << "Name associated with " << phone << " is: " << name << "\n";
            } else {
                std::cout << "No entry found for phone " << phone << "\n";
            }
            break;
        }
        case 6: {
            // Add user
            std::cout << "Enter first name: ";
            std::string fname;
            std::getline(std::cin, fname);
            std::cout << "Enter last name: ";
            std::string lname;
            std::getline(std::cin, lname);
            std::cout << "Enter phone number: ";
            std::string pnum;
            std::getline(std::cin, pnum);

            pb.insert_sorted(fname, lname, pnum);
            std::cout << "User added.\n";
            break;
        }
        case 7: {
            // Delete user
            std::cout << "Enter name (\"FirstName LastName\") to delete: ";
            std::string name;
            std::getline(std::cin, name);
            pb.delete_user(name);
            std::cout << "If the user existed, they have been removed.\n";
            break;
        }
        case 8: {
            // Exit
            std::cout << "Exiting program...\n";
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }

    } while (choice != 8);

    return 0;
}
