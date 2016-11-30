//
//  classes.h
//  3050 final
//
//  Created by Evan Teters on 11/28/16.
//  Copyright © 2016 Evan Teters. All rights reserved.
//

#ifndef classes_h
#define classes_h
//
//  classes.cpp
//
//
//  Created by Lydia on 11/28/16.
//
//

#include <stdio.h>

class Node {
public:
    int horizontalFlag;
    int verticalFlag;
    char visualRepresentation; //vertical wall = | , horizontal wall = - , door = D, robot = 8, obstacle O
};


//separate from Obstacle, because if obstacle hits wall it will change speeds... robot will not?
class Robot {
public:
    int locationX;
    int locationY; // Length of a box
    void moveRobot(int RobotLocation, int obtacleLocation, Node** gameBoard);   // Height of a box
};

class Obstacle {
public:
    int locationX;
    int locationY; // Length of a box
    int speed;  // Breadth of a box
    int directionX;
    int directionY;
    void moveObstacle(Node** board);   // Height of a box
};

class Exit {
public:
    int locationX;
    int locationY;
};



#endif /* classes_h */
