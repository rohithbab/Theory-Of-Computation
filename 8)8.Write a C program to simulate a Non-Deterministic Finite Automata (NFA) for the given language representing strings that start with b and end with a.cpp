#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 100

// NFA state
typedef struct {
    int transitions[2][MAX_STATES]; // 0 for 'a', 1 for 'b'
    bool is_final;
    int num_transitions[2];
} State;

// Initialize NFA
void initialize_nfa(State nfa[MAX_STATES], int *num_states) {
    // Initializing NFA with a sample structure for strings that start with 'b' and end with 'a'
    *num_states = 3;
    
    // State 0: Start state, on 'b' goes to state 1
    nfa[0].num_transitions[0] = 0; // no transitions for 'a'
    nfa[0].num_transitions[1] = 1; // one transition for 'b'
    nfa[0].transitions[1][0] = 1; // state 0 --b--> state 1
    nfa[0].is_final = false;
    
    // State 1: Intermediate state, can go to itself on 'a' or 'b', and to state 2 on 'a'
    nfa[1].num_transitions[0] = 2; // two transitions for 'a'
    nfa[1].num_transitions[1] = 1; // one transition for 'b'
    nfa[1].transitions[0][0] = 1; // state 1 --a--> state 1 (itself)
    nfa[1].transitions[0][1] = 2; // state 1 --a--> state 2
    nfa[1].transitions[1][0] = 1; // state 1 --b--> state 1 (itself)
    nfa[1].is_final = false;

    // State 2: Final state, can go to itself on 'a' or 'b'
    nfa[2].num_transitions[0] = 1; // one transition for 'a'
    nfa[2].num_transitions[1] = 1; // one transition for 'b'
    nfa[2].transitions[0][0] = 2; // state 2 --a--> state 2 (itself)
    nfa[2].transitions[1][0] = 2; // state 2 --b--> state 2 (itself)
    nfa[2].is_final = true;
}

// Function to check if a string is accepted by the NFA
bool is_accepted(State nfa[MAX_STATES], int current_state, char *input, int pos) {
    if (input[pos] == '\0') {
        return nfa[current_state].is_final;
    }

    int symbol = (input[pos] == 'a') ? 0 : 1;

    for (int i = 0; i < nfa[current_state].num_transitions[symbol]; i++) {
        if (is_accepted(nfa, nfa[current_state].transitions[symbol][i], input, pos + 1)) {
            return true;
        }
    }

    return false;
}

int main() {
    State nfa[MAX_STATES];
    int num_states;

    initialize_nfa(nfa, &num_states);

    char input[100];
    printf("Enter a string to check: ");
    scanf("%s", input);

    if (is_accepted(nfa, 0, input, 0)) {
        printf("String is accepted.\n");
    } else {
        printf("String is not accepted.\n");
    }

    return 0;
}
