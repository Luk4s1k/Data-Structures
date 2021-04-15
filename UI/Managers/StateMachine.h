//
// Created by Luka Mitrović on 04/04/2021.
//

#ifndef SFMLTUTOR_STATEMACHINE_H
#define SFMLTUTOR_STATEMACHINE_H


#include <memory>
#include <stack>

#include "State.h"
namespace lm{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine{
    public:
        StateMachine(){}
        ~StateMachine(){}

        void AddState(StateRef newState, bool isReplacing = true);
        void RemoveState();

        void ProcessStateChanges();

        StateRef &GetActiveState();


    private:
        std::stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}

#endif //SFMLTUTOR_STATEMACHINE_H
