#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 100

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf(" %[^\n]", library[bookCount].title);
        printf("Enter book author: ");
        scanf(" %[^\n]", library[bookCount].author);
        bookCount++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full!\n");
    }
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d: Title: %s, Author: %s\n", i + 1, library[i].title, library[i].author);
    }
}

void listBooksByAuthor() {
    char author[MAX_AUTHOR];
    printf("Enter author name: ");
    scanf(" %[^\n]", author);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].author, author) == 0) {
            printf("Title: %s\n", library[i].title);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by this author.\n");
    }
}

void countBooks() {
    printf("Total number of books in the library: %d\n", bookCount);
}

int main() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. List Books by Author\n");
        printf("4. Count Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                listBooksByAuthor();
                break;
            case 4:
                countBooks();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
