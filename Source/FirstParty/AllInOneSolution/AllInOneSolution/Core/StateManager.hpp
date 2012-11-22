#pragma once

#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include "State.hpp"

#include <memory> // unique_ptr
#include <vector>

/// This class is used to manage the diffrent states
class StateManager
{
public:

    StateManager();
    ~StateManager();

    void push(std::unique_ptr<State> state);

    void next();
    void prev();

    void draw();
    void update();

private:

    std::vector<std::unique_ptr<State>> m_states;
    unsigned int m_index;

};

#endif // STATE_MANAGER_HPP
