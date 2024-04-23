#ifndef PLAYER_STRUCT_H
#include "maze_struct.h"
/**
* @file Player_struct.h
*
* @brief Implementation of the struct Player of the maze project.
*
* @author @laflemme21
*/

/**
 * @brief Player struct
 * 
 */
typedef struct{
    int x;
    int y;
} Player;

/**
 * @brief Assigns starting values to the variables of the Player struct.
 * 
 * @param maze Maze object
 * @param player Player object
 */
void setup_player(Maze *maze, Player *player){
    player->y=maze->start_row;
    player->x=maze->start_column;
}

/**
 * @brief Moves the player on the maze in a certain direction.
 * 
 * @param maze Maze object
 * @param player Player object
 * @param direction Direction of movement
 */
void move_player(Maze *maze,Player *player, char direction)
{
    int next_row=-2;
    int next_column=-2;

    if(direction=='W'||direction=='w'){
        next_row=player->y-1;
    }
    else if(direction=='A'||direction=='a'){
        next_column=player->x-1;
    }
    else if(direction=='S'||direction=='s'){
        next_row=player->y+1;
    }
    else if(direction=='D'||direction=='d'){
        next_column=player->x+1;
    }

    if(0<=next_row && next_row<=maze->total_rows){
        if(maze->map[next_row][player->x]==' '||maze->map[next_row][player->x]=='S'||maze->map[next_row][player->x]=='E'){
            player->y=next_row;
        }
        else{
            printf("You collided with a wall or border\n");
        }
    }
    else if(0<=next_column && next_column<=maze->total_columns){
        if(maze->map[player->y][next_column]==' ' || maze->map[player->y][next_column]=='S' || maze->map[player->y][next_column]=='E'){
            player->x=next_column;
        }
        else{
            printf("You collided with a wall or border\n");
        }
    }
    else if(next_column!=-2 || next_row!=-2){
        printf("You collided with a wall or border\n");
    }
}

#endif