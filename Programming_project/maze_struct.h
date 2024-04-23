#ifndef MAZE_H
#define MAZE_H
#include "Player_struct.h"
#include <stdio.h>
#include <stdlib.h>
/**
* @file maze_struct.h
*
* @brief Implementation of the struct Maze of the maze project.
*
* @author @laflemme21
*/

/**
 * @brief Maze struct
 * 
 */
typedef struct
{
    int a;
    char map[100][100];
    int total_rows;
    int total_columns;
    int start_row;
    int start_column;
    int end_row;
    int end_column;
} Maze;

/**
 * @brief Set the up maze struct object
 * 
 * @param maze 
 */
void setup_maze_struct(Maze *maze){
    //assigned to an unatagnable value to know if it was already modified or not
    maze->end_column=-1;
    maze->end_row=-1;
    maze->start_column=-1;
    maze->start_row=-1;

    //assigned to unnatagnable value to know if it was already modified or not
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            maze->map[i][j]='\0';
        }
    }
}

void store_map(Maze *maze,char *filename){

    FILE* file=fopen(filename,"r");
    if(file==NULL){
        printf("could not open file");
        exit(2);
    }

    //first char stored at [0][0]
    char char_from_file=getc(file);
    int row=0;
    int column=0;

    
    while(char_from_file!=EOF){

        if(row>99||column>99){
            printf("Invalid maze, invalid maze size, the maze is too big");
            exit(3);
        }

        if(char_from_file!='\n'){
            maze->map[row][column]=char_from_file;
            column++;
            char_from_file=getc(file);
        }
        //counts total num of rows and resets num of columns except if the newline is the last of the file and is empty
        else{
            char_from_file=getc(file);
            if(char_from_file!=EOF){
                column=0;
                row++;
            }
        }

    }
    fclose(file);
    maze->total_columns=column;
    maze->total_rows=row+1;
}

void char_check_map(Maze *maze){
    for(int row=0;row<maze->total_rows;row++){
        for(int column=0;column<maze->total_columns;column++){

            if(maze->map[row][column]=='S'){
                //checks if its the first time it enters
                if(maze->start_column!=-1){
                    printf("Invalid maze, contains more than one strarting position S");
                    exit(3);
                }
                maze->start_column=column;
                maze->start_row=row;
            }
            else if(maze->map[row][column]=='E'){
                //checks if its the first time it enters
                if(maze->end_column!=-1){
                    printf("Invalid maze, contains more than one ending position E");
                    exit(3);
                }
                maze->end_column=column;
                maze->end_row=row;
            }
            //checks for invalid chars
            else if(maze->map[row][column]!=' ' && maze->map[row][column]!='#' && maze->map[row][column]!='\n' && maze->map[row][column]!='\0'){
                
                printf("Invalid maze, invalid character %c found",maze->map[row][column]);
                exit(3);
            }
        }
    }
}

void size_check_map(Maze *maze){
    
    if(maze->total_rows<5||maze->total_columns<5){
        printf("Invalid maze, invalid maze size, the maze is too small");
        exit(3);
    }
    if(maze->end_column==-1||maze->start_column==-1){
        printf("Invalid maze, missing starting S or ending E position");
        exit(3);
    }

    int num_of_char_in_row;
    for(int i=0;i<maze->total_rows+1;i++){
        num_of_char_in_row=0;

        //count num of chars in a row
        while(maze->map[i][num_of_char_in_row]!='\0' && num_of_char_in_row<100){
            num_of_char_in_row++;
        }

        //first checks if every line has the same length
        //and
        //second always true unless it's the last row of the maze, 
        //in this case only if the row is empty the maze is considered valid
        if((num_of_char_in_row!=maze->total_columns) && (i!=maze->total_rows || num_of_char_in_row!=0)){
            printf("Invalid maze, invalid maze size, the maze is not a rectangle");
            exit(3);
        }
    }
}

void display_maze(Maze *maze,Player *player)
{
    printf("\n");
    for(int row=0;row<maze->total_rows;row++){
        for(int column=0;column<maze->total_columns;column++){
            if(row==player->y && column==player->x){
                printf("X");
            }
            else{
                printf("%c",maze->map[row][column]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

#endif