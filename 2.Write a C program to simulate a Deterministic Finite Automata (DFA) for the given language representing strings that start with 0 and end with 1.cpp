#include <stdio.h>
#include <string.h>

// DFA transition function
int transition(int state, char input) {
    switch(state) {
        case 0:
            if(input == '0')
                return 1;
            else
                return -1; // Invalid input
        case 1:
            if(input == '0')
                return 1;
            else if(input == '1')
                return 2;
            else
                return -1; // Invalid input
        case 2:
            if(input == '1')
                return 2;
            else
                return -1; // Invalid input
        default:
            return -1; // Invalid state
    }
}

// DFA simulation function
int isAccepted(char* str) {
    int currentState = 0;
    int i = 0;
    
    while(str[i] != '\0') {
        currentState = transition(currentState, str[i]);
        if(currentState == -1)
            return 0; // Input string rejected
        i++;
    }
    
    // Check if the final state is an accepting state
    return currentState == 2 ? 1 : 0;
}

int main() {
    char inputString[100];
    printf("Enter the string: ");
    scanf("%s", inputString);
    
    if(inputString[0] == '0' && inputString[strlen(inputString) - 1] == '1') {
        if(isAccepted(inputString))
            printf("String accepted\n");
        else
            printf("String rejected\n");
    } else {
        printf("String rejected\n");
    }
    
    return 0;
}
