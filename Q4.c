/*
Write a program to check whether a given string is a palindrome. Ignore spaces and differences
between uppercase and lowercase letters.
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[200], clean[200];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    int len = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalnum(str[i])) clean[len++] = tolower(str[i]);
    }

    int isPalindrome = 1;
    for(int i = 0; i < len / 2; i++) {
        if(clean[i] != clean[len - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome && len > 0) printf("It is a palindrome.\n");
    else printf("It is not a palindrome.\n");
    return 0;
}