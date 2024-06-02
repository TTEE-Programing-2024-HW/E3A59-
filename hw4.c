#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10
#define PASSWORD 2024
#define ATTEMPTS 3

typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void clearScreen();
void displayWelcomeMessage();
void enterStudentGrades();
void displayStudentGrades();
void searchStudentGrades();
void gradeRanking();
void exitSystem();
float calculateAverage(int, int, int);
void sortStudentsByAverage();
int stringCompare(const char*, const char*);
void stringCopy(char*, const char*);

int main() {
    int password;
    int attempts = 0;

    // Display personalized screen
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

    // Password prompt
    while (attempts < ATTEMPTS) {
        printf("Please enter the 4-digit password: ");
        scanf("%d", &password);
        if (password == PASSWORD) {
            displayWelcomeMessage();
            break;
        } else {
            printf("Incorrect password. Try again.\n");
            attempts++;
        }
    }

    if (attempts == ATTEMPTS) {
        printf("Too many incorrect attempts. Exiting program.\n");
        return 0;
    }

    // Main menu loop
    char choice;
    while (1) {
        clearScreen();
        printf("------------[Grade System]----------\n");
        printf("|  a. Enter student grades          |\n");
        printf("|  b. Display student grades        |\n");
        printf("|  c. Search for student grades     |\n");
        printf("|  d. Grade ranking                 |\n");
        printf("|  e. Exit system                   |\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                enterStudentGrades();
                break;
            case 'b':
                displayStudentGrades();
                break;
            case 'c':
                searchStudentGrades();
                break;
            case 'd':
                gradeRanking();
                break;
            case 'e':
                exitSystem();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

void clearScreen() {
    system("clear || cls");
}

void displayWelcomeMessage() {
    printf("Welcome to the Grade System!\n");
}

void enterStudentGrades() {
    clearScreen();
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    int n;
    printf("Enter the number of students (5-10): ");
    while (scanf("%d", &n) != 1 || n < 5 || n > 10 || (studentCount + n) > MAX_STUDENTS) {
        printf("Invalid number. Please enter a number between 5 and 10: ");
        while (getchar() != '\n'); // clear buffer
    }

    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d\n", studentCount + 1);
        printf("Name: ");
        scanf("%s", students[studentCount].name);
        printf("ID (6 digits): ");
        while (scanf("%d", &students[studentCount].id) != 1 || students[studentCount].id < 100000 || students[studentCount].id > 999999) {
            printf("Invalid ID. Please enter a 6-digit ID: ");
            while (getchar() != '\n'); // clear buffer
        }
        printf("Math score (0-100): ");
        while (scanf("%d", &students[studentCount].math) != 1 || students[studentCount].math < 0 || students[studentCount].math > 100) {
            printf("Invalid score. Please enter a score between 0 and 100: ");
            while (getchar() != '\n'); // clear buffer
        }
        printf("Physics score (0-100): ");
        while (scanf("%d", &students[studentCount].physics) != 1 || students[studentCount].physics < 0 || students[studentCount].physics > 100) {
            printf("Invalid score. Please enter a score between 0 and 100: ");
            while (getchar() != '\n'); // clear buffer
        }
        printf("English score (0-100): ");
        while (scanf("%d", &students[studentCount].english) != 1 || students[studentCount].english < 0 || students[studentCount].english > 100) {
            printf("Invalid score. Please enter a score between 0 and 100: ");
            while (getchar() != '\n'); // clear buffer
        }

        students[studentCount].average = calculateAverage(students[studentCount].math, students[studentCount].physics, students[studentCount].english);
        studentCount++;
    }

    printf("Students added successfully.\n");
}

void displayStudentGrades() {
    clearScreen();
    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s, ID: %d, Math: %d, Physics: %d, English: %d, Average: %.1f\n",
               students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }
    printf("Press any key to return to the main menu...\n");
    getchar();
    getchar();
}

void searchStudentGrades() {
    clearScreen();
    char searchName[50];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < studentCount; i++) {
        if (stringCompare(students[i].name, searchName) == 0) {
            printf("Name: %s, ID: %d, Math: %d, Physics: %d, English: %d, Average: %.1f\n",
                   students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
            printf("Press any key to return to the main menu...\n");
            getchar();
            getchar();
            return;
        }
    }
    printf("Student not found. Press any key to return to the main menu...\n");
    getchar();
    getchar();
}

void gradeRanking() {
    clearScreen();
    sortStudentsByAverage();
    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s, ID: %d, Average: %.1f\n",
               students[i].name, students[i].id, students[i].average);
    }
    printf("Press any key to return to the main menu...\n");
    getchar();
    getchar();
}

void exitSystem() {
    char confirm;
    printf("Are you sure you want to exit? (y/n): ");
    while (1) {
        scanf(" %c", &confirm);
        if (confirm == 'y') {
            printf("Exiting system...\n");
            exit(0);
        } else if (confirm == 'n') {
            return;
        } else {
            printf("Invalid input. Please enter 'y' or 'n': ");
        }
    }
}

float calculateAverage(int math, int physics, int english) {
    return (math + physics + english) / 3.0;
}

void sortStudentsByAverage() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (students[i].average < students[j].average) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int stringCompare(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

void stringCopy(char* dest, const char* src) {
    while ((*dest++ = *src++));
}

