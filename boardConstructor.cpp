//
//  boardConstructor.cpp
//  
//
//  Created by Lydia on 11/28/16.
//
//

#include "boardConstructor.hpp"

Node** boardConstructor(int dimensions, Exit exit){
    
    //malloc values
    int i;
    int c;
    
    Node** board  = (Node **)malloc(sizeof(Node *) * dimensions);
    Node* board[0] = (Node *)malloc(sizeof(Node) * dimensions * dimensions);
    
    for(i = 0; i < dimensions; i++){
        arr[i] = (*arr + dimensions * i);
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
    
    board[0][0].visualRepresentation = TOP LEFT CORNER;
    board[0][dimensions-1].visualRepresentation = '7';
    board[dimensions-1][dimensions-1].visualRepresentation = BOTTOM RIGHT CORNER;
    board[dimensions-1][0].visualRepresentation = 'L';
    board[exit.locationX][exit.locationY].visualRepresentation = 'D';
    
    return board;
    
}

Object* objectConstructor(int locationX, int locationY, int speed, int directionX, int directionY){
    
    Object* obj =(Object*)malloc(sizeof(Object*) * 1);
    
    obj.locationX = locationX;
    obj.locationY = locationY;
    obj.directionX = directionX;
    obj.directionY = directionY;
    obj.speed = speed;
    
    return obj;
    
    
}

Robot* robotConstructor(int x, int y){
    
    Robot* robo = (Robot*)malloc(sizeof(Robot*) * 1);
    
    robo.locationX = x;
    robo.locationY = y;
    
    return robo;
}

Exit* exitConstructor(int locationX, int locationY){
    
    Exit* exit = (Exit*)malloc(sizeof(Exit*) * 1);
    
    exit.locationX = x;
    exit.locationY = y;
    
    return exit;
    
}
