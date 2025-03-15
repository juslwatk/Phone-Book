#include "phonebook.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor initializes an empty list
Phonebook::Phonebook() : head(nullptr) {}

// Destructor cleans up all nodes in the list
Phonebook::~Phonebook() {
    Entry* current = head;
    while (current) {
        Entry* temp = current;
        current = current->next;
        delete temp;
    }
}

// Insert at the front of the list
void Phonebook::push_front(const string &first, const string &last, const string &phone) {
    Entry* new_entry = new Entry{first, last, phone, head};
    head = new_entry;
}

// Insert at the end of the list
void Phonebook::push_back(const string &first, const string &last, const string &phone) {
    Entry* new_entry = new Entry{first, last, phone, nullptr};
    if (!head) {
        head = new_entry;
    } else {
        Entry* current = head;
        while (current->next)
            current = current->next;
        current->next = new_entry;
    }
}

// Insert in alphabetical order (sorted by last name)
void Phonebook::insert_sorted(const string &first, const string &last, const string &phone) {
    Entry* new_entry = new Entry{first, last, phone, nullptr};
    if (!head || head->last_name >= last) {
        new_entry->next = head;
        head = new_entry;
    } else {
        Entry* current = head;
        while (current->next && current->next->last_name < last)
            current = current->next;
        new_entry->next = current->next;
        current->next = new_entry;
    }
}

// Read phonebook data from file and insert using insert_sorted
void Phonebook::read_from_file(const string &filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "Unable to open file " << filename << endl;
        return;
    }
    
    string name_line, phone;
    while(getline(infile, name_line)) {
        // Skip empty lines
        if(name_line.empty())
            continue;
        
        // Use an istringstream to parse the name_line into first and last name
        istringstream iss(name_line);
        string first, last;
        iss >> first >> last;
        
        // Read the next line as the phone number
        if(!getline(infile, phone))
            break;
        
        // Insert the entry
        insert_sorted(first, last, phone);
    }
    
    infile.close();
}

// Write the phonebook data to file in the specified format
void Phonebook::write_to_file(const string &filename) const {
    ofstream outfile(filename);
    if (!outfile) {
        cout << "Unable to open file " << filename << endl;
        return;
    }
    Entry* current = head;
    while (current) {
        outfile << current->first_name << " " << current->last_name << "\n";
        outfile << current->phone_number << "\n";
        current = current->next;
    }
    outfile.close();
}

// Lookup phone number by user's last name
string Phonebook::lookup(const string &last) {
    Entry* current = head;
    while (current) {
        if (current->last_name == last)
            return current->phone_number;
        current = current->next;
    }
    return "Not Found";
}

// Reverse lookup: find the user's name by phone number
string Phonebook::reverse_lookup(const string &phone) {
    Entry* current = head;
    while (current) {
        if (current->phone_number == phone)
            return current->first_name + " " + current->last_name;
        current = current->next;
    }
    return "Not Found";
}

// Print the phonebook in a formatted manner
void Phonebook::print() const {
    cout << left << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(20) << "Phone Number" << endl;
    Entry* current = head;
    while (current) {
        cout << left << setw(15) << current->first_name
             << setw(15) << current->last_name
             << setw(20) << current->phone_number << endl;
        current = current->next;
    }
}

// Delete an entry given the user's first and last name
void Phonebook::delete_user(const string &first, const string &last) {
    if (!head)
        return;
    if (head->first_name == first && head->last_name == last) {
        Entry* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Entry* current = head;
    while (current->next) {
        if (current->next->first_name == first && current->next->last_name == last) {
            Entry* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}
