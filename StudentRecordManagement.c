#include <stdio.h> 
#include <stdlib.h>

typedef struct {
    char name[15];
    int id;
    int age;
    int marks[3];
} Student;

void addStudent(Student*, int);
void displayStudent(Student*, int);
void calculateAverage(Student*, int);
void calculateAverageAll(Student*, int);
void findHighestScoringStudent(Student*, int);

int main() {
    printf("\n\tWelcome to Student Record Management!\n\n");
    
    int size = 0;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    printf("\n");
    
    Student* ptr = (Student*)malloc(size*sizeof(Student));
    if (ptr == NULL) {
        return 0;
    }
    addStudent(ptr, size);
    displayStudent(ptr, size);

    int choice;
    do {
    int a = 0;
    printf("To see the student with the highest GPA, enter 1\nTo see a specific student's GPA, enter 2\nTo see the GPA of all student's, enter 3: ");
    scanf("%d", &a);
    if (a == 1) {
        findHighestScoringStudent(ptr, size);
        printf("\n\n");
    } else if (a == 2) {
        int index = 0;
        printf("\nEnter student's ID(You can check it above): ");
        scanf("%d", &index);
        calculateAverage(ptr, index);
    } else if (a == 3) {
        calculateAverageAll(ptr, size);
    } else {
        printf("\nUnknown command!\n\n");
    }
    printf("Enter 1 to run program again or 0 to exit: ");
    scanf("%d", &choice);
    printf("\n\n");
    } while (choice == 1);
    
    free(ptr);
    ptr = NULL;
}

void addStudent(Student* ptr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Student N°%d\n",i + 1);
        printf("Enter name: ");
        scanf("%s", (ptr + i)->name);
        printf("Enter age: ");
        scanf("%d", &(ptr + i)->age);
        printf("Enter marks: ");
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &(ptr + i)->marks[j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void displayStudent(Student* ptr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Student (ID)N°%d: ", i + 1);
        printf("\nName: %s\n", (ptr + i)->name);
        printf("Age: %d\n", (ptr + i)->age);
        printf("Marks: ");
        for (int j = 0; j < 3; ++j) {
            printf("%d ", (ptr + i)->marks[j]);
        }
        printf("\n\n");
    }
    printf("\n");
}

void calculateAverage(Student* ptr,int index) {
    int i = index - 1;
    int sum = 0;

    for (int j = 0; j < 3; ++j) {
        sum += ((ptr + i)->marks[j]);
    }
    printf("Average of student N°%d: %d\n\n", index, sum / 3);
}

void calculateAverageAll(Student* ptr, int size) {
    unsigned int result = 0;
    unsigned int sum = 0;
    printf("\n\tAverage mark\n\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum += (ptr + i)->marks[j];
        }
        result = sum/3;
        printf("Student N°%d: %d\n", i + 1, result);
        sum = 0;
        result = 0;
    } 
}

void findHighestScoringStudent(Student* ptr, int size) {
    int maxi = 0;
    int result = 0;
    for (int i = 0; i < size; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            sum += (ptr + i)->marks[j];
        }
        result = sum / 3;
        if (maxi < result) {
            maxi = i;
        }
    }
    printf("%s", (ptr + maxi)->name);
}
