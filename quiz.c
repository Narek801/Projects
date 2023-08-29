#include <stdio.h>

int main(int argc, char const *argv[])
{
    int start = 0;
    int score = 0;
    int answer1 = 0;
    int answer2 = 0;
    int answer3 = 0;
    int answer4 = 0;

    printf("Welcome to the quiz game! \n\n");

    printf("Enter 1 to start or 0 to exit: ");
    scanf("%d", &start);

    if (start == 1) {
        printf("\nThe game has started! \n");
    } else {
        return 0;
    } 

    printf("\n1/4 What is the capital of Armenia? \n\n1) Tbilisi \n2) Yerevan \n3) Tehran \n4) Kishinev \n");
    printf("Enter Your Answer (1 / 2 / 3 / 4): ");
    scanf("%d", &answer1);

    switch (answer1) {
        case 1: 
            printf("\nWrong answer! The capital of Armenia is Yerevan. \n");
            break;
        case 2: 
            printf("\nCorrect answer!\nYou have scored 5 point. \n");
            score += 5;
            break;
        case 3: 
            printf("\nWrong answer! The capital of Armenia is Yerevan. \n");
            break;
        case 4: 
            printf("\nWrong answer! The capital of Armenia is Yerevan. \n");
            break;
        }

    printf("\n2/4 When was Yerevan founded? \n\n1) 782 BC \n2) 1441 AD \n3) 1990 AD \n4) 650 BC \n");
    printf("Enter Your Answer: ");
    scanf("%d", &answer2);

    switch (answer2) {
        case 1:
            printf("\nCorrect answer!\nYou have scored 5 point. \n");
            score += 5;
            break;
        case 2:
            printf("\nWrong answer! Yerevan was founded in 782 BC.\n");
            break;
        case 3:
            printf("\nWrong answer! Yerevan was founded in 782 BC.\n");
            break;
        case 4:
            printf("\nWrong answer! Yerevan was founded in 782 BC. \n");
            break;
        }

    printf("\n3/4 Who made the plan of Yerevan? \n\n1) Jim Torosian \n2) Hovhannes Tumanian \n3) Alexander Tamanian \n4) Aslan Mkhitarian \n");
    printf("Enter Your Answer: ");
    scanf("%d", &answer3);

    switch (answer3) {
        case 1:
            printf("\nWrong answer! The plan of Yerevan was created by Alexander Tamanyan. \n");
            break;
        case 2:
            printf("\nWrong answer! The plan of Yerevan was created by Alexander Tamanyan. \n");
            break;
        case 3:
            printf("\nCorrect answer!\nYou have scored 5 point.\n");
            score += 5;
            break;
        case 4:
            printf("\nWrong answer! The plan of Yerevan was created by Alexander Tamanyan.\n");
            break;
        }

    printf("\n4/4 How many administrative districts are there in Yerevan?\n\n1) 7\n2) 11\n3) 9 \n4) 12\n");
    printf("Enter Your Answer: ");
    scanf("%d", &answer4);

    switch (answer4) {
        case 1:
            printf("\nWrong answer! Yerevan is divided into 12 administrative districts.");
            break;
        case 2:
            printf("\nWrong answer! Yerevan is divided into 12 administrative districts.");
            break;
        case 3: 
            printf("\nWrong answer! Yerevan is divided into 12 administrative districts.");
            break;
        case 4: 
            printf("\nCorrect answer! You have scored 5 points. \n\n");
            score += 5;
            break;
    }

    if (score == 20) {
        printf("Great! You scored 20 of 20․ Thanks for participating. \n");
    } else {
        printf("You scored %d. Better luck next time! \n", score);
    }
}
