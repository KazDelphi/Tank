#pragma once

#ifdef linux
#include <curses.h> //linux getch()头文件
#elif _WIN32
#include <conio.h> //windows getch()头文件
#include <windows.h>
#define windows
#else
#error Non-Supported System.
#endif

#include <stdlib.h>

void Console(bool InitOrShutdown); //初始化:是,关闭:否.
void Locate(short y, short x);
void LocateWrite(short y, short x, char character);
void LocateWriteString(short y, short x, char *string);
#ifdef linux //检查系统.
void Console(bool InitOrShutdown)
{
    if (InitOrShutdown)
    {
        initscr();
        noecho();
    }
    else
    {
        endwin();
        exit(0);
    }
}
void Locate(short y, short x)
{
    move(y, x);
    refresh();
}
void LocateWrite(short y, short x, char character)
{
    mvaddch(y, x, character);
    refresh();
}
void LocateWriteString(short y, short x, char *string)
{
    mvprintw(y, x, "%s", string);
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
void Locate(short y, short x)
{
    //COORD coord;
    //coord.X = x;
    //coord.Y = y;
    //...Uncomplete...
}
#endif