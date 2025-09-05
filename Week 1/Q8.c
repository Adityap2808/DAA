#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWords(const char str[]) {
    int count = 0, inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            if (!inWord) {
                count++;
                inWord = 1; // Start of a new word
            }
        } else {
            inWord = 0; // End of a word
        }
    }

    return count;
}

int main() {
    char str[200];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read the input string

    int wordCount = countWords(str);

    printf("Number of words in the string: %d\n", wordCount);

    return 0;
}