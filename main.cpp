/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: evanteters
 *
 * Created on November 17, 2016, 5:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

int* parseFile(FILE* fp);

/*
 * 
 */
int main(int argc, char** argv) {
    
    FILE * pFile;
    FILE* inputFile;
    int* numberArray;
    char buffer [100];
    
    numberArray = (int*)malloc(sizeof(int) * 15);
    inputFile = fopen(argv[1], "r");
    if(!inputFile)
    {
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

    return 0;
}

int* parseFile(FILE* fp)
{
        char* line = NULL;
        char *p;
	size_t nbytes = 0;
        int i=0, linelen=0;
        unsigned int firstValue;
        unsigned int secondValue;
        unsigned int thirdValue;
        int mallocSize;
        int* numArray;
        int arraySlotCount = 0; /*Need to create this because we can't use count
        because count only increases once, but this one increases either once or twice. */
        int count = 0; //Used to count the amount of lines in the input file.
        mallocSize = 15; //Made 15 because there will always be 15 integers.
        numArray = (int*)malloc(sizeof(int) * mallocSize);
        fseek(fp, 0, SEEK_SET);
	while ((linelen=getline(&line, &nbytes, fp)) != -1) {
		line[linelen-1] = '\0'; //removing the newline and adding the NULL character
                if(count == 0 || count == 4 || count == 7)
                {
                    numArray[arraySlotCount] = atoi(line);
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
                    numArray[arraySlotCount] = firstValue;
                    arraySlotCount++;
                    numArray[arraySlotCount] = secondValue;
                    arraySlotCount++;
                }
                count++;
	}
	free(line);
        return numArray;
}

