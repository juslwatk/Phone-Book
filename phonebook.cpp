#include "phonebook.h"
#include <iostream>
#include <fstream>
#include <sstream>

Phonebook::Phonebook() : head(nullptr) {}

Phonebook::~Phonebook() {
    while (head) {
        Entry* temp = head;
        head = head->next;
        delete temp;
    }
}

void Phonebook::push_front(const std::string& fn, const std::string& ln, const std::string& pn) {
    Entry* new_node = new Entry(fn, ln, pn);
    new_node->next = head;
    head = new_node;
}

void Phonebook::push_back(const std::string& fn, const std::string& ln, const std::string& pn) {
    Entry* new_node = new Entry(fn, ln, pn);
    if (!head) {
        head = new_node;
        return;
    }
    Entry* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
}

void Phonebook::insert_sorted(const std::string& fn, const std::string& ln, const std::string& pn) {
    Entry* new_node = new Entry(fn, ln, pn);
    if (!head || ln < head->last_name) {
        new_node->next = head;
        head = new_node;
        return;
    }
    Entry* current = head;
    while (current->next && current->next->last_name < ln) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void Phonebook::read_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }

    std::string fn, ln, pn;
    int count = 0;
    while (file >> fn >> ln) {
        std::getline(file, pn);
        if (!pn.empty() && pn[0] == ' ') pn.erase(0, 1);  // trim space
        insert_sorted(fn, ln, pn);
        ++count;
    }

    std::cout << "📄 Successfully loaded " << count << " entries from " << filename << "\n";
}



void Phonebook::write_to_file(const std::string& filename) {
    std::ofstream file(filename);
    Entry* current = head;
    while (current) {
        file << current->first_name << " " << current->last_name << "\n"
             << current->phone_number << "\n";
        current = current->next;
    }
}

std::string Phonebook::lookup(const std::string& name) const {
    Entry* current = head;
    while (current) {
        if (current->first_name + " " + current->last_name == name)
            return current->phone_number;
        current = current->next;
    }
    return "User not found.";
}

std::string Phonebook::reverse_lookup(const std::string& phone_number) const {
    Entry* current = head;
    while (current) {
        if (current->phone_number == phone_number)
            return current->first_name + " " + current->last_name;
        current = current->next;
    }
    return "Phone number not found.";
}

void Phonebook::delete_user(const std::string& name) {
    Entry* current = head;
    Entry* prev = nullptr;

    while (current) {
        if (current->first_name + " " + current->last_name == name) {
            if (!prev) head = current->next;
            else prev->next = current->next;
            delete current;
            std::cout << "User deleted.\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    std::cout << "User not found.\n";
}

void Phonebook::print() const {
    Entry* current = head;
    while (current) {
        std::cout << "Name: " << current->first_name << " " << current->last_name << "\n"
                  << "Phone: " << current->phone_number << "\n\n";
        current = current->next;
    }
}
