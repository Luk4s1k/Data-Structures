//
// Created by Luka Mitrović on 04/04/2021.
//

#ifndef SFMLTUTOR_STATE_H
#define SFMLTUTOR_STATE_H
namespace lm{
    class State{
    public:
        virtual void Init() = 0;

        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Draw (float dt) = 0;

        virtual void Pause() {}
        virtual void Resume() {}

    };
}

#endif //SFMLTUTOR_STATE_H
