#include <stdio.h>

typedef enum {
    STATE_OFF,
    STATE_ON_DIMMED,
    STATE_ON_MEDIUM,
    STATE_ON_BRIGHT
} State;

typedef enum {
    EVENT_SWITCH_ON,
    EVENT_SWITCH_OFF,
    EVENT_BRIGHTEN,
    EVENT_DIM
} Event;

State currentState = STATE_OFF;

void performAction(State state) {
    switch (state) {
        case STATE_OFF:
            printf("Light off\n");
            break;
        case STATE_ON_DIMMED:
            printf("Light on Dimmed\n");
            break;
        case STATE_ON_MEDIUM:
            printf("Light on Medium\n");
            break;
        case STATE_ON_BRIGHT:
            printf("Light on Bright\n");
            break;
        default:
            break;
    }
}

State transitionFunction(State currentState, Event event) {
    switch (currentState) {
        case STATE_OFF:
            if (event == EVENT_SWITCH_ON) {
                performAction(STATE_ON_DIMMED);
                return STATE_ON_DIMMED;
            }
            break;
        case STATE_ON_DIMMED:
            if (event == EVENT_SWITCH_OFF) {
                performAction(STATE_OFF);
                return STATE_OFF;
            } else if (event == EVENT_BRIGHTEN) {
                performAction(STATE_ON_MEDIUM);
                return STATE_ON_MEDIUM;
            } else if (event == EVENT_DIM) {
                performAction(STATE_OFF);
                return STATE_OFF;
            }
            break;
        case STATE_ON_MEDIUM:
            if (event == EVENT_SWITCH_OFF) {
                performAction(STATE_OFF);
                return STATE_OFF;
            } else if (event == EVENT_BRIGHTEN) {
                performAction(STATE_ON_BRIGHT);
                return STATE_ON_BRIGHT;
            } else if (event == EVENT_DIM) {
                performAction(STATE_ON_DIMMED);
                return STATE_ON_DIMMED;
            }
            break;
        case STATE_ON_BRIGHT:
            if (event == EVENT_SWITCH_OFF) {
                performAction(STATE_OFF);
                return STATE_OFF;
            } else if (event == EVENT_BRIGHTEN) {
                performAction(STATE_ON_BRIGHT);
            } else if (event == EVENT_DIM) {
                performAction(STATE_ON_MEDIUM);
                return STATE_ON_MEDIUM;
            }
            break;
        default:
            break;
    }
    return currentState;
}

int main() {
    Event events[] = {EVENT_SWITCH_ON, EVENT_BRIGHTEN, EVENT_DIM, EVENT_SWITCH_OFF};
    int numEvents = sizeof(events) / sizeof(events[0]);

    for (int i = 0; i < numEvents; i++) {
        currentState = transitionFunction(currentState, events[i]);
    }

    return 0;
}
