#ifndef MAZE_H
#define MAZE_H
#include <stdio.h>
#include <stdlib.h>


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

typedef struct{
    int x;
    int y;
} Player;
void setup_maze_struct(Maze *maze){
    //assigned to an unnatagnable value to know if it was already modified or not
    maze->end_column=-1;
    maze->end_row=-1;
    maze->start_column=-1;
    maze->start_row=-1;

    //assigned to unnatagnable value to know if it was already modified or not
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            maze->map[i][j]='N';
        }
    }
}
void setup_player(Player *player){}

void check_map(Maze *maze){
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
            else if(maze->map[row][column]!=' ' && maze->map[row][column]!='#' && maze->map[row][column]!='\n' && maze->map[row][column]!=EOF){
                
                printf("Invalid maze, invalid character %c found",maze->map[row][column]);
                exit(3);
            }
        }
    }
}
void load_map(Maze *maze,char *filename){

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

// Function definitions
void load_maze(Maze *maze,char *filename){
    setup_maze_struct(maze);
    load_map(maze,filename);
    check_map(maze);

}

void prepare_game(Maze *maze, Player *player){

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
        while(maze->map[i][num_of_char_in_row]!='N' && num_of_char_in_row<100){
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

    player->y=maze->start_row;
    player->x=maze->start_column;
}

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
    else if(direction!='M'||direction!='m'){
        printf("Invalid input");
        exit(100);
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
void display_maze(Maze *maze,Player *player)
{
    printf("\n");
    for(int i=0;i<maze->total_rows;i++){
        for(int j=0;j<maze->total_columns;j++){
            if(i==player->y&&j==player->x){
                printf("X");
            }
            else{
                printf("%c",maze->map[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

#endif