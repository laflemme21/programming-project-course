#include "maze.h"

int main(int argc, char **argv){
    if(argc!=2){
        printf("No maze was given");
        exit(1);
    }
    Maze maze;
    Player player;
    char user_input[2];
    int exit=0;
    load_maze(&maze, argv[1]);
    prepare_game(&maze,&player);
    while (exit!=1)
    {   
        scanf("%c",user_input);
        if (user_input[0] == 'm' || user_input[0] == 'M')
        {
            display_maze(&maze, &player);
        }
        else if (user_input[0] == 'a' || user_input[0] == 'A' || user_input[0] == 's' || user_input[0] == 'S' || user_input[0] == 'd' || user_input[0] == 'D' || user_input[0] == 'W' || user_input[0] == 'w')
        {
            move_player(&maze, &player, user_input[0]);
        }
        else{
            printf("invalid input\n");
        }

        if(player.y==maze.end_row&&player.x==maze.end_column){
            exit=1;
        }
        else{
            exit=0;
        }
    }
    printf("You completed the maze!\n");
    display_maze(&maze, &player);
    return 0;
}