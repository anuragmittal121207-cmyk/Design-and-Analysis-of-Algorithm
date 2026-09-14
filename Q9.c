/*
Library Book Management
• Store the book ID, title, author, total copies, and available copies using structures.
• Create a menu-driven program to add and search for books, issue and return books, and display
all books currently unavailable.
*/

#include <stdio.h>

struct Book {
    int id, totalCopies, availCopies;
    char title[50], author[50];
};

int main() {
    struct Book b[50];
    int count = 0, choice, id, found;

    while(1) {
        printf("\n1.Add 2.Search 3.Issue 4.Return 5.Display Unavailable 6.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 6) break;

        if(choice == 1) {
            printf("Enter ID, Title, Author, Total Copies: ");
            scanf("%d %s %s %d", &b[count].id, b[count].title, b[count].author, &b[count].totalCopies);
            b[count].availCopies = b[count].totalCopies;
            count++;
        } else if(choice == 2) {
            printf("Enter Book ID: "); scanf("%d", &id);
            found = 0;
            for(int i = 0; i < count; i++) {
                if(b[i].id == id) {
                    printf("Found: %s | Available: %d/%d\n", b[i].title, b[i].availCopies, b[i].totalCopies);
                    found = 1; break;
                }
            }
            if(!found) printf("Book not found.\n");
        } else if(choice == 3) {
            printf("Enter Book ID: "); scanf("%d", &id);
            for(int i = 0; i < count; i++) {
                if(b[i].id == id && b[i].availCopies > 0) {
                    b[i].availCopies--;
                    printf("Book issued!\n");
                }
            }
        } else if(choice == 4) {
            printf("Enter Book ID: "); scanf("%d", &id);
            for(int i = 0; i < count; i++) {
                if(b[i].id == id && b[i].availCopies < b[i].totalCopies) {
                    b[i].availCopies++;
                    printf("Book returned!\n");
                }
            }
        } else if(choice == 5) {
            printf("Unavailable Books:\n");
            for(int i = 0; i < count; i++) {
                if(b[i].availCopies == 0) printf("ID: %d | Title: %s\n", b[i].id, b[i].title);
            }
        }
    }
    return 0;
}