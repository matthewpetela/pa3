
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


int main(int agrc, char**argv){
    
    std::string codeFileName = getFileName();
    
    std::ifstream infile;
    infile.open(codeFileName);
    
    infile.close();
    
}