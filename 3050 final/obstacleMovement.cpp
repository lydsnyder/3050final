//
//  obstacleMovement.cpp
//  3050 final
//
//  Created by Evan Teters on 11/28/16.
//  Copyright © 2016 Evan Teters. All rights reserved.
//




//Obstacles will have a var called speed and directionX directionY

//As well as a locationX and locationY

//So I will really just be called for both objects

//This assumes access to the board's double array, somehow.



#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include "classes.h"



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
