
/*
    
    pa3.cpp
    Matthew Petela
    04/09/2018
    COP3503 Section: 1B02

*/

#include <fstream> //used to read in file
#include <string> //used for file 
#include <iostream> //used to get filename
#include <vector> //used for my own "stack"


#include "pa3.h" //Include the header file


std::string getFileName(){ //returns filename to open
    std::string fileName;
    std::cout<<"Please enter the name of the input file: ";
    std::cin>>fileName;
    return fileName;
}

void fileCanBeOpened(std::string codeFileName){ //checks to see if the file can be opened
    std::ifstream infile(codeFileName); //opens the file
    if (!infile) //checks to see if the file can be opened
    {
        std::cout<<"Error! The file could not be opened.\n"; //prints if file can't be opened
        infile.close(); //closes the file
        exit(0); //kills the program
    }
    infile.close(); //closes the file
}


int main(int agrc, char**argv){
    
    std::string codeFileName = getFileName(); //gets the name of the file
    fileCanBeOpened(codeFileName); //checks to see if the file can be opened
    
}