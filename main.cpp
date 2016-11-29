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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    FILE * pFile;
    char buffer [100];
    
    pFile = fopen ("myfile.txt" , "r");
    if (pFile == NULL) perror ("Error opening file");
/*    else
    {
        while ( ! feof (pFile) )
        {
            if ( fgets (buffer , 100 , pFile) == NULL ) break;
            fputs (buffer , stdout);
        }
 
    }*/
    
    fclose (pFile);
    
    //here's a difference

    return 0;
}

