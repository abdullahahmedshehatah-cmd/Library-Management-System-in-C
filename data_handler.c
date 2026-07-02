#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data_handler.h"

// This array holds the hardcoded (pre-defined) book data for this version.
// This data will be loaded every time the program starts, instead of reading from a file.
Book hardcoded_books[] = {
    {1, "The Lord of the Rings", "J.R.R. Tolkien", 1954, 0},
    {2, "Pride and Prejudice", "Jane Austen", 1813, 0},
    {3, "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979, 0},
    {4, "1984", "George Orwell", 1949, 0},
    {5, "The Hobbit", "J.R.R. Tolkien", 1937, 0},
    {6, "Foundation", "Isaac Asimov", 1951, 0}
};

// The count of hardcoded books
int hardcoded_books_count = 6;

// Function to load books
// In this version, it loads hardcoded data instead of reading from a file.
int load_books(const char *filename, Book *books, int *count) {
    if (hardcoded_books_count > MAX_BOOKS) { // Check if hardcoded data exceeds library capacity
        *count = 0;
        return 0; // Indicate failure to load due to capacity
    }

    *count = hardcoded_books_count; // Set the current book count to the hardcoded count
    for (int i = 0; i < hardcoded_books_count; i++) {
        books[i] = hardcoded_books[i]; // Copy hardcoded books into the main library array
    }
    
    printf("Hardcoded books loaded successfully. Total books: %d\n", *count);
    return 1; // Indicate successful loading
}

// Function to save books
// In this version, it does not save to a file; data will be lost on program exit.
int save_books(const char *filename, const Book *books, int count) {
    printf("Changes are not saved to file in this version. Data will be reset on exit.\n");
    return 1; // Indicate successful (though non-persistent) saving
}