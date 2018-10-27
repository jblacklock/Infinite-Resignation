#ifndef MENUSTATE_H
#define MENUSTATE_H


class MenuState
{
    public:
        MenuState() = default;
       virtual void update()=0;
       virtual void render()=0;
       virtual void handleEvent()=0;
};

#endif // MENUSTATE_H
