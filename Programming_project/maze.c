#include <stdio.h>
#include <stdlib.h>

// Define the Maze structure
typedef struct
{
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

// Function prototypes
void load_maze(Maze *maze, const char *filename, int num_of_args);
void display_maze(int x, int y, const Maze *maze);
void move_player(Player *player, char direction);
int is_at_exit(int x, int y, Maze *maze);

// Function definitions
void load_maze(Maze *maze, const char *filename, int num_of_args){
    if(num_of_args==1){
        printf("No maze was given");
        exit(1);
    }
    FILE* file=fopen(filename,"r");
    char char_from_file=getc(file);
    int row=0;
    int column=0;

    maze->end_column=-1;
    maze->end_row=-1;
    maze->start_column=-1;
    maze->start_row=-1;

    while(char_from_file!=EOF){
        if(char_from_file!='\n'){
            maze->map[row][column]=char_from_file;
            column++;
            char_from_file=getc(file);
        }
        else{
            char_from_file=getc(file);
            if(char_from_file!=EOF){
                column=0;
                row++;
            }
        }

        if(char_from_file=='S'){
            maze->start_column=column;
            maze->start_row=row;
        }
        else if(char_from_file=='E'){
            maze->end_column=column;
            maze->end_row=row;
        }
    }
    maze->total_columns=column;
    maze->total_rows=row;
}
void prepare_game(Maze *maze, Player *player){
    if(maze->end_column==-1||maze->start_column==-1){
        printf("Invalid maze");
    }
}
void move_player(Player *player, char direction)
{
    int next_row=-1;
    int next_column=-1;
    if(direction=='W'){
        
    }
    else if(direction='A'){

    }
    else if(direction='S'){

    }
    else if(direction='D'){

    }
}
void display_maze(int x, int y, const Maze *maze)
{
    // Display the current state of the maze and position of player
}

int is_at_exit(int x, int y, Maze *maze)
{
    // Check if the player is at the exit of the maze
    // returns 0 if he's not at the exit
}

int main(int argc, char **argv)
{
    int x;
    int y;
    Maze *maze;
    Player *player;
    char direction;
    load_maze(maze, argv[1], argc);
    prepare_game(maze,player);
    // runs until maze is solved
    while (/*is_at_exit(x, y, maze) == 0*/0==1)
    {
        if (direction == 'm' || direction == 'M')
        {
            display_maze(x, y, maze);
        }
        else if (direction == 'a' || direction == 'A' || direction == 's' || direction == 'S' || direction == 'd' || direction == 'D' || direction == 'W' || direction == 'w')
        {
            move_player(x, y, direction);
        }
    }
}