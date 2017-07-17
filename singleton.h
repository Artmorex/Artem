#ifndef SINGLETON_H
#define SINGLETON_H

#include <Widget.h>

class Game
{

public:

     void Run();

     static Game& Instance()
     {
         static Game theSingleInstance;
         return theSingleInstance;
     }

private:
    Game(){}
    Game(const Game& root);
    Game& operator = (const Game&);

    Widget widget;

};

#endif // SINGLETON_H
