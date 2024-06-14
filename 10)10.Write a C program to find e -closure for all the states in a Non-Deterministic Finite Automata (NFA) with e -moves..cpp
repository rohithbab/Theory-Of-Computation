#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STATES 100

typedef struct {
    int epsilon_transitions[MAX_STATES];
    int num_epsilon_transitions;
} State;

void initialize_nfa(State nfa[MAX_STATES], int num_states) {
    // Initialize states with example e-transitions
    for (int i = 0; i < num_states; i++) {
        nfa[i].num_epsilon_transitions = 0;
    }

    // Example e-transitions (customize as needed)
    nfa[0].epsilon_transitions[nfa[0].num_epsilon_transitions++] = 1;
    nfa[1].epsilon_transitions[nfa[1].num_epsilon_transitions++] = 2;
    nfa[2].epsilon_transitions[nfa[2].num_epsilon_transitions++] = 0;
    nfa[2].epsilon_transitions[nfa[2].num_epsilon_transitions++] = 3;
    nfa[3].epsilon_transitions[nfa[3].num_epsilon_transitions++] = 3;
}

void epsilon_closure(State nfa[MAX_STATES], int num_states, int state, bool visited[MAX_STATES]) {
    if (visited[state]) {
        return;
    }
    visited[state] = true;

    for (int i = 0; i < nfa[state].num_epsilon_transitions; i++) {
        int next_state = nfa[state].epsilon_transitions[i];
        epsilon_closure(nfa, num_states, next_state, visited);
    }
}

void print_epsilon_closure(State nfa[MAX_STATES], int num_states) {
    for (int i = 0; i < num_states; i++) {
        bool visited[MAX_STATES] = {false};
        epsilon_closure(nfa, num_states, i, visited);

        printf("e-closure of state %d: {", i);
        bool first = true;
        for (int j = 0; j < num_states; j++) {
            if (visited[j]) {
                if (!first) {
                    printf(", ");
                }
                printf("%d", j);
                first = false;
            }
        }
        printf("}\n");
    }
}

int main() {
    State nfa[MAX_STATES];
    int num_states = 4;  // Example number of states

    initialize_nfa(nfa, num_states);

    print_epsilon_closure(nfa, num_states);

    return 0;
}
