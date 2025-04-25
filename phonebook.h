#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>

struct Entry {
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    Entry* next;

    Entry(std::string fn, std::string ln, std::string pn)
        : first_name(fn), last_name(ln), phone_number(pn), next(nullptr) {}
};

class Phonebook {
private:
    Entry* head;

public:
    Phonebook();
    ~Phonebook();

    void push_front(const std::string& fn, const std::string& ln, const std::string& pn);
    void push_back(const std::string& fn, const std::string& ln, const std::string& pn);
    void insert_sorted(const std::string& fn, const std::string& ln, const std::string& pn);

    void read_from_file(const std::string& filename);
    void write_to_file(const std::string& filename);

    std::string lookup(const std::string& name) const;
    std::string reverse_lookup(const std::string& phone_number) const;
    void delete_user(const std::string& name);
    void print() const;
};

#endif
