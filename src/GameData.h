#pragma once
#include "System.h"

#define MapHeight 20 //地图长定义
#define MapWidth 25  //地图宽定义
typedef enum _Direct_
{
    DOWN,
    LEFT,
    RIGHT,
    UP
} Direct;

short Map[25][25];

typedef struct _GameObject_
{
    char symbol;
    Direct direct;
    short attack;
    short health;
    short y;
    short x;
} Player; //玩家结构体定义

void Down(Player *player);
void InitMap();
void InitPlayer(Player *player, char symbol, Direct direct, short attack, short health, short y, short x);
void Left(Player *player);
void Right(Player *player);
void Up(Player *player);

void Down(Player *player)
{
    if (!Map[player->y + 1][player->x])
    {
        Map[player->y][player->x] = 0;
        LocateWrite(player->y++, player->x, ' ');
        Map[player->y][player->x] = player->symbol;
        LocateWrite(player->y, player->x, player->symbol);
    }
}
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
void InitPlayer(Player *player, char symbol, Direct direct, short attack, short health, short y, short x)
{
    player->symbol = symbol;
    player->attack = attack;
    player->direct = direct;
    player->health = health;
    player->x = x;
    player->y = y;
    LocateWrite(player->y, player->x, player->symbol);
}
void Left(Player *player)
{
    if (!Map[player->y][player->x - 1])
    {
        Map[player->y][player->x] = 0;
        LocateWrite(player->y, player->x--, ' ');
        Map[player->y][player->x] = player->symbol;
        LocateWrite(player->y, player->x, player->symbol);
    }
}
void Right(Player *player)
{
    if (!Map[player->y][player->x + 1])
    {
        Map[player->y][player->x] = 0;
        LocateWrite(player->y, player->x++, ' ');
        Map[player->y][player->x] = player->symbol;
        LocateWrite(player->y, player->x, player->symbol);
    }
}
void Up(Player *player)
{
    if (!Map[player->y - 1][player->x])
    {
        Map[player->y][player->x] = 0;
        LocateWrite(player->y--, player->x, ' ');
        Map[player->y][player->x] = player->symbol;
        LocateWrite(player->y, player->x, player->symbol);
    }
}