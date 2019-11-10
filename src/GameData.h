#pragma once
#include "System.h"
#define MapHeight 20 //地图长定义
#define MapWidth 25  //地图宽定义
short Map[25][25];
struct Player //玩家信息定义
{
    char symbol;
    short attack;
    short direct;
    short health;
    short x;
    short y;
};
void MapPrint()
{
    for (short tmp = 0; tmp < MapWidth; tmp++)
    {
        Map[0][tmp] = '*';
        LocateWrite(0, tmp, '*');
    }
    for (short tmp = 1; tmp < MapHeight - 1; tmp++)
    {
        Map[tmp][0] = '*';
        LocateWrite(tmp, 0, '*');
        Map[tmp][MapWidth - 1] = '*';
        LocateWrite(tmp, MapWidth - 1, '*');
    }
    for (short tmp = 0; tmp < MapWidth; tmp++)
    {
        Map[MapHeight - 1][tmp] = '*';
        LocateWrite(MapHeight - 1, tmp, '*');
    }
}