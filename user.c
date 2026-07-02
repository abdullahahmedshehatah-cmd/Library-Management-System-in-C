#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For system()

#include "user.h"        // Ensure this line is present
#include "book.h"        // Include header for Book struct and related functions (defines MAX_BOOKS)
#include "data_handler.h" // For saving data after modifications

// User Mode function - provides a menu for user interactions
void user_mode(Book *books, int *count) {
    int choice;
    do {
        system("cls || clear"); // Clear screen (for Windows and Unix/Linux)
        printf("\n--- User Mode ---\n");
        printf("1. View Available Books\n");
        printf("2. Borrow a Book\n");
        printf("3. Return a Book\n");
        printf("4. Search Books by Title\n");
        printf("5. Filter Books by Author\n");
        printf("6. Filter Books by Year\n");
        printf("7. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer(); // Clear any leftover characters in the input buffer

        switch (choice) {
            case 1:
                view_available_books(books, *count);
                break;
            case 2:
                borrow_book(books, *count);
                save_books("library_books.txt", books, *count); // Save changes after borrowing
                break;
            case 3:
                return_book(books, *count);
                save_books("library_books.txt", books, *count); // Save changes after returning
                break;
            case 4:
                search_books_by_title(books, *count);
                break;
            case 5:
                filter_books_by_author(books, *count);
                break;
            case 6:
                filter_books_by_year(books, *count);
                break;
            case 7:
                printf("Logging out from User Mode...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        if (choice != 7) { // If user didn't choose to logout, wait for user input
            printf("\nPress Enter to continue...");
            clear_input_buffer();
        }
    } while (choice != 7); // Loop until user chooses to logout
}

// Function to view books currently available for borrowing
void view_available_books(const Book *books, int count) {
    printf("\n--- Available Books ---\n");
    int available_count = 0;
    if (count == 0) { // Check if there are any books in the library
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        if (!books[i].is_borrowed) { // Check if the book is NOT marked as borrowed
            display_book(&books[i]);
            available_count++;
        }
    }
    if (available_count == 0) { // If no books are available
        printf("No books are currently available.\n");
    }
}

// Function to allow a user to borrow a book
void borrow_book(Book *books, int count) {
    if (count == 0) { // Check if there are any books to borrow
        printf("No books in the library to borrow.\n");
        return;
    }

    int id_to_borrow;
    printf("\n--- Borrow Book ---\n");
    printf("Enter the ID of the book you want to borrow: ");
    scanf("%d", &id_to_borrow);
    clear_input_buffer();

    int found_index = -1; // Flag to store the index of the found book
    for (int i = 0; i < count; i++) {
        if (books[i].id == id_to_borrow) {
            found_index = i;
            break; // Book found, exit loop
        }
    }

    if (found_index != -1) { // If the book is found
        if (!books[found_index].is_borrowed) { // Check if it's not already borrowed
            books[found_index].is_borrowed = 1; // Set status to borrowed
            printf("Book '%s' (ID: %d) successfully borrowed.\n",
                   books[found_index].title, books[found_index].id);
        } else {
            printf("Book '%s' (ID: %d) is already borrowed.\n",
                   books[found_index].title, books[found_index].id);
        }
    } else { // If book with given ID is not found
        printf("Book with ID %d not found.\n", id_to_borrow);
    }
}

// Function to allow a user to return a book
void return_book(Book *books, int count) {
    if (count == 0) { // Check if there are any books in the library
        printf("No books in the library.\n");
        return;
    }

    int id_to_return;
    printf("\n--- Return Book ---\n");
    printf("Enter the ID of the book you want to return: ");
    scanf("%d", &id_to_return);
    clear_input_buffer();

    int found_index = -1; // Flag to store the index of the found book
    for (int i = 0; i < count; i++) {
        if (books[i].id == id_to_return) {
            found_index = i;
            break; // Book found, exit loop
        }
    }

    if (found_index != -1) { // If the book is found
        if (books[found_index].is_borrowed) { // Check if it was actually borrowed
            books[found_index].is_borrowed = 0; // Set status to available
            printf("Book '%s' (ID: %d) successfully returned.\n",
                   books[found_index].title, books[found_index].id);
        } else {
            printf("Book '%s' (ID: %d) was not borrowed.\n",
                   books[found_index].title, books[found_index].id);
        }
    } else { // If book with given ID is not found
        printf("Book with ID %d not found.\n", id_to_return);
    }
}

// Function to search for books by title (case-sensitive substring match)
void search_books_by_title(const Book *books, int count) {
    char search_title[MAX_TITLE_LEN];
    printf("\n--- Search Books by Title ---\n");
    printf("Enter title to search: ");
    fgets(search_title, MAX_TITLE_LEN, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Remove trailing newline from input

    int found_count = 0;
    for (int i = 0; i < count; i++) {
        // strstr searches for search_title as a substring within book's title
        if (strstr(books[i].title, search_title) != NULL) {
            display_book(&books[i]);
            found_count++;
        }
    }
    if (found_count == 0) { // If no books match the search criteria
        printf("No books found with title containing '%s'.\n", search_title);
    }
}

// Function to filter and display books by author (case-sensitive substring match)
void filter_books_by_author(const Book *books, int count) {
    char filter_author[MAX_AUTHOR_LEN];
    printf("\n--- Filter Books by Author ---\n");
    printf("Enter author name to filter: ");
    fgets(filter_author, MAX_AUTHOR_LEN, stdin);
    filter_author[strcspn(filter_author, "\n")] = 0;

    int found_count = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].author, filter_author) != NULL) {
            display_book(&books[i]);
            found_count++;
        }
    }
    if (found_count == 0) {
        printf("No books found by author containing '%s'.\n", filter_author);
    }
}

// Function to filter and display books by a specific publication year
void filter_books_by_year(const Book *books, int count) {
    int filter_year;
    printf("\n--- Filter Books by Year ---\n");
    printf("Enter publication year to filter: ");
    scanf("%d", &filter_year);
    clear_input_buffer();

    int found_count = 0;
    for (int i = 0; i < count; i++) {
        if (books[i].publication_year == filter_year) { // Match exact publication year
            display_book(&books[i]);
            found_count++;
        }
    }
    if (found_count == 0) {
        printf("No books found published in year %d.\n", filter_year);
    }
}