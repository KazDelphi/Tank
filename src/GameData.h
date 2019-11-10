#pragma once
#include "System.h"

#define MapHeight 20 //地图长定义
#define MapWidth 25  //地图宽定义
typedef enum _Direct_
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direct;

short Map[25][25];

typedef struct _Player_
{
    char symbol;
    short attack;
    short direct;
    short health;
    short x;
    short y;
} Player; //玩家结构体定义
typedef struct _Bullet_
{
    char symbol;
    short attack;
    short direct;
    short x;
    short y;

} Bullet; //子弹结构体定义
void Down();
void InitMap();
void InitPlayer(Player *player, char symbol, short attack, short direct, short health, short x, short y);
void Left();
void Right();
void Up();

void InitMap()
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
void InitPlayer(Player *player, char symbol, short attack, short direct, short health, short x, short y)
{
    player->symbol = symbol;
    player->attack = attack;
    player->direct = direct;
    player->health = health;
    player->x = x;
    player->y = y;
    LocateWrite(player->y, player->x, player->symbol);
}