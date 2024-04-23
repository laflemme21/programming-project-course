#ifndef MAZE_STRUCTS_H
/**
 * @file maze_structs.h
 *
 * @brief The structs of the Maze project.
 *
 * @author @laflemme21
 */

/**
 * @brief Maze struct.
 *
 */
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

/**
 * @brief Player struct
 *
 */
typedef struct
{
    int x;
    int y;
} Player;
#endif