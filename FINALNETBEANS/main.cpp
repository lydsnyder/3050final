//
//  main.cpp
//  3050 final
//
//  Created by Evan Teters on 11/28/16.
//  Copyright © 2016 Evan Teters. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include "classes.h"
//#include "constructors.cpp"

using namespace std;

int* parseFile(FILE* fp);


int main(int argc, const char * argv[]) {
    printf("In the beginning!\n");
    //Parsing would happen
    FILE * pFile;
    FILE* inputFile;
    int* numberArray;
    //char buffer [100];
    
    numberArray = (int*)malloc(sizeof(int) * 15);
    inputFile = fopen(argv[1], "r");
    if(!inputFile)
    {
        printf("poop\n");
        //Input file unable to be opened.
        return 0;
    }
    else
    {
        //Do shit with file.
        numberArray = parseFile(inputFile);
        for(int i = 0; i < 15; i++)
        {
            printf("%d\n", numberArray[i]);
        }
    }
    
    //fclose (pFile);
    //PARSING DONE !!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    Exit* exit= (Exit*)malloc(sizeof(Exit*) * 1);
    
    exit->exitConstructor(numberArray[1], numberArray[2]);
    
    Node** board ;//= boardConstructor(numberArray[0], exit);
    
   
    Obstacle* object1 = (Obstacle*)malloc(sizeof(Obstacle*) * 1); //= objectConstructor(numberArray[5], numberArray[6], numberArray[7], numberArray[8], numberArray[9]);
    
    object1->obstacleConstructor(numberArray[5], numberArray[6], numberArray[7], numberArray[8], numberArray[9]);
    
    
    
   // Obstacle* object2 = objectConstructor(numberArray[10], numberArray[11], numberArray[12], numberArray[13], numberArray[14]);
    
    
    Obstacle* object2 = (Obstacle*)malloc(sizeof(Obstacle*) * 1); //= objectConstructor(numberArray[5], numberArray[6], numberArray[7], numberArray[8], numberArray[9]);
    
    object2->obstacleConstructor(numberArray[10], numberArray[11], numberArray[12], numberArray[13], numberArray[14]);
    
    
    
    Robot* robo  = (Robot*)malloc(sizeof(Robot*) * 1); //robotConstructor(numberArray[1], numberArray[2]);
    
    robo->robotConstructor(numberArray[1], numberArray[2]);
    
    
    //Move :D
    
    
    
    
    int i=0;
    for(i=0;i<numberArray[0];i++) {
        
        int j=0;
        for(j=0;j<numberArray[0]; j++){
        
            printf("%c\n", board[j][i].visualRepresentation);
            
            
    }
    }
    
    fclose(pFile);
    printf("hello\n");
    return 0;
}
    
    
    
    
    
    
    
    
int* parseFile(FILE* fp)
    {
        char* line = NULL;
        char *p;
        size_t nbytes = 0;
        int linelen=0;
        unsigned int firstValue;
        unsigned int secondValue;
        //unsigned int thirdValue;
        int mallocSize;
        int* numberArray;
        int arraySlotCount = 0; /*Need to create this because we can't use count
                                 because count only increases once, but this one increases either once or twice. */
        int count = 0; //Used to count the amount of lines in the input file.
        mallocSize = 15; //Made 15 because there will always be 15 integers.
        numberArray = (int*)malloc(sizeof(int) * mallocSize);
        fseek(fp, 0, SEEK_SET);
        while ((linelen=getline(&line, &nbytes, fp)) != -1) {
            line[linelen-1] = '\0'; //removing the newline and adding the NULL character
            if(count == 0 || count == 4 || count == 7)
            {
                numberArray[arraySlotCount] = atoi(line);
                arraySlotCount++;
            }
            else
            {
                //Assign line to a pointer so that we can free line later without having to set the line back to the starting point.
                p = line;
                //First value will be left parentheses, skip over.
                p++;
                //Now, take in the number with strtol with base 10.
                firstValue = strtol(p, &p, 10);
                //Skip over the comma.
                p++;
                //Take in the second number with strtol as well.
                secondValue = strtol(p, &p, 10);
                numberArray[arraySlotCount] = firstValue;
                arraySlotCount++;
                numberArray[arraySlotCount] = secondValue;
                arraySlotCount++;
            }
            count++;
        }
        free(line);
        return numberArray;
    }
