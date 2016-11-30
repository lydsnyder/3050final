/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   classes.h
 * Author: evanteters
 *
 * Created on November 29, 2016, 7:43 PM
 */

#ifndef CLASSES_H
#define CLASSES_H


#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include <stdio.h>
//#include "constructors.cpp"

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
    void robotConstructor(int x, int y);
    
};

class Obstacle {
public:
    int locationX;
    int locationY; // Length of a box
    int speed;  // Breadth of a box
    int directionX;
    int directionY;
    void moveObstacle(Node** board);   // Height of a box
    void obstacleConstructor(int locationX, int locationY, int speed, int directionX, int directionY);
    
};

class Exit {
public:
    int locationX;
    int locationY;
    void exitConstructor(int x, int y);
};



Node** boardConstructor(int dimensions, Exit* exit){
    
    //malloc values
    int i;
    int c;
    
    Node** board;
    
    // allocation
    board = new Node*[dimensions];
    for(int i = 0; i < dimensions; i++)
        board[i] = new Node[dimensions];
    
    // initialization
    for(int c = 0; c < dimensions; c++)
        for(int i = 0; i < dimensions; i++){
            board[i][c].horizontalFlag = 0;
            board[i][c].verticalFlag = 0;
            board[i][c].visualRepresentation = ' ';
        }
    
    //initialize values in Node,
    //(1,0) first component is N-S, second is E-W
    for(i = 1; i <= dimensions; i++){
        for(c = 1; c <= dimensions; c++){
            if(i == 1 || i == dimensions){
                board[i][c].horizontalFlag = 1;
                board[i][c].visualRepresentation = '-';
            }
            if(c == 1 || c == dimensions){
                board[i][c].verticalFlag = 1;
                board[i][c].visualRepresentation = '|';
            }
        }
    }
    
    
    board[exit->locationX][exit->locationY].visualRepresentation = 'D';
    
    return board;
    
}

void Obstacle::obstacleConstructor(int locationX, int locationY, int speed, int directionX, int directionY){
    
    //Obstacle* obj = (Obstacle*)malloc(sizeof(Obstacle*) * 1);
    
    
    //deleted obj -> on all lines
    locationX = locationX;
    locationY = locationY;
    directionX = directionX;
    directionY = directionY;
    speed = speed;
    
    //return obj;
    
    
}

void Robot::robotConstructor(int x, int y){
    
    //Robot* robo = (Robot*)malloc(sizeof(Robot*) * 1);
    
    locationX = x;
    locationY = y;
    
    //return robo;
}

void Exit::exitConstructor(int x, int y){
    
    //Exit* exit = (Exit*)malloc(sizeof(Exit*) * 1);
    
    locationX = x;
    locationY = y;
    
    //return exit; should not return a value
    
}

void Obstacle::moveObstacle(Node** board) {
    
          board[locationX][locationY].visualRepresentation = ' ';
   
    
    //Corner!
   
    int i=0;
    for (i=0; i<speed; i++){
        if (board[locationX][locationY].verticalFlag && board[locationX][locationY].horizontalFlag == 1 ) {
            
            directionX *= -1;
            directionY *= -1;
            
            board[locationX][locationY].visualRepresentation = '|';
            
        }
        
        //Vertical Edge!
        
        else if(board[locationX][locationY].verticalFlag == 1) {
            
            directionY *= -1;
            
              board[locationX][locationY].visualRepresentation = '|';
            
        }
        
        //Horizontal Edge!
        else if(board[locationX][locationY].horizontalFlag) {
            
            directionX *= -1;
            
              board[locationX][locationY].visualRepresentation = '-';
            
        }
        
       
        
        locationX = directionX*1 + locationX;
        locationY = directionY*1 + locationY;
        
        board[locationX][locationY].visualRepresentation = 'O';
        
    }
    
}

#endif /* CLASSES_H */

