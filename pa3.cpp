
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
#include <iterator> //ostream_iterator which is used for testing purposes to print the vectors
#include <algorithm> //used for std::remove
#include <sstream> //used for stringstream


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

std::vector<std::string> fileVectorOpen(std::string codeFileName){ //opens the file and stores it as a vector
    std::string currentLine;
    std::vector<std::string> vectorOpen; //declares the vector
    std::ifstream infile(codeFileName); //opens the file
    while (std::getline(infile, currentLine)){
        vectorOpen.push_back(currentLine);
    }
    return vectorOpen;    
}

std::vector<std::string> removeSpaces(std::vector<std::string> vectorOpen){ //removes spaces from the vector

    int currentVectorSize = vectorOpen.size();
    for (int i = 0; i < currentVectorSize; i++){
        //std::cout<<vectorOpen.at(i); //used for print testing purposes
        vectorOpen.at(i).erase(remove(vectorOpen.at(i).begin(), vectorOpen.at(i).end(), ' '), vectorOpen.at(i).end());
    }
    
    return vectorOpen;
}

std::vector<std::string> properSplit(std::vector<std::string> vectorRemoved){
    int commaNumb = 0;
    int parathesisNumbL = 0;
    int parathesisNumbR = 0;
    int equalNumb= 0;
    int currentVectorSize = vectorRemoved.size();
    std::vector<std::string> vectorProperSplit;
    for (int i = 0; i < currentVectorSize; i++){
        std::string ppString = vectorRemoved.at(i);
        std::stringstream pp(ppString);
        while (pp.good()){
            std::string curString;
            getline(pp, curString, '(');
            vectorProperSplit.push_back(curString);
            parathesisNumbR++;
            
        }
        
    }
   
   
    currentVectorSize = vectorRemoved.size();
    for (int i = 0; i < currentVectorSize; i++){
        std::string ppString = vectorRemoved.at(i);
        std::stringstream pp(ppString);
        while (pp.good()){
            std::string curString;
            getline(pp, curString, ')');
            vectorProperSplit.push_back(curString);
            parathesisNumbL++;
            
        }
    }
    currentVectorSize = vectorRemoved.size();
    for (int i = 0; i < currentVectorSize; i++){
        std::string ppString = vectorRemoved.at(i);
        std::stringstream pp(ppString);
        while (pp.good()){
            std::string curString;
            getline(pp, curString, ',');
            vectorProperSplit.push_back(curString);
            commaNumb++;
            
        }
    }
    currentVectorSize = vectorRemoved.size();
    for (int i = 0; i < currentVectorSize; i++){
        std::string ppString = vectorRemoved.at(i);
        std::stringstream pp(ppString);
        while (pp.good()){
            std::string curString;
            getline(pp, curString, '=');
            vectorProperSplit.push_back(curString);
            equalNumb++;
            
        }
    }
    
    
    
    std::copy(vectorProperSplit.begin(), vectorProperSplit.end(), std::ostream_iterator<std::string>(std::cout, "/*/")); //testing purposes to print the vector
    return vectorProperSplit;
}


void CodeClass::setAllWords(std::vector<std::string> finalVector){
    for (int i = 0; i < finalVector.size(); i++){
        std::string current = finalVector.back();
        if (current.compare("BEGIN") || current.compare("END") || current.compare("FOR")){
            keywords.push_back(current);
            finalVector.pop_back();
        }
    }
    std::vector<std::string> vectorProperSplit = properSplit(finalVector);
    finalVector.clear();
}


int main(int agrc, char**argv){
    
    std::string codeFileName = getFileName(); //gets the name of the file
    fileCanBeOpened(codeFileName); //checks to see if the file can be opened
    std::vector<std::string> vectorOpen = fileVectorOpen(codeFileName);
    std::vector<std::string> vectorOpenNoSpaces = removeSpaces(vectorOpen);
    vectorOpen.clear();
    
    
    std::copy(vectorOpenNoSpaces.begin(), vectorOpenNoSpaces.end(), std::ostream_iterator<std::string>(std::cout, "/*/")); //testing purposes to print the vector
    std::cout<<"\n\n";
    std::vector<std::string> testVector = properSplit(vectorOpenNoSpaces); //used for print testing
    
}