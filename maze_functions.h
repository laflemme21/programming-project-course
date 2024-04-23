#ifndef MAZE_FUNCTIONS_H
#include "maze_structs.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * @file maze_functions.h
 *
 * @brief All the functions of the maze project.
 *
 * @author @laflemme21
 */

/**
 * @brief Set the up maze struct object.
 *
 * @param maze maze object
 */
void setup_maze_struct(Maze *maze)
{
    // assigned to an unattainable value to know if it was already modified or not
    maze->end_column = -1;
    maze->end_row = -1;
    maze->start_column = -1;
    maze->start_row = -1;

    // assigned to null value to know if it was already modified or not
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            maze->map[i][j] = '\0';
        }
    }
}

/**
 * @brief Assigns starting values to the variables of the Player struct.
 *
 * @param maze Maze object
 * @param player Player object
 */
void setup_player(Maze *maze, Player *player)
{
    player->y = maze->start_row;
    player->x = maze->start_column;
}

/**
 * @brief Stores the maze file in the maze object.
 *
 * @param maze maze object
 * @param filename maze file
 */
void store_map(Maze *maze, char *filename)
{

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("could not open file");
        exit(2);
    }
    
    // first char stored at [row=0][column=0]
    char char_from_file = getc(file);
    int row = 0;
    int column = 0;

while(char_from_file!=EOF){
    if(char_from_file!='\n'){
        column++;
    }
    else{
        if(maze->total_columns < column){
            maze->total_columns = column;
        }
        row++;
        if(maze->total_rows < row){
            maze->total_rows = row;
        }
        column=0;
    }

}
maze->total_rows++;
row=0;
column=0;
    // loops till end of file
    while (char_from_file != EOF)
    {

        if (row > 99 || column > 99)
        {
            printf("Invalid maze, invalid maze size, the maze is too big");
            exit(3);
        }

        // stores all characters in the maze object
        if (char_from_file != '\n')
        {
            maze->map[row][column] = char_from_file;
            column++;
            char_from_file = getc(file);
        }
        // counts total num of rows and resets num of columns for each row
        else
        {
            char_from_file = getc(file);
            if (char_from_file != EOF)
            {
                column = 0;
                row++;
            }
        }
    }
    fclose(file);
}

/**
 * @brief Checks that the maze doesn't contain invalid chars.
 *
 * @param maze maze object
 */
void char_check_map(Maze *maze)
{
    // loops through the maze
    for (int row = 0; row < maze->total_rows; row++)
    {
        for (int column = 0; column < maze->total_columns; column++)
        {

            if (maze->map[row][column] == 'S')
            {
                // checks if its the first time Start is found
                if (maze->start_column != -1)
                {
                    printf("Invalid maze, contains more than one starting position S");
                    exit(3);
                }
                maze->start_column = column;
                maze->start_row = row;
            }
            else if (maze->map[row][column] == 'E')
            {
                // checks if its the first time End is found
                if (maze->end_column != -1)
                {
                    printf("Invalid maze, contains more than one ending position E");
                    exit(3);
                }
                maze->end_column = column;
                maze->end_row = row;
            }
            // checks for invalid chars
            else if (maze->map[row][column] != ' ' && maze->map[row][column] != '#' && maze->map[row][column] != '\n' && maze->map[row][column] != '\0')
            {

                printf("Invalid maze, invalid character %c found", maze->map[row][column]);
                exit(3);
            }
        }
    }
}

/**
 * @brief Checks that the size of the maze is valid.
 *
 * @param maze maze object
 */
void size_check_map(Maze *maze)
{

    if (maze->total_rows < 5 || maze->total_columns < 5)
    {
        printf("Invalid maze, invalid maze size, the maze is too small");
        exit(3);
    }

    // checks if starting and ending exists
    if (maze->end_column == -1 || maze->start_column == -1)
    {
        printf("Invalid maze, missing starting S or ending E position");
        exit(3);
    }

    int num_of_char_in_row;
    for (int row = 0; row < maze->total_rows + 1; row++)
    {
        num_of_char_in_row = 0;

        // count num of chars in a row
        while (maze->map[row][num_of_char_in_row] != '\0' && num_of_char_in_row < 100)
        {
            num_of_char_in_row++;
        }

        // first checks if every line has the same length
        // and
        // second always true unless it's the last row of the maze,
        // in this case only if the row is empty the maze is considered valid
        if ((num_of_char_in_row != maze->total_columns) && (row != maze->total_rows || num_of_char_in_row != 0))
        {
            printf("Invalid maze, invalid maze size, the maze is not a rectangle");
            exit(3);
        }
    }
}

/**
 * @brief Prints the maze and player on the terminal.
 *
 * @param maze maze object
 * @param player player object
 */
void display_maze(Maze *maze, Player *player)
{
    printf("\n");
    // loops through the maze and prints each char and the player
    for (int row = 0; row < maze->total_rows; row++)
    {
        for (int column = 0; column < maze->total_columns; column++)
        {
            if (row == player->y && column == player->x)
            {
                printf("X");
            }
            else
            {
                printf("%c", maze->map[row][column]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Moves the player on the maze in a certain direction.
 *
 * @param maze Maze object
 * @param player Player object
 * @param direction Direction of movement
 */
void move_player(Maze *maze, Player *player, char direction)
{
    // sets impossible values to know if they were altered
    int next_row = -2;
    int next_column = -2;

    if (direction == 'W' || direction == 'w')
    {
        next_row = player->y - 1;
    }
    else if (direction == 'A' || direction == 'a')
    {
        next_column = player->x - 1;
    }
    else if (direction == 'S' || direction == 's')
    {
        next_row = player->y + 1;
    }
    else if (direction == 'D' || direction == 'd')
    {
        next_column = player->x + 1;
    }

    // checks if player is not crossing maze boundaries
    if (0 <= next_row && next_row <= maze->total_rows)
    {   
        //checks if player is bumping in a wall
        if (maze->map[next_row][player->x] == ' ' || maze->map[next_row][player->x] == 'S' || maze->map[next_row][player->x] == 'E')
        {
            player->y = next_row;
        }
        else
        {
            printf("You collided with a wall or border\n");
        }
    }
    // checks if player is not crossing maze boundaries
    else if (0 <= next_column && next_column <= maze->total_columns)
    {
        //checks if player is bumping in a wall
        if (maze->map[player->y][next_column] == ' ' || maze->map[player->y][next_column] == 'S' || maze->map[player->y][next_column] == 'E')
        {
            player->x = next_column;
        }
        else
        {
            printf("You collided with a wall or border\n");
        }
    }
    // checks if player crossed the maze boundaries
    else if (next_column != -2 || next_row != -2)
    {
        printf("You collided with a wall or border\n");
    }
}

#endif