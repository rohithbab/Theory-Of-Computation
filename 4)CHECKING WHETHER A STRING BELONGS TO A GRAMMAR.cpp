#include<stdio.h>
#include<string.h>

int main() {
    char s[100];
    int i, flag = 1;
    int l;
    
    printf("Enter a string to check: ");
    scanf("%s", s);
    l = strlen(s);
    
    for(i = 0; i < l; i++) {
        if(s[i] != '0' && s[i] != '1') {
            flag = 0;
            break;
        }
    }
    
    if(flag == 0) {
        printf("String is not valid\n");
    } else {
        int flag1 = 1;
        int a = 0, b = l - 1;
        
        while(a < b) {
            if(s[a] != s[b]) {
                flag1 = 0;
                break;
            }
            a++;
            b--;
        }
        
        if(flag1 == 1) {
            printf("The string is a palindrome\n");
            printf("String is accepted\n");
        } else {
            printf("The string is not a palindrome\n");
            printf("String is not accepted\n");
        }
    }
    
    return 0;
}
 