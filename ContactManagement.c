#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char email[30];
    char phone_number[15];
} contact;

void addContact(contact** ptr, int* count);
void displayContact(contact* ptr, int count);
void searchContact(contact* ptr, int count, char* search);
void deleteContact(contact** ptr, int* cou, char* delete);

int main() {
    printf("\n\tContact Management System\n\n");

    unsigned int count = 0;
    printf("Enter the number of contacts: ");
    scanf("%i", &count);
    printf("\n");

    contact* ptr = (contact*)malloc(count * sizeof(contact));
    if (ptr == NULL) {
        return 0;
    }
    unsigned int cho = 1;
    for (int i = 0; i < count; ++i) {
        printf("Name: ");
        scanf("%s", (ptr + i)->name);
        printf("Number: ");
        scanf("%s", (ptr + i)->phone_number);
        printf("Email: ");
        scanf("%s", (ptr + i)->email);
        printf("\n");
    }

    do {
        unsigned int choice = 0;

        printf("1. Add new contact\n");
        printf("2. Display contact\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("... or enter 0 to exit\n");
        printf("Your choice: ");
        scanf("%i", &choice);

        switch (choice) {
        case 1:
            printf("\n");
            addContact(&ptr, &count);
            break;
        case 2:
            displayContact(ptr, count);
            break;
        case 3:
            char search[30];
            printf("\n");
            printf("Enter name: ");
            scanf("%s", search);
            printf("\n");
            searchContact(ptr, count, search);
            break;
        case 4:
            char delete[30];
            printf("Enter name: ");
            scanf("%s", delete);
            deleteContact(&ptr, &count, delete);
            break;
        case 0:
            return 0;
            break;
        default: 
            printf("\nUnknown command\n\n");
        }

        printf("Enter 1 to return to the menu or 0 to exit: ");
        scanf("%i", &cho);
        printf("\n");
    } while (cho == 1);

    free(ptr);
    ptr = NULL;
}

void addContact(contact** ptr, int* count) {
    *ptr = (contact*)realloc(*ptr, (*count + 1) * sizeof(contact));
    if (*ptr == NULL) {
        return;
    }

    printf("Name: ");
    scanf("%s", (*ptr + *count)->name);
    printf("Number: ");
    scanf("%s", (*ptr + *count)->phone_number);
    printf("Email: ");
    scanf("%s", (*ptr + *count)->email);
    ++(*count);
    printf("\n");
}

void displayContact(contact* ptr, int count) {
    printf("\n");
    for (int i = 0; i < count; ++i) {
        printf("Contact N°%d\n", i + 1);
        printf("Name: %s\n", (ptr + i)->name);
        printf("Number: %s\n", (ptr + i)->phone_number);
        printf("Email: %s\n", (ptr + i)->email);
        printf("\n");
    }
}

void searchContact(contact* ptr, int count, char* search) {
    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (strcmp((ptr + i)->name, search) == 0) {
            printf("Contact found\n");
            printf("Name: %s\n", (ptr + i)->name);
            printf("Number: %s\n", (ptr + i)->phone_number);
            printf("Email: %s\n", (ptr + i)->email);
            
            found = 1;  // Set found to true
            break;
        }
    }

    if (!found) {
        printf("Contact not found\n");
    }
    printf("\n");
}

void deleteContact(contact** ptr, int* cou, char* delete) {
    unsigned int result = 0;
    for (int i = 0; i < *cou; ++i) {
        if (strcmp((*ptr + i)->name, delete) == 0) {
            for (int j = i; j < *cou - 1; ++j) {
                strcpy((*ptr + j)->name, (*ptr + j + 1)->name);
                strcpy((*ptr + j)->phone_number, (*ptr + j + 1)->phone_number);
                strcpy((*ptr + j)->email, (*ptr + j + 1)->email);
            }
            break;
        }
    }

    *cou -= 1;
    *ptr = (contact*)realloc(*ptr, *cou * sizeof(contact));
    printf("\n");
}
