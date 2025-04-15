#include <stdio.h>
#include <string.h>
#define MAX_CHAR 26 // 26 letters in the English alphabet

void findDuplicates(char str[]) {
    int count[MAX_CHAR] = {0}; // Array to hold counts for A-Z and a-z
    int i;

    // Count occurrences of each character (case insensitive)
    for (i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            count[c - 'A']++; // Count uppercase letters
        } else if (c >= 'a' && c <= 'z') {
            count[c - 'a']++; // Count lowercase letters
        }
    }

    // Print counts separately for upper and lower case
    printf("Duplicate characters:\n");
    for (i = 0; i < MAX_CHAR; i++) {
        if (count[i] > 1) {
            printf("%c appears %d times\n", i + 'a', count[i]); // Print lowercase
            printf("%c appears %d times\n", i + 'A', count[i]); // Print uppercase
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    findDuplicates(str);
    return 0;
}
