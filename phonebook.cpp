#include "phonebook.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief Construct a new phonebook::phonebook object
 */
phonebook::phonebook() : head(nullptr) {
}

/**
 * @brief Destroy the phonebook::phonebook object
 */
phonebook::~phonebook() {
    node* current = head;
    while (current != nullptr) {
        node* temp = current;
        current = current->next;
        delete temp;
    }
}

/**
 * @brief Insert at the front of the list
 */
void phonebook::push_front(const std::string &fname,
                           const std::string &lname,
                           const std::string &phone) {
    node* new_node = new node(fname, lname, phone);
    new_node->next = head;
    head = new_node;
}

/**
 * @brief Insert at the back of the list
 */
void phonebook::push_back(const std::string &fname,
                          const std::string &lname,
                          const std::string &phone) {
    node* new_node = new node(fname, lname, phone);
    if (!head) {
        // if list is empty, just assign head
        head = new_node;
        return;
    }
    node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new_node;
}

/**
 * @brief Insert sorted by last name; if last names match, sort by first name
 */
void phonebook::insert_sorted(const std::string &fname,
                              const std::string &lname,
                              const std::string &phone) {
    node* new_node = new node(fname, lname, phone);

    // If list is empty, or new node should go at head
    if (!head ||
        (lname < head->last_name) ||
        (lname == head->last_name && fname < head->first_name)) {
        new_node->next = head;
        head = new_node;
        return;
    }

    // Otherwise, find the correct insertion spot
    node* current = head;
    while (current->next != nullptr) {
        // check next node to see if we should insert before it
        if ((lname < current->next->last_name) ||
            (lname == current->next->last_name &&
             fname < current->next->first_name)) {
            break;
        }
        current = current->next;
    }

    // Insert new_node
    new_node->next = current->next;
    current->next = new_node;
}

/**
 * @brief Read from file
 */
void phonebook::read_from_file(const std::string &filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for reading.\n";
        return;
    }

    std::string firstName, lastName, phoneNum;
    while (true) {
        if (!(fin >> firstName >> lastName)) {
            break; // no more entries
        }
        // read the next line as phone number
        std::getline(fin, phoneNum);
        if (phoneNum.size() > 0 && phoneNum[0] == ' ') {
            // remove leading space if any
            phoneNum.erase(0, 1);
        }

        insert_sorted(firstName, lastName, phoneNum);
    }
    fin.close();
}

/**
 * @brief Write to file
 */
void phonebook::write_to_file(const std::string &filename) const {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    node* current = head;
    while (current) {
        fout << current->first_name << " " 
             << current->last_name << "\n"
             << current->phone_number << "\n";
        current = current->next;
    }
    fout.close();
}

/**
 * @brief Lookup user phone by full name
 */
std::string phonebook::lookup(const std::string &full_name) const {
    // Expect "FirstName LastName"
    // For simplicity, we compare to "first_name last_name"
    node* current = head;
    while (current) {
        std::string combined = current->first_name + " " + current->last_name;
        if (combined == full_name) {
            return current->phone_number;
        }
        current = current->next;
    }
    return ""; // not found
}

/**
 * @brief Reverse lookup name by phone number
 */
std::string phonebook::reverse_lookup(const std::string &phone) const {
    node* current = head;
    while (current) {
        if (current->phone_number == phone) {
            return current->first_name + " " + current->last_name;
        }
        current = current->next;
    }
    return ""; // not found
}

/**
 * @brief Print entire phonebook
 */
void phonebook::print() const {
    node* current = head;
    std::cout << "----- Phonebook Contents -----\n";
    while (current) {
        std::cout << "Name: " << current->first_name << " " 
                  << current->last_name << "\n"
                  << "Phone: " << current->phone_number << "\n\n";
        current = current->next;
    }
    std::cout << "----- End of Phonebook -----\n";
}

/**
 * @brief Delete user from phonebook by full name
 */
void phonebook::delete_user(const std::string &full_name) {
    if (!head) {
        return; // empty list
    }

    // Check if head should be deleted
    std::string headName = head->first_name + " " + head->last_name;
    if (headName == full_name) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Otherwise find the node whose next is the target
    node* current = head;
    while (current->next) {
        std::string nextName = current->next->first_name + " " + current->next->last_name;
        if (nextName == full_name) {
            node* temp = current->next;
            current->next = temp->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}
