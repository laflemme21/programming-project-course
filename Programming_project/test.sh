#!/bin/bash
EXECUTABLE="./maze"

gcc maze.c -o maze
echo -e "\n\n~~ Maze Tests ~~"

#Testing no arguments
echo -n "Test 1: Maze with no arguments"
$EXECUTABLE > tmp1
if grep -q "No maze was given" tmp1;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#makes sure code works with valid maze
echo -n "Test 2: Valid Maze"
$EXECUTABLE valid_maze.txt > tmp
#checks whether a file is empty
if [ -s tmp ];
then
    echo "   FAIL"
else
    echo "   PASS"
fi

#testing with invalid path
echo -n "Test 3: Invalid path"
$EXECUTABLE unexistantpath.txt > tmp
if grep -q "Invalid path" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing with "Q" in the maze
echo -n "Test 4: Invalid character in maze (1)"
$EXECUTABLE invalidchar_1.txt > tmp
if grep -q "Invalid path" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing with "5" in the maze
echo -n "Test 4: Invalid character in maze (2)"
$EXECUTABLE invalidchar_2.txt > tmp
if grep -q "Invalid path" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing with "^" in the maze
echo -n "Test 4: Invalid character in maze (3)"
$EXECUTABLE invalidchar_3.txt > tmp
if grep -q "Invalid path" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with no space
echo -n "Test 5: Missing maze characteristic (1)"
$EXECUTABLE missingchar_1.txt > tmp
if grep -q "Invalid maze" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with no \n
echo -n "Test 5: Missing maze characteristic (2)"
$EXECUTABLE missingchar_2.txt > tmp
if grep -q "Invalid maze" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with no S
echo -n "Test 5: Missing maze characteristic (3)"
$EXECUTABLE missingchar_3.txt > tmp
if grep -q "Invalid maze" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with no E
echo -n "Test 5: Missing maze characteristic (4)"
$EXECUTABLE missingchar_4.txt > tmp
if grep -q "Invalid maze" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi
#testing for maze with more than one S
echo -n "Test 6: Too many maze characteristic (1)"
$EXECUTABLE multiplechar_1.txt > tmp
if grep -q "Invalid maze" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with more than one E
echo -n "Test 6: Too many maze characteristic (2)"
$EXECUTABLE multiplechar_2.txt > tmp
if grep -q "Invalid maze" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with less than 5 colomuns
echo -n "Test 7: Invalid Maze Size (1)"
$EXECUTABLE invalidsize_1.txt > tmp
if grep -q "Invalid maze size" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with less than 5 rows
echo -n "Test 7: Invalid Maze Size (2)"
$EXECUTABLE invalidsize_2.txt > tmp
if grep -q "Invalid maze size" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with more than 100 colomuns
echo -n "Test 7: Invalid Maze Size (3)"
$EXECUTABLE invalidsize_3.txt > tmp
if grep -q "Invalid maze size" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with more than 100 rows
echo -n "Test 7: Invalid Maze Size (4)"
$EXECUTABLE invalidsize_4.txt > tmp
if grep -q "Invalid maze size" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with a row with an extra #\necho -n "Test 8: Uneven Maze Size (1)"
$EXECUTABLE unevenmaze_1.txt > tmp
if grep -q "Invalid maze size" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with a row with an extra space
echo -n "Test 8: Uneven Maze Size (2)"
$EXECUTABLE unevenmaze_2.txt > tmp
if grep -q "Invalid maze size" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze with a row with a missing character
echo -n "Test 8: Uneven Maze Size (3)"
$EXECUTABLE unevenmaze_3.txt > tmp
if grep -q "Invalid maze size" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing the command m and M
echo -n "Test 9: printing the maze and starting position using M command"
$EXECUTABLE valid_maze.txt < M.txt > tmp
if grep -q "#S######\n#   X  #\n#      #\n#      E\n########\n\n#S######\n#   X  #\n#      #\n#      E\n########" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing the command s and S
echo -n "Test 10: testing WASD and wasd command (S/s)"
$EXECUTABLE valid_maze.txt < S.txt > tmp
if grep -q "#S######\n#X  #  #\n#      #\n#      E\n########\n\n#S######\n#   #  #\n#X     #\n#      E\n########" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi
rm -f tmp

#testing the command d and D
echo -n "Test 10: testing WASD and wasd command (D/d)"
$EXECUTABLE valid_maze.txt < D.txt > tmp
if grep -q "#S######\n#   #  #\n# X    #\n#      E\n########\n\n#S######\n#   #  #\n#  X   #\n#      E\n########" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi


#testing the command a and A
echo -n "Test 10: testing WASD and wasd command (A/a)"
$EXECUTABLE valid_maze.txt < A.txt > tmp
if grep -q "#S######\n#   #  #\n# X    #\n#      E\n########\n\n#S######\n#   #  #\n#X     #\n#      E\n########" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi


#testing the command w and W
echo -n "Test 10: testing WASD and wasd command (W/w)"
$EXECUTABLE valid_maze.txt < W.txt > tmp
if grep -q "#S######\n#X  #  \n#      #\n#      E\n########\n\n#X######\n#   #  #\n#      #\n#      E\n########" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing collision on the left
echo -n "Test 11: testing walls and border collision (1)"
$EXECUTABLE valid_maze.txt < wall_1.txt > tmp
if grep -q "You collided with a wall or border" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing collision on the right
echo -n "Test 11: testing walls and border collision (2)"
$EXECUTABLE valid_maze.txt < wall_2.txt > tmp
if grep -q "You collided with a wall or border" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi


#testing collision on the top
echo -n "Test 11: testing walls and border collision (3)"
$EXECUTABLE valid_maze.txt < wall_3.txt > tmp
if grep -q "You collided with a wall or border" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi


#testing collision on the bottom
echo -n "Test 11: testing walls and border collision (4)"
$EXECUTABLE valid_maze.txt < wall_4.txt > tmp
if grep -q "You collided with a wall or border" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for wrong input
echo -n "Test 12: wrong input"
$EXECUTABLE valid_maze.txt < wronginput.txt > tmp
if grep -q "Wrong input" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

#testing for maze completion
echo -n "Test 13: Maze completed"
$EXECUTABLE valid_maze.txt < valid_maze_input.txt > tmp
if grep -q "You completed the maze" tmp;
then
    echo "   PASS"
else
    echo "   FAIL"
fi

