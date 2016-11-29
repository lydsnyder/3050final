//
//  classes.cpp
//  
//
//  Created by Lydia on 11/28/16.
//
//

#include <stdio.h>


//separate from Obstacle, because if obstacle hits wall it will change speeds... robot will not?
class Robot {
public:
    int locationX;
    int locationY; // Length of a box
    virtual public moveRobot(int RobotLocation, int obtacleLocation, Node** gameBoard);   // Height of a box
};

class Obstacle {
public:
    int locationX;
    int locationY; // Length of a box
    int speed;  // Breadth of a box
    int directionX;
    int directionY;
    virtual public moveObstacle(Node** gameBoard);   // Height of a box
};

class Exit {
    locationX;
    locationY;
};

class Node {
public:
    int horizontalFlag;
    int verticalFlag;
    char visualRepresentation; //vertical wall = | , horizontal wall = - , door = D, robot = 8, obstacle O
};
