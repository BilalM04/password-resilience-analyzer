#include <stdio.h>
#include <string.h>

int hasLowercase(char password[]);
int hasUppercase(char password[]);
int hasDigit(char password[]);
int hasSpecialChar(char password[]);
char* evaluateStrength(char password[]);

int main() {
    char input[500];
    int choice = 0;
    char password[500];
    char c[500];

    while (choice != 3) {
        choice = 0;
        strcpy(input, "");

        printf("\nPassword Resilience Analyzer\n");
        printf("1. Test a new password\n");
        printf("2. View strength of the last tested password\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        fgets(input, 500, stdin);
        input[strlen(input) - 1] = '\0';

        if (strlen(input) == 1 && isdigit(input[0])) {
            choice = input[0] - '0';
        }

        if (choice == 1) {
            printf("Enter the password: ");
            fgets(password, 500, stdin);
            password[strlen(password) - 1] = '\0';

            if (strlen(password) < 8) {
                printf("Error: Password should be at least 8 characters long.\n");
                strcpy(password, "");
            } else {
                printf("Password strength: %s\n", evaluateStrength(password));
            }
        }
        else if (choice == 2) {
            if (password[0] == '\0') {
                printf("Error: no previous password.\n");
            } else {
                printf("Last tested password strength: %s\n", evaluateStrength(password));
            }
        }
        else if (choice == 3) {
            printf("Exiting...\n");
        } 
        else {
            printf("Error: invalid input, please enter '1', '2', or '3'\n");
        }
    }

    return 0;
}

int hasLowercase(char password[]) {
    int i;

    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }

    return 0;
}

int hasUppercase(char password[]) {
    int i;

    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }

    return 0;
}

int hasDigit(char password[]) {
    int i;

    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }

    return 0;
}

int hasSpecialChar(char password[]) {
    int i;

    for (i = 0; i < strlen(password); i++) {
        if (!isalpha(password[i]) && !isdigit(password[i])) {
            return 1;
        }
    }

    return 0;
}

char* evaluateStrength(char password[]) {
    char* result;
    int score = hasUppercase(password) + hasLowercase(password) + hasDigit(password) + hasSpecialChar(password);

    if (strlen(password) >= 12) {
        score += 1;
    }

    if (score <= 2) {
        result = "Weak";
    } else if(score >= 3 && score <= 4) {
        result = "Moderate";
    } else {
        result = "Strong";
    }

    return result;
}
