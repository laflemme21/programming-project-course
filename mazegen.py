import random as random
import sys


def maze_gen(x, y):
    maze = []
    solution = []
    for i in range(0, y):
        maze.append([])
        for j in range(0, x):
            maze[i].append('#')

    Sx = random.randint(0, x-1)
    Sy = random.randint(0, y-1)
    maze[Sy][Sx] = 'S'
    Ex = random.randint(0, x-1)
    Ey = random.randint(0, y-1)
    maze[Ey][Ex] = 'E'

    Py = Sy
    Px = Sx
    while Py != Ey or Px != Ex:
        ''' while valid_move(maze, next_Px, next_Py):
             direction = 'W' '''
        direction = random.choice(['W', 'A', 'S', 'D'])
        if direction == 'W':
            if valid_move(maze, Px, Py-1):
                Py = Py - 1
                maze[Py][Px] = ' '
                solution.append(direction)

        elif direction == 'A':
            if valid_move(maze, Px-1, Py):
                Px = Px - 1
                maze[Py][Px] = ' '
                solution.append(direction)

        elif direction == 'S':
            if valid_move(maze, Px, Py+1):
                Py = Py+1
                maze[Py][Px] = ' '
                solution.append(direction)

        elif direction == 'D':
            if valid_move(maze, Px+1, Py):
                Px = Px+1
                maze[Py][Px] = ' '
                solution.append(direction)

    maze[Sy][Sx] = 'S'
    maze[Ey][Ex] = 'E'
    for i in range(0, y):
        print('')
        for j in range(0, x):
            print(maze[i][j], end='')
    print('')
    for i in range(0, len(solution)):
        print(solution[i], end='')


def valid_move(maze, x, y):
    if 0 <= y < len(maze) and 0 <= x < len(maze[0]):
        '''if maze[y][x] == ' ' :
            return True'''
        return True
    return False


x = random.randint(5, 100)
y = random.randint(5, 100)
maze_gen(x, y)
