//
// Created by vanes on 11/18/2021.
//

#ifndef MAIN_CPP_STATES_H
#define MAIN_CPP_STATES_H
#include <map>
#include "StateName.h"

class States {
public:
    // Default constructor adds all states to the map and makes them false
    States();

    bool isOn(StateName state) const;
    void stateOn(StateName state);
    void stateOff(StateName state);

private:
    std::map<StateName, bool> states;
};


#endif //MAIN_CPP_STATES_H
