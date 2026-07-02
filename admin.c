#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For system() to clear screen

#include "admin.h"
#include "book.h" // Include header for Book structure and utilities
#include "data_handler.h" // For saving data after modifications

// Admin Mode function - provides a menu for administrative tasks
void admin_mode(Book *books, int *count) {
    int choice;
    do {
        system("cls || clear"); // Clear the console screen (cross-platform)
        printf("\n--- Admin Mode ---\n");
        printf("1. Add New Book\n");
        printf("2. Remove Book\n");
        printf("3. View All Books\n");
        printf("4. View Borrowed Books\n");
        printf("5. View Total Books Count\n");
        printf("6. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer(); // Clear any leftover characters in the input buffer

        switch (choice) {
            case 1:
                add_new_book(books, count);
                break;
            case 2:
                remove_book(books, count);
                break;
            case 3:
                view_all_books(books, count); 
                break;
            case 4:
                view_borrowed_books(books, count); 
                break;
            case 5:
                view_total_books_count(count); 
                break;
            case 6:
                printf("Logging out from Admin Mode...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        if (choice != 6) { // If user didn't choose to logout, wait for user input
            printf("\nPress Enter to continue...");
            clear_input_buffer();
        }
    } while (choice != 6); // Loop until user chooses to logout
}

// Function to add a new book to the library
void add_new_book(Book *books, int *count) {
    if (*count >= MAX_BOOKS) { // Check if the library is full
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book new_book;
    new_book.id = get_next_id(books, *count); // Get a unique ID for the new book

    printf("\n--- Add New Book ---\n");
    printf("Enter Title: ");
    fgets(new_book.title, MAX_TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove trailing newline from input

    printf("Enter Author: ");
    fgets(new_book.author, MAX_AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;

    printf("Enter Publication Year: ");
    scanf("%d", &new_book.publication_year);
    clear_input_buffer();

    new_book.is_borrowed = 0; // A newly added book is always available

    books[*count] = new_book; // Add the new book to the array
    (*count)++; // Increment the total book count
    save_books("library_books.txt", books, *count); // Save changes to file
    printf("Book '%s' added successfully with ID %d.\n", new_book.title, new_book.id);
}

// Function to remove a book from the library by its ID
void remove_book(Book *books, int *count) {
    if (*count == 0) { // Check if there are any books to remove
        printf("No books in the library to remove.\n");
        return;
    }

    int id_to_remove;
    printf("\n--- Remove Book ---\n");
    printf("Enter the ID of the book to remove: ");
    scanf("%d", &id_to_remove);
    clear_input_buffer();

    int found_index = -1; // Flag to store the index of the found book
    for (int i = 0; i < *count; i++) {
        if (books[i].id == id_to_remove) {
            found_index = i;
            break; // Book found, exit loop
        }
    }

    if (found_index != -1) {
        // If the book is found, print confirmation and shift remaining elements
        printf("Book '%s' by %s (ID: %d) removed successfully.\n",
               books[found_index].title, books[found_index].author, books[found_index].id);
        for (int i = found_index; i < *count - 1; i++) {
            books[i] = books[i+1]; // Shift elements to the left
        }
        (*count)--; // Decrease the total book count
        save_books("library_books.txt", books, *count); // Save changes to file
    } else {
        printf("Book with ID %d not found.\n", id_to_remove);
    }
}

// Function to display all books currently in the library
void view_all_books(const Book *books, int *count) { 
    printf("\n--- All Books in Library (%d total) ---\n", *count);
    if (*count == 0) { // Check if the library is empty
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < *count; i++) { 
        display_book(&books[i]); // Use the utility function to display each book
    }
}

// Function to display only the books that are currently borrowed
void view_borrowed_books(const Book *books, int *count) {
    printf("\n--- Borrowed Books ---\n");
    int borrowed_count = 0;
    for (int i = 0; i < *count; i++) {
        if (books[i].is_borrowed) { // Check if the book is marked as borrowed
            display_book(&books[i]);
            borrowed_count++;
        }
    }
    if (borrowed_count == 0) { // If no books are borrowed
        printf("No books are currently borrowed.\n");
    }
}

// Function to display the total count of books in the library
void view_total_books_count(int *count) { 
    printf("\nTotal number of books in the library: %d\n", *count);
}