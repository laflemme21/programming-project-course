#include "maze_functions.h"
#include "maze_structs.h"

int main(int argc, char **argv)
{
    //checking if args were given
    if (argc != 2)
    {
        printf("No maze was given");
        exit(1);
    }

    Maze maze;
    setup_maze_struct(&maze);

    char user_input[2];

    store_map(&maze, argv[1]);

    char_check_map(&maze);
    size_check_map(&maze);

    Player player;
    setup_player(&maze, &player);

    // true till the end of the program
    while (1)
    {
        scanf("%c", &user_input[0]);
        if (user_input[0] == 'm' || user_input[0] == 'M')
        {
            display_maze(&maze, &player);
        }
        //checking if player is trying to move
        else if (user_input[0] == 'a' || user_input[0] == 'A' || user_input[0] == 's' || user_input[0] == 'S' || user_input[0] == 'd' || user_input[0] == 'D' || user_input[0] == 'W' || user_input[0] == 'w')
        {
            move_player(&maze, &player, user_input[0]);
        }
        else if (user_input[0] != '\n')
        {
            printf("invalid input\n");
        }

        // checking if player is at the end of the maze
        if (player.y == maze.end_row && player.x == maze.end_column)
        {
            printf("You completed the maze!\n");
            display_maze(&maze, &player);
            // freeing the allocated memory
            for (int row = 0; row < maze.total_rows; row++)
            {
                free(maze.map[row]);
            }
            free(maze.map);
            return 0;
        }
    }
}