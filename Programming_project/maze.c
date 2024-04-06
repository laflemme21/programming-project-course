#include <stdio.h>

// Define the Maze structure
typedef struct
{
    char grid[100][100];
    int row;
    int column;
} Maze;

// Define the Players coordinate variables

// Function prototypes
void load_maze(Maze *maze, const char *filename);
void display_maze(int x, int y, const Maze *maze);
void move_player(int x, int y, char direction);
int is_at_exit(int x, int y, Maze *maze);

// Function definitions
void load_maze(Maze *maze, const char *filename)
{
    // Stores the maze in a struct
    // initializes player coordinates
}

void move_player(int x, int y, char direction)
{
    // Move the player in the given direction if no wall or border is in the way
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

int main()
{
    int x;
    int y;
    char *filename;
    Maze *maze;
    char direction;
    load_maze(maze, filename);
    // runs until maze is solved
    while (is_at_exit(x, y, maze) == 0)
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