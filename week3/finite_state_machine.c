#include <stdio.h>

typedef enum {
    IDLE,
    FILL,
    WASH,
    RINSE,
    SPIN
} State;

State current_state = IDLE;

void next_state() {
    switch(current_state) {
        case IDLE:
            current_state = FILL;
            break;
        case FILL:
            current_state = WASH;
            break;
        case WASH:
            current_state = RINSE;
            break;
        case RINSE:
            current_state = SPIN;
            break;
        case SPIN:
            current_state = IDLE;
            break;
    }
}

void print_state() {
    switch(current_state) {
        case IDLE: printf("IDLE\n"); break;
        case FILL: printf("FILL\n"); break;
        case WASH: printf("WASH\n"); break;
        case RINSE: printf("RINSE\n"); break;
        case SPIN: printf("SPIN\n"); break;
    }
}

int main() {
    for(int i = 0; i < 7; i++) {
        print_state();
        next_state();
    }
    return 0;
}