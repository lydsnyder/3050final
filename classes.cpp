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
    int location;   // Length of a box
    int speed;  // Breadth of a box
    int directionLeft;
    int directionRight;
    virtual public move(int RobotLocation, int obtacleLocation, Node** gameBoard);   // Height of a box
};

class Obstacle {
public:
    int location;   // Length of a box
    int speed;  // Breadth of a box
    int directionLeft;
    int directionRight;
    virtual public move(Node** gameBoard);   // Height of a box
};

class Node {
public:
    int NorthEdge;
    int NortheastEdge;
    int EastEdge;
    int SoutheastEdge;
    int SouthEdge;
    int SouthwestEdge;
    int WestEdge;
    int NorthwestEdge;
    int horizontalFlag;
    int verticalFlag;
};
