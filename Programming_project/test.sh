#!/bin/bash
EXECUTABLE="./maze"

gcc -g maze.c -o maze -Wall
echo -e "\n\n~~ Maze Tests ~~\n"

#Testing no arguments
echo -n "Test 1: Maze with no arguments 8"
$EXECUTABLE > tmp.txt
if grep -q "No maze was given" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi
: << 'c'
#makes sure code works with valid maze
echo -n "Test 2: Valid Maze 18"
$EXECUTABLE valid_maze.txt > tmp2.txt
#checks whether a file is empty
if [ -s tmp2.txt ];
then
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
else
    echo "   PASS"
fi
c
: << 'COMMENT'
#testing with invalid path
echo -n "Test 3: Invalid path 29"
$EXECUTABLE unexistantpath.txt > tmp.txt
if grep -q "Invalid path" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi
COMMENT
#testing with "Q" in the maze
echo -n "Test 4: Invalid character in maze (1) 39"
$EXECUTABLE invalidchar_1.txt > tmp.txt
if grep -q "Invalid maze, invalid char" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing with "5" in the maze
echo -n "Test 4: Invalid character in maze (2) 49"
$EXECUTABLE invalidchar_2.txt > tmp.txt
if grep -q "Invalid maze, invalid char" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing with "^" in the maze
echo -n "Test 4: Invalid character in maze (3)"
$EXECUTABLE invalidchar_3.txt > tmp.txt
if grep -q "Invalid maze, invalid char" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with no space
: << 'COMMENT'
echo -n "Test 5: Missing maze characteristic (1) 69"
$EXECUTABLE missingchar_1.txt > tmp.txt
if grep -q "Invalid maze" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi
COMMENT

#testing for maze with no \n
: << 'COMMENT'
echo -n "Test 5: Missing maze characteristic (2)79"
$EXECUTABLE missingchar_2.txt > tmp.txt
if grep -q "Invalid maze" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi
COMMENT

#testing for maze with no S
echo -n "Test 5: Missing maze characteristic (3)"
$EXECUTABLE missingchar_3.txt > tmp.txt
if grep -q "Invalid maze" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with no E
echo -n "Test 5: Missing maze characteristic (4) 99"
$EXECUTABLE missingchar_4.txt > tmp.txt
if grep -q "Invalid maze" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi
#testing for maze with more than one S
echo -n "Test 6: Too many maze characteristic (1) 108"
$EXECUTABLE multiplechar_1.txt > tmp.txt
if grep -q "Invalid maze" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with more than one E
echo -n "Test 6: Too many maze characteristic (2)"
$EXECUTABLE multiplechar_2.txt > tmp.txt
if grep -q "Invalid maze" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with less than 5 colomuns
echo -n "Test 7: Invalid Maze Size (1) 128"
$EXECUTABLE invalidsize_1.txt > tmp.txt
if grep -q "invalid maze size" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with less than 5 rows
echo -n "Test 7: Invalid Maze Size (2)"
$EXECUTABLE invalidsize_2.txt > tmp.txt
if grep -q "invalid maze size" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with more than 100 colomuns
echo -n "Test 7: Invalid Maze Size (3) 152"
$EXECUTABLE invalidsize_3.txt > tmp.txt
if grep -q "invalid maze size" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with more than 100 rows
echo -n "Test 7: Invalid Maze Size (4)"
$EXECUTABLE invalidsize_4.txt > tmp.txt
if grep -q "invalid maze size" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with a row with an extra #\n
echo -n "Test 8: Uneven Maze Size (1) 169"
$EXECUTABLE unevenmaze_1.txt > tmp.txt
if grep -q "invalid maze size" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with a row with an extra space
echo -n "Test 8: Uneven Maze Size (2)"
$EXECUTABLE unevenmaze_2.txt > tmp.txt
if grep -q "invalid maze size" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze with a row with a missing character
echo -n "Test 8: Uneven Maze Size (3) 187"
$EXECUTABLE unevenmaze_3.txt > tmp.txt
if grep -q "invalid maze size" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing the command m and M
echo -n "Test 9: printing the maze and starting position using M command 202"
$EXECUTABLE valid_maze.txt < M.txt > tmp.txt
if grep -q "#X######" tmp.txt && grep -q "#   #  #" tmp.txt && grep -q "#      #" tmp.txt && grep -q "#      E" tmp.txt && grep -q "########" tmp.txt && grep -q "#S######" tmp.txt && grep -q "#X  #  #" tmp.txt && grep -q "#      #" tmp.txt && grep -q "#      E" tmp.txt && grep -q "########" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi
#testing the command s and S
echo -n "Test 10: testing WASD and wasd command (S/s)207"
$EXECUTABLE valid_maze.txt < S.txt > tmp1.txt
if grep -q "#S######\n#X  #  #\n#      #\n#      E\n########\n\n#S######\n#   #  #\n#X     #\n#      E\n########" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi
rm -f tmp.txt

#testing the command d and D
echo -n "Test 10: testing WASD and wasd command (D/d)218"
$EXECUTABLE valid_maze.txt < D.txt > tmp.txt
if grep -q "#S######\n#   #  #\n# X    #\n#      E\n########\n\n#S######\n#   #  #\n#  X   #\n#      E\n########" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi


#testing the command a and A
echo -n "Test 10: testing WASD and wasd command (A/a)"
$EXECUTABLE valid_maze.txt < A.txt > tmp.txt
if grep -q "#S######\n#   #  #\n# X    #\n#      E\n########\n\n#S######\n#   #  #\n#X     #\n#      E\n########" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi


#testing the command w and W
echo -n "Test 10: testing WASD and wasd command (W/w)240"
$EXECUTABLE valid_maze.txt < W.txt > tmp.txt
if grep -q "#S######\n#X  #  \n#      #\n#      E\n########\n\n#X######\n#   #  #\n#      #\n#      E\n########" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing collision on the left
echo -n "Test 11: testing walls and border collision (1)"
$EXECUTABLE valid_maze.txt < wall_1.txt > tmp.txt
if grep -q "You collided with a wall or border" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing collision on the right
echo -n "Test 11: testing walls and border collision (2)260"
$EXECUTABLE valid_maze.txt < wall_2.txt > tmp.txt
if grep -q "You collided with a wall or border" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi


#testing collision on the top
echo -n "Test 11: testing walls and border collision (3)"
$EXECUTABLE valid_maze.txt < wall_3.txt > tmp.txt
if grep -q "You collided with a wall or border" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi


#testing collision on the bottom
echo -n "Test 11: testing walls and border collision (4)282"
$EXECUTABLE valid_maze.txt < wall_4.txt > tmp.txt
if grep -q "You collided with a wall or border" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for wrong input
echo -n "Test 12: wrong input 292"
$EXECUTABLE valid_maze.txt < wronginput.txt > tmp.txt
if grep -q "invalid input" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

#testing for maze completion
echo -n "Test 13: Maze completed 302"
$EXECUTABLE valid_maze.txt < valid_maze_input.txt > tmp.txt
if grep -q "You completed the maze" tmp.txt;
then
    echo "   PASS"
else
    echo "   FAILLLLLLLLLLLLLLLLLLLLLLLL"
fi

