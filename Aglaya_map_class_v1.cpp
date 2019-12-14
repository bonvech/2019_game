#include <TXLib.h>
#include "map.h"


class Character
{
  public:
    Map &location;
    HDC DC;
    int x, y, a0, b0, a, b, dy, dx, k;
    COLORREF color;

    Character();
    ~Character();
    void Up();
    void Down();
    void Right();
    void Left();
    void Draw();
    void Delete();
    void Init();
    void Set_map(Map &mapp);
};


int main()
{
    txCreateWindow(800, 600);

    Map location;
    location.Draw();

    Character Boy;
    Boy.Set_map(location);
    //Boy.Init();

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        if(GetAsyncKeyState(VK_UP))
            Boy.Up();

        if(GetAsyncKeyState(VK_DOWN))
            Boy.Down();

        if(GetAsyncKeyState(VK_RIGHT))
            Boy.Right();

        if(GetAsyncKeyState(VK_LEFT))
            Boy.Left();

        txClear();
        location.Draw();
        Boy.Draw();
        txSleep(100);
    }

    return 0;
}


void Character::Up()
{
    if(location.Get_cell(x, y - dy) != 0)
    {
        y -= dy;
        b = b0 * 2 + 10;
        a += a0;
        if(a >= a0 * k)
            a = a0;
    }
}

void Character::Down()
{
    if(location.Get_cell(x, y + dy) != 0)
    {
        y += dy;
        b = b0 * 0;
        a += a0;
        if(a >= a0 * k)
            a = a0;
    }
}

void Character::Right()
{
    if(location.Get_cell(x + dx, y) != 0)
    {
        x += dx;
        b = b0 * 3 + 12;
        a += a0;
        if(a >= a0 * k)
            a = a0;
    }
}

void Character::Left()
{
    if(location.Get_cell(x - dx, y) != 0)
    {
        x -= dx;
        b = b0 * 1;
        a += a0;
        if(a >= a0 * k)
            a = a0;
    }

}

void Character::Draw()
{
    txTransparentBlt (txDC(), x, y, a0, b0, DC, a, b, color);
}

void Character::Delete()
{
    txDeleteDC(DC);
}

void Character::Init()
{
   *location = NULL;
   DC = txLoadImage("sprite_aglaya.bmp");
   x = 650;
   y = 380;
   a0 = 45;
   b0 = 94;
   a = 0;
   b = 0;
   dx = 10;
   dy = 10;
   k = 6;
   color = TX_WHITE;
}

Character::Character()
{
    Init();
}

Character::~Character()
{
    Delete();
}

void Character::Set_map(Map &mapp)
{
    location = mapp;
}
