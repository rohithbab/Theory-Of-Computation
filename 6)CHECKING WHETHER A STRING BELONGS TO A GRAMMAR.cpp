#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, flag = 1, flag1 = 1, flag2 = 1;
    int l;

    printf("Enter a string to check: ");
    scanf("%99s", s);  // Use %99s to avoid buffer overflow
    l = strlen(s);

    // Check if the string contains only 0s and 1s
    for(i = 0; i < l; i++) {
        if(s[i] != '0' && s[i] != '1') {
            flag = 0;
            break;
        }
    }

    // If the string contains other characters, it's not valid
    if(flag != 1) {
        printf("String is not valid\n");
    } else {
        // If the length of the string is odd, it cannot satisfy the condition
        if(l % 2 != 0) {
            printf("The string does not satisfy the condition 0n1n\n");
            printf("String Not Accepted\n");
        } else {
            // Check if the first half contains only 0s
            for(i = 0; i < (l / 2); i++) {
                if(s[i] != '0') {
                    flag1 = 0;
                    break;
                }
            }
            // Check if the second half contains only 1s
            for(i = l / 2; i < l; i++) {
                if(s[i] != '1') {
                    flag2 = 0;
                    break;
                }
            }
            // If both halves satisfy their respective conditions, the string is accepted
            if(flag1 == 1 && flag2 == 1) {
                printf("The string satisfies the condition 0n1n\n");
                printf("String Accepted\n");
            } else {
                printf("The string does not satisfy the condition 0n1n\n");
                printf("String Not Accepted\n");
            }
        }
    }
    
    return 0;  // Return a value from main
}
