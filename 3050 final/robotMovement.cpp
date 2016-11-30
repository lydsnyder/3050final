//
//  robotMovement.cpp
//
//
//  Created by fctech on 11/29/16.
//
//

#include <stdio.h>
#include "classes.h"

int flipFlag(int flag);

void moveRobot(Obstacle* obstacle1, Obstacle* obstacle2, Exit* door, Node** board, Robot* robot, int n){
    
    int Dx = door->locationX;
    int Dy = door->locationY;
    
    int Obs1x = obstacle1->locationX;
    int Obs1y = obstacle1->locationY;
    
    int Obs2x = obstacle2->locationX;
    int Obs2y = obstacle2->locationY;
    
    int xtemp = Dx;
    int ytemp = Dy;
    
    int flagx = 0; // -1 is subtract 1, 0 is equal, 1 is add 1
    int flagy = 0;
    
    //THIS IS A PLACEHOLDER!!! CHANGE THIS TO THE ACTUAL N WHEN POSSBILE!!!!!!!!!
    n = 10;
    
    if(robot->locationX == Dx){
        flagx = 0;
    }else if(robot->locationX < Dx){
        flagx = 1;
    }else if(robot->locationX < Dx){
        flagx = -1;
    }
    
    if(robot->locationY == Dy){
        flagy = 0;
    }else if(robot->locationY < Dy){
        flagy = 1;
    }else if(robot->locationY < Dy){
        flagx = -1;
    }
    
    xtemp += flagx;
    ytemp += flagy;
    
    //Check if the robot is at the space.
    
    if(flagx == 0 && flagy == 0)
    {
        //The robot wins!
    }
    
    //Move the robot diagonally, vertically, or horizontally.
    
    if(xtemp == Obs1x && ytemp == Obs1y) //Robot is trying to occupy the same space as the obstacle 1. Move the robot vertically instead.
    {
        if(Dx == Obs2x && Dy + flagy== Obs2y) //Robot is now trying to occupy the same space as the obstacle 2. Move the robot horizontally instead.
        {
            //Horizontal move
            if(xtemp < 1 || xtemp > n)
            {
                Dx = Dx + flipFlag(flagx);
            }
            else{
                Dx = Dx + flagx;
            }
            //Dy = Dy;
        }
        else{
            //Vertical move. Change y but not x.
            Dy = Dy + flagy;
        }
    }
    else if(xtemp == Obs2x && ytemp == Obs2y) //Means that robot is trying to move on top of obstacle 2.
    {
        if (Dx == Obs1x && Dy + flagy == Obs1y) {
            //Move robot horizontally towards goal.
            if(xtemp < 1 || xtemp > n)
            {
                //Need to flip the flag so it doesn't go over.
                Dx = Dx + flipFlag(flagx);
            }
            else
            {
                Dx = Dx + flagx;
            }
        } else {
            //Move robot vertically towards goal.
            Dy = Dy + flagy;
        }
    }
    else{
        //Move the robot diagonally.
        /*if(xtemp < 1 || xtemp > n) //Means that we're at the edge of the board. Just move y.
        {
            Dy = ytemp;
        }
        else if(ytemp < 1 || ytemp > n) //Means that we're at the edge of the board. Just move x.
        {
            Dx = xtemp;
        }*/
        //else{ //Both are fine, move the robot diagonally.
            Dx = xtemp;
            Dy = ytemp;
        //}
    }
    
    //Move the robot. Assign the values of Dx and Dy to the actual robot values.
    
    robot->locationX = Dx;
    robot->locationY = Dy;
    
    
}

//Used to flip horizontal flag.
int flipFlag(int flag)
{
    if(flag == -1)
    {
        flag = 1;
    }
    else
    {
        flag = -1;
    }
    return flag;
}

