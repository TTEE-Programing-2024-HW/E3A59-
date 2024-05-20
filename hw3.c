#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define PASSWORD 2024
#define MAX_TRIES 3
#define ROWS 9
#define COLS 9

void WelcomeScreen();
int verifyPassword();
void displayMenu();
void showAvailableSeats(char seats[ROWS][COLS]);
void arrangeSeatsForYou(char seats[ROWS][COLS]);
void chooseSeatsByYourself(char seats[ROWS][COLS]);
void clearScreen();
void updateSeats(char seats[ROWS][COLS], int seatRow, int seatCol, char marker);
void initializeSeats(char seats[ROWS][COLS]);
void markRandomSeats(char seats[ROWS][COLS], int numSeats);
void displaySeats(char seats[ROWS][COLS]);

int main() {
    char seats[ROWS][COLS];
    char choice;
    int exitProgram = 0;

    initializeSeats(seats);
    markRandomSeats(seats, 10);

    WelcomeScreen();
    if (!verifyPassword()) {
        printf("Too many incorrect attempts. Exiting program.\n");
        printf("\a");
		return 0;
    }

    while (!exitProgram) {
        clearScreen();
        displayMenu();
        choice = getch();

        switch (choice) {
            case 'a':                        //a:  Available seats 
            case 'A':
                showAvailableSeats(seats);
                break;
            case 'b':						 //b:  Arrange for you
            case 'B': 
                arrangeSeatsForYou(seats);
                break;
            case 'c':   				     //c:  Choose by yourself                  
            case 'C': 
                chooseSeatsByYourself(seats);
                break;
            case 'd':
            case 'D': 
                printf("Continue? (y/n): ");
                char continueChoice = getch();
                if (continueChoice == 'n' ) {
                    exitProgram = 1;
                } else if (continueChoice != 'y' ) {
                    printf("\nInvalid input. Returning to menu.\n");
                }
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    printf("Program exited.\n");
    return 0;
}

void WelcomeScreen() {
    printf("5PPJJY77777!!~!!!!!YY?5555PPP5?J55Y5YY5YYYJ^JGPPP5\n"); //螢幕上出現個人風格的畫面
    printf("5PG?Y5YYY55YJJYY555YJ?J???JJYJ??JJJ????????^5PPPPP\n");
    printf("55GY5555PGBBBBBBBBBP??7777?JJJ??J??????????75P55JY\n");
    printf("YPJ?55Y55GGGGBBBBBBP?777777??J???777?7????7J555J7Y\n");
    printf("Y5JY5YYY5PGGGGBBGBBP?7YPJ?7?JYY?77!!7777777?555JJ5\n");
    printf("YYYYYYYYJYPGGGGBBBBG5PB###BGB#BGPYJ?7777777?555555\n");
    printf("YYYYYJYJJYPGB##B#########&&&#&####BGGPY?777755555Y\n");
    printf("YJJJ??JYPGB#&&&#&#&&&&&&&&&&&&#####B###B5?77??7777\n");
    printf("???7?5B##&##&&##&&&&&&&&&&&&&&#######BBBGG5JJYYY55\n");
    printf("777?P#&&&&&##&&#&&&#&&&&&&&&#&##B##B##BBBBBBGGPPPP\n");
    printf("???G###&&#######&&&#&&&&&&&&&##BB##B#BBBBBBBBBGPPP\n");
    printf("~!J########BPYYG#&######B#####BBB#BBBGGBGJPGBGGPPP\n");
    printf(".~G#&##&#P?J55?JB#BBBBBGGBBBBBBBBBBBBBBB5!?BGGGGP5\n");
    printf(":!BB#####Y7JY?P#BBBBBBBGBBB###BBBBGGGGB#Y!!PBBGGGP\n");
    printf(":7B#####BPGBBB##BBBBBBGBB#&####BBBBGGBB##Y?Y###GPP\n");
    printf(":Y#######&#B#BPPPPY??77YYYYJ?5GGGGB#BGGGGGG&&#BG5Y\n");
    printf(" ~G#####&#55PP5PP5!!7!7J7JGP!:?GGBGYYP5!^~7?G#PYYY\n");
    printf(".:5#####B5JPG5P55YJYBPPBGGBB?^?Y5#P5P##?~!!7JBG5YY\n");
    printf("^~JB#B##BP5YYJ?JYPP5PJG&#&&&BYY!!G&#&&&BY????G#B5Y\n");
    printf("^^^J5P5B#5YYY55Y5PBGPPP#BGB#PY?~^7PBB&&@BJJJYGBP5Y\n");
    printf("~~~~?5YGBYJJJJ5555Y5YPP55PPPJ?!!~^!YGGB#5YY5PBP~7!\n");
    printf("!!!!!YPGGYJJJ??YYPPPPPP5555YJ?7!^^^!5PGPY5PGGY!^~!\n");
    printf("!!!!!?YYP5YYJJJ??YYYYYYYJYYJ?JYJ???77JJY555J~^~~~!\n");
    printf("!!!!!!7JY5YJJJJ???J?JJ??7?Y5PGGGGGG5?7!7???!~~~7!7\n");
    printf("!!!!!!~!7YYJJJ?J?JJJ??7!!7????JYYJJ?!7?JJJ?~~7??Y7\n");
    printf("JJJJJ??JYYYYJJJ?JJ???7?J????JJJ?77??7??JJ?~~~!~!?!\n");
    printf("J?7??J77J??YYJJJJJ???JPGGGGGGGGPPGGGP5J??!:^7!: .^\n");
    printf("~~^~~?!^~!!7JYJJJJ?JJJJJYY55YYYYJYYYYYJ?~~^.~?~..^\n");
    printf("^~!~~!?~~!!~~JYYYYJYYJ????JY555555J?JJ?!!!!.^7~:.:\n");
    printf("~^^!~~J7~!~^^J5555YJYJJ??7??????7????!:^!?7.:7~^.:\n");
    printf("!^^~~!?J~~~^^J555555YYJJ?J??7?!77??7~~::~J?::!~^::\n");
    printf("7^^!~^!J7~~^^?5555PPPPP555YYYYYYY?!::~^:~JY!^~^:::\n");
    printf("7^~!~^^7?~~^^~5P5PPPPGGGGGGGGGPG~.:::~~:^?Y?~^^:::\n");
    printf("7~!!~^^~7!^~^^?GGPPPPGGGGGGGGGGJ..^::~!:^7YJ!^:::^\n");
    printf("!!!~~^^^~7~^~~~JGGGGGGGGGGGGGP?:::^::~!^^7YY!^^~~~\n");
    printf("!!!~~~^^~~!~~~~~75PPGGGGGGGPY!^::^^^:~!^^7YY7^^!~!\n");
    printf("~~!!!~^^~~~!~~~~~!JY55555Y?!~^::^^^^^!!^^?YY7::~!!\n");
    printf("^~~!!~~~^!~~~~~~~~!7???77!~^:::::^~^^!!^~?YJ!^:~!!\n");
    printf("^~~!!~~~^~?~~~~^^~~!!!!~^::.....:~~^^!!^~?JJ!^^~!!\n");
    printf("^^~!!~~~~^7J!~~~^^^~~^^:......:^~~~^^~~~~?J?!^^~7!\n");
    printf("^^~~~~~~~~~??77!!~~~^^::::.:^~!!!~^:^^!!~7?7~^^!?7\n");
    printf("Give Me Four Number:");
}

int verifyPassword() {        
    int inputPassword, tries = 0;

    while (tries < MAX_TRIES) {
        scanf("%d", &inputPassword);
        if (inputPassword == PASSWORD) {
            printf("Password correct. Welcome!\n");
            return 1;
        } else {
            tries++;
            if (tries < MAX_TRIES) {
                printf("Try again: ");
            }
        }
    }
    return 0;
}

void displayMenu() {
    printf("----------[Booking System]----------\n");
    printf("|  a. Available seats              |\n");
    printf("|  b. Arrange for you              |\n");
    printf("|  c. Choose by yourself           |\n");
    printf("|  d. Exit                         |\n");
    printf("------------------------------------\n");
}
void showAvailableSeats(char seats[ROWS][COLS]) {
    clearScreen();
    displaySeats(seats);
    printf("Press any key to return to the menu.\n");
    getch();
}

void arrangeSeatsForYou(char seats[ROWS][COLS]) {
    clearScreen();
    int seatsNeeded, i, j, found = 0;
    printf("How many seats do you need (1-4)? ");
    scanf("%d", &seatsNeeded);

    // Finding and marking seats
    if (seatsNeeded >= 1 && seatsNeeded <= 3) {
        for (i = 0; i < ROWS && !found; i++) {
            for (j = 0; j <= COLS - seatsNeeded; j++) {
                int k, empty = 1;
                for (k = 0; k < seatsNeeded; k++) {
                    if (seats[i][j + k] != '-') {
                        empty = 0;
                        break;
                    }
                }
                if (empty) {
                    for (k = 0; k < seatsNeeded; k++) {
                        seats[i][j + k] = '@';
                    }
                    found = 1;
                    break;
                }
            }
        }
    } else if (seatsNeeded == 4) {
        for (i = 0; i < ROWS - 1 && !found; i++) {
            for (j = 0; j <= COLS - 2; j++) {
                if (seats[i][j] == '-' && seats[i][j + 1] == '-' &&
                    seats[i + 1][j] == '-' && seats[i + 1][j + 1] == '-') {
                    seats[i][j] = seats[i][j + 1] = seats[i + 1][j] = seats[i + 1][j + 1] = '@';
                    found = 1;
                    break;
                }
            }
        }
    }
       displaySeats(seats);

    printf("Are you satisfied with the arrangement? (y/n): ");
    char satisfied = getch();
    if (satisfied == 'y') {
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (seats[i][j] == '@') {
                    seats[i][j] = '*';
                }
            }
        }
    } else {
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (seats[i][j] == '@') {
                    seats[i][j] = '-';
                }
            }
        }
    }
}

