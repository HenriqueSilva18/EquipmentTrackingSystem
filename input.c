#include <stdio.h>
#include <string.h>

#define INVALID_VALUE "The value entered is invalid."

void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int getInt(int min_value, int max_value, char *msg) {
    int value;
    printf(msg);
    while (scanf("%d", &value) != 1 || value < min_value || value > max_value) {
        puts(INVALID_VALUE);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return value;
}

void readString(char *string, unsigned int size, char *msg) {
    printf(msg);
    if (fgets(string, size, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}