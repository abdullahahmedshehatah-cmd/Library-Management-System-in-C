#ifndef ADMIN_H
#define ADMIN_H

#include "book.h" // Include header for Book structure

// Function declarations for Admin Mode operations
void admin_mode(Book *books, int *count);
void add_new_book(Book *books, int *count);
void remove_book(Book *books, int *count);
void view_all_books(const Book *books, int *count);
void view_borrowed_books(const Book *books, int *count);
void view_total_books_count(int *count);

#endif // ADMIN_H