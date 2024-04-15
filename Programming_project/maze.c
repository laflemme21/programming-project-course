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
void load_maze(Maze *maze,char *filename, int num_of_args);
void display_maze(Maze *maze,Player *player);
void move_player(Maze *maze, Player *player, char direction);
int is_at_exit(Maze *maze, Player *player);

// Function definitions
void load_maze(Maze *maze,char *filename, int num_of_args){
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

void move_player(Maze *maze,Player *player, char direction)
{
    int next_row=-2;
    int next_column=-2;

    if(direction=='W'||direction=='w'){
        next_column=player->y-1;
    }
    else if(direction=='A'||direction=='a'){
        next_row=player->x-1;
    }
    else if(direction=='S'||direction=='s'){
        next_column=player->y+1;
    }
    else if(direction=='D'||direction=='d'){
        next_row=player->x+1;
    }
    else if(direction!='M'||direction!='m'){
        printf("Invalid input");
        exit(100);
    }

    if(0<=next_row<=maze->total_rows){
        if(maze->map[next_row][player->x]==' '){
            player->y=next_row;
        }
        else{
            printf("You collided with a wall or border");
            exit(100);
        }
    }
    else if(0<=next_column<=maze->total_columns){
        if(maze->map[player->y][next_column]==' '){
            player->x=next_column;
        }
        else{
            printf("You collided with a wall or border");
            exit(100);
        }
    }
    else if(next_column!=-2 || next_row!=-2){
        printf("You collided with a wall or border");
        exit(100);
    }
}
void display_maze(Maze *maze,Player *player)
{
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
}

int is_at_exit(Maze *maze, Player *player)
{
    if(player->y==maze->end_row&&player->x==maze->end_column){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char **argv)
{
    int x;
    int y;
    Maze *maze;
    Player *player;
    char user_input;
    load_maze(maze, argv[1], argc);
    prepare_game(maze,player);
    while (is_at_exit(maze, player))
    {
        if (user_input == 'm' || user_input == 'M')
        {
            display_maze(maze, player);
        }
        else if (user_input == 'a' || user_input == 'A' || user_input == 's' || user_input == 'S' || user_input == 'd' || user_input == 'D' || user_input == 'W' || user_input == 'w')
        {
            move_player(maze,player, user_input);
        }
    }
}