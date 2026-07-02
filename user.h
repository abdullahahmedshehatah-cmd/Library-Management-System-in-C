#ifndef USER_H
#define USER_H

#include "book.h" // Include header for Book struct and related functions

// Function declarations for User Mode operations
void user_mode(Book *books, int *count);
void view_available_books(const Book *books, int count);
void borrow_book(Book *books, int count);
void return_book(Book *books, int count);
void search_books_by_title(const Book *books, int count);
void filter_books_by_author(const Book *books, int count);
void filter_books_by_year(const Book *books, int count);

#endif // USER_H