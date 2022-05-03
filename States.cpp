//
// Created by vanes on 11/18/2021.
//

#include "States.h"

// Default constructor adds all states to the map and makes them false
States::States() {
    for (int i = 0; i < LAST; ++i)
        states[static_cast<StateName>(i)] = false;
}

bool States::isOn(StateName state) const {
    return states.at(state);
}
void States::stateOn(StateName state) {
    states[state] = true;
}
void States::stateOff(StateName state) {
    states[state] = false;
}