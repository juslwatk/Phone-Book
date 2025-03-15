#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Node definition for a phonebook entry
struct Entry {
    string first_name;
    string last_name;
    string phone_number;
    Entry* next;
};

class Phonebook {
private:
    Entry* head;
public:
    // Constructor & Destructor
    Phonebook();
    ~Phonebook();

    // Basic linked list operations
    void push_front(const string &first, const string &last, const string &phone);
    void push_back(const string &first, const string &last, const string &phone);

    // Insert entry in sorted order (by last name)
    void insert_sorted(const string &first, const string &last, const string &phone);

    // File operations
    void read_from_file(const string &filename);
    void write_to_file(const string &filename) const;

    // Search functions
    string lookup(const string &last);
    string reverse_lookup(const string &phone);

    // Display the phonebook
    void print() const;

    // Delete an entry given the user's name
    void delete_user(const string &first, const string &last);
};

#endif // PHONEBOOK_H
