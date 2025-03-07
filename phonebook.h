#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>

/**
 * @class phonebook
 * @brief A singly linked list to store a simple phone directory.
 *
 * Each entry holds a first name, last name, and phone number.
 */
class phonebook {
private:
    /**
     * @struct node
     * @brief Represents one entry in the phonebook.
     */
    struct node {
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        node* next;

        // convenience constructor
        node(const std::string &f,
             const std::string &l,
             const std::string &p)
            : first_name(f), last_name(l), phone_number(p), next(nullptr) {}
    };

    node* head;  ///< Pointer to the front (head) of the linked list

public:
    /**
     * @brief Default Constructor: initialize an empty list.
     */
    phonebook();

    /**
     * @brief Destructor: free all dynamically allocated nodes.
     */
    ~phonebook();

    /**
     * @brief Insert an entry at the front of the list.
     * @param fname first name
     * @param lname last name
     * @param phone phone number
     */
    void push_front(const std::string &fname,
                    const std::string &lname,
                    const std::string &phone);

    /**
     * @brief Insert an entry at the back of the list.
     * @param fname first name
     * @param lname last name
     * @param phone phone number
     */
    void push_back(const std::string &fname,
                   const std::string &lname,
                   const std::string &phone);

    /**
     * @brief Insert a new entry into the list, sorted by last name.
     *        If there is a tie on last name, sort by first name.
     * @param fname first name
     * @param lname last name
     * @param phone phone number
     */
    void insert_sorted(const std::string &fname,
                       const std::string &lname,
                       const std::string &phone);

    /**
     * @brief Read from a text file and insert (sorted) all entries into the list.
     * @param filename Name of the file to read from
     */
    void read_from_file(const std::string &filename);

    /**
     * @brief Write all phonebook entries to a file in the same format used by read_from_file.
     * @param filename Name of the file to write to
     */
    void write_to_file(const std::string &filename) const;

    /**
     * @brief Search by (first name, last name) or just last name (depending on how you want to interpret).
     *        For the assignment description, we will assume it takes a full name ("John Doe").
     * @param full_name "firstName lastName" (you can parse inside if you want).
     * @return The phone number associated with that name. Empty string if not found.
     */
    std::string lookup(const std::string &full_name) const;

    /**
     * @brief Reverse lookup: given a phone number, find the name.
     * @param phone The phone number to search for
     * @return The "firstName lastName" associated with that phone number. 
     *         Empty string if not found.
     */
    std::string reverse_lookup(const std::string &phone) const;

    /**
     * @brief Print the entire phonebook to std::cout.
     */
    void print() const;

    /**
     * @brief Delete a user from the phonebook by name.
     * @param full_name "firstName lastName"
     */
    void delete_user(const std::string &full_name);
};

#endif
