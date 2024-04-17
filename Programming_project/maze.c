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
    if(file==NULL){
        printf("could not open file");
        exit(100);
    }
    char char_from_file=getc(file);
    int row=0;
    int column=0;

    maze->end_column=-1;
    maze->end_row=-1;
    maze->start_column=-1;
    maze->start_row=-1;

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
        //counts total num of rows and resets num of columns
        else{
            char_from_file=getc(file);
            if(char_from_file!=EOF){
                column=0;
                row++;
            }
        }

        if(char_from_file=='S'){
            //checks if its the first time it enters
            if(maze->start_column!=-1){
                printf("Invalid maze, contains more than one strarting position S");
                exit(3);
            }
            maze->start_column=column;
            maze->start_row=row;
        }
        else if(char_from_file=='E'){
            //checks if its the first time it enters
            if(maze->end_column!=-1){
                printf("Invalid maze, contains more than one ending position E");
                exit(3);
            }
            maze->end_column=column;
            maze->end_row=row;
        }
        //checks for invalid chars
        else if(char_from_file!=' ' && char_from_file!='#' && char_from_file!='\n' && char_from_file!=EOF){
            
            printf("Invalid maze, invalid character %c found",char_from_file);
            exit(3);
        }
    }
    fclose(file);
    maze->total_columns=getline(0);
    maze->total_rows=row;
}

void prepare_game(Maze *maze, Player *player){
    if(maze->end_column==-1||maze->start_column==-1){
        printf("Invalid maze, missing starting S or ending E position");
        exit(3);
    }

    for(int i=0;i<maze->total_rows;i++){
        printf("%d",i);
        //checks if every line has the same length
        if(sizeof(maze->map[i])!=maze->total_columns && 
        //always true unless it's the last row of the maze, 
        //in this case if the row is empty the maze is considered valid
        ((i!=maze->total_rows-1) || sizeof(maze->map[i])!=0)){
            printf("Invalid maze, invalid maze size, the maze is not a rectangle");
            exit(3);
        }
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

    if(0<=next_row && next_row<=maze->total_rows){
        if(maze->map[next_row][player->x]==' '){
            player->y=next_row;
        }
        else{
            printf("You collided with a wall or border");
            exit(100);
        }
    }
    else if(0<=next_column && next_column<=maze->total_columns){
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
    Maze maze;
    Player player;
    char user_input='q';
    load_maze(&maze, argv[1], argc);
    prepare_game(&maze,&player);
    while (is_at_exit(&maze, &player))
    {
        if (user_input == 'm' || user_input == 'M')
        {
            display_maze(&maze, &player);
        }
        else if (user_input == 'a' || user_input == 'A' || user_input == 's' || user_input == 'S' || user_input == 'd' || user_input == 'D' || user_input == 'W' || user_input == 'w')
        {
            move_player(&maze, &player, user_input);
        }
    }
}