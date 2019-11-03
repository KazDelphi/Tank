#pragma once

#ifdef __linux__
#include <curses.h> //linux getch()头文件
#define linux
#elif _WIN32
#include <conio.h> //windows getch()头文件
#include <windows.h>
#define windows
#else
#error Non-Supported System.
#endif

#include <stdlib.h>

void Console(bool InitOrShutdown); //初始化:是,关闭:否.
void Locate(int x, int y);
void LocateWrite(int x, int y, char character);
#ifdef linux //检查系统.
void Console(bool InitOrShutdown)
{
    if (InitOrShutdown)
    {
        initscr();
    }
    else
    {
        endwin();
        exit(0);
    }
}
void Locate(int x, int y)
{
    move(y, x);
    refresh();
}
void LocateWrite(int x, int y, char character)
{
    mvaddch(y, x, character);
    refresh();
}
#elif windows
void Console(bool InitOrShutdown)
{
    if (InitOrShutdown)
    {
    }
    else
    {
        exit();
    }
}
void Locate(int x, int y)
{
    //COORD coord;
    //coord.X = x;
    //coord.Y = y;
    //...Uncomplete...
}
#endif