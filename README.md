# Linked List Phonebook

## Overview

This project implements a simple phonebook using a singly linked list. Each node
stores:

- First Name
- Last Name
- Phone Number

The phonebook supports:
- Reading from file (and sorting entries by last name, then first name)
- Writing to file
- Lookup (by name)
- Reverse lookup (by phone number)
- Adding a user in sorted order
- Deleting a user by name
- Printing all entries

## File Descriptions

- **main.cpp**: The driver program. Offers a menu-based interface to interact with the phonebook.
- **phonebook.h**: Header file for the `phonebook` class and its internal `node` struct.
- **phonebook.cpp**: Implementation of the `phonebook` methods.
- **phonebook.txt**: Sample phonebook data. You can modify or create more test files as needed.
- **Makefile**: A simple makefile with a default target and a `clean` target.

## How to Build

1. Open a terminal on a Linux environment (e.g., CS1 or lab machine).
2. Navigate to the folder containing the makefile.
3. Run `make`.

This will compile source files and produce an executable called `phonebook_app`.

## How to Run

1. In the same directory, run `./phonebook_app`.
2. Follow the prompts to read/write files and manipulate the phonebook.

## Notes
- The phonebook sorts entries automatically when reading from a file or inserting a new user.
- Deleting or looking up entries that do not exist yields no results (or empty strings).
- The output format of the file is identical to the input format, so you can read back files you wrote out.

## Author
Justice Watkins/ CSCI325/ Spr 25
