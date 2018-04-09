
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
#include <locale>  //used for isupper


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




void CodeClass::setAllWords(std::vector<std::string> finalVector){
    for (unsigned int i = 0; i < finalVector.size(); i++){
        std::string current = finalVector.at(i);
        if (current.std::string::find("BEGIN")!= std::string::npos){
            std::string begin = "BEGIN";
            hardCodedKeywordsBool[0] = true;
            std::size_t loc1 = current.find(begin);
            current.replace(loc1, begin.length(), "");
            finalVector.at(i) = current;
        }
        
        if (current.std::string::find("FOR")!= std::string::npos){
            std::string forS = "FOR";
            hardCodedKeywordsBool[1] = true;
            std::size_t loc2 = current.find(forS);
            current.replace(loc2, forS.length(), "");
            finalVector.at(i) = current;
        }
        
        if (current.std::string::find("END")!= std::string::npos){
            std::string endS = "END";
            hardCodedKeywordsBool[2] = true;
            std::size_t loc3 = current.find(endS);
            current.replace(loc3, endS.length(), "");
            finalVector.at(i) = current;
        }
        
        if (current.std::string::find("++")!= std::string::npos){
            std::string plusp = "++";
            hardCodedOperatorsBool[4] = true;
            std::size_t loc3 = current.find(plusp);
            current.replace(loc3, plusp.length(), "");
            finalVector.at(i) = current;
        }
        
        while (finalVector.back() == ""){
            finalVector.pop_back();
        }
    }
    
    int finalVectorSize = finalVector.size();
    for (int i = 0; i < finalVectorSize; i++){
        std::string current = finalVector.at(i);
        int symbolOccurence[5];
        char symbols[6] = {')', '(', ',', '=', '+', ';'};
        for (int j=0; j < 6; j++){
            symbolOccurence[j] = std::count(current.begin(), current.end(), symbols[j]);
            if (j == 0){
                leftPara+=symbolOccurence[j];
                while(current.std::string::find(')')!=std::string::npos){
                    std::size_t loc = current.find(')');
                    current.replace(loc, 1, " ");
                    finalVector.at(i) = current;
                }
                
            }
            else if (j == 1){
                rightPara+=symbolOccurence[j];
                while(current.std::string::find('(')!=std::string::npos){
                    std::size_t loc = current.find('(');
                    current.replace(loc, 1, " ");
                    finalVector.at(i) = current;
                }
                
            }
            else if (j == 2){
                comma+=symbolOccurence[j];
                hardCodedDelimitersBool[0] = true;
                while(current.std::string::find(',')!=std::string::npos){
                    std::size_t loc = current.find(',');
                    current.replace(loc, 1, " ");
                    finalVector.at(i) = current;
                }
            }
            else if (j == 3){
                hardCodedOperatorsBool[5] = true;
                while(current.std::string::find('=')!=std::string::npos){
                    std::size_t loc = current.find('=');
                    current.replace(loc, 1, " ");
                    finalVector.at(i) = current;
                }
            }
            else if (j == 4){
                hardCodedOperatorsBool[0] = true;
                while(current.std::string::find('+')!=std::string::npos){
                    std::size_t loc = current.find('+');
                    current.replace(loc, 1, " ");
                    finalVector.at(i) = current;
                }
            }
            else{
                hardCodedDelimitersBool[1] = true;
                while(current.std::string::find(';')!=std::string::npos){
                    std::size_t loc = current.find(';');
                    current.replace(loc, 1, " ");
                    finalVector.at(i) = current;
                }
                
            }
        }
        
        
        
        
    
        while (finalVector.back() == ""){
            finalVector.pop_back();
        }
    }
    
    finalVectorSize = finalVector.size();
    for (int i = 0; i < finalVectorSize; i++){
        int constantsValues;
        std::string current = finalVector.at(i);
        std::stringstream ss;
        ss >> current;
        std::string tempString;
        int found;
        while(!ss.eof()){
            ss>>tempString;
            
            if (std::stringstream(tempString)>>found){
                constantsValues+=found;
                constants.push_back(found);
            }
        }
        
    }
    
    
    //finalVector.clear();
    //std::copy(finalVector.begin(), finalVector.end(), std::ostream_iterator<std::string>(std::cout, "/*/")); //used for print testing
}

int CodeClass::getNestedDepth(){
    return nestedDepth;
}

std::vector<std::string> CodeClass::getIdentifiers(){
    return identifiers;
}
std::vector<int> CodeClass::getConstants(){
    return constants;
}

std::vector<std::string> CodeClass::getSyntaxErrors(){
    return syntaxErrors;        
}

CodeClass::CodeClass(std::vector<std::string> codeVector){
        //const std::string hardCodedKeywords[3] = {"BEGIN", "FOR", "END"}; 
        //const std::string hardCodedOperators[6] = {"+", "-", "*", "/", "++", "="};
        //const char hardCodedDelimiters[2] = {',', ';'};
        //bool hardCodedKeywordsBool[3];
        //bool hardCodedOperatorsBool[6];
        //bool hardCodedDelimitersBool[2];
    setAllWords(codeVector);
}

void CodeClass::printScreen(){
    const std::string hardCodedKeywords[3] = {"BEGIN", "FOR", "END"}; 
    const std::string hardCodedOperators[6] = {"+", "-", "*", "/", "++", "="};
    const char hardCodedDelimiters[2] = {',', ';'};
    
    
    std::cout<<"The depth of nested loop(s) is "<<nestedDepth<<"\n";
    std::cout<<"Keywords: ";
    for (int i = 0; i < 3; i++){
        if (hardCodedKeywordsBool[i]){
            std::cout<<hardCodedKeywords[i]<<" ";
        }
    }
    std::cout<<"\n";
    std::cout<<"Identifier: ";
    for (int i = 0; i < 3; i++){
        if (hardCodedKeywordsBool[i]){
            std::cout<<hardCodedKeywords[i]<<" ";
        }
    }
    std::cout<<"\n";
    std::cout<<"Constant: ";
    std::copy(getConstants().begin(), getConstants().end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<"\n";
    std::cout<<"Operators: ";
    for (int i = 0; i < 6; i++){
        if (hardCodedOperatorsBool[i]){
            std::cout<<hardCodedOperators[i]<<" ";
        }
    }
    std::cout<<"\n";
    std::cout<<"Delimiter: ";
    for (int i = 0; i < 2; i++){
        if (hardCodedDelimitersBool[i]){
            std::cout<<hardCodedDelimiters[i]<<" ";
        }
    }
    std::cout<<"\n";
    std::cout<<"Syntax Error(s): ";
    
    std::cout<<"\n";
    
    
    
}


int main(int agrc, char**argv){
    
    std::string codeFileName = getFileName(); //gets the name of the file
    fileCanBeOpened(codeFileName); //checks to see if the file can be opened
    std::vector<std::string> vectorOpen = fileVectorOpen(codeFileName);
    std::vector<std::string> vectorOpenNoSpaces = removeSpaces(vectorOpen);
    vectorOpen.clear();
    
    CodeClass codeClassVector(vectorOpenNoSpaces);
    
    codeClassVector.printScreen();
    
    
    //std::copy(vectorOpenNoSpaces.begin(), vectorOpenNoSpaces.end(), std::ostream_iterator<std::string>(std::cout, "/*/")); //testing purposes to print the vector
    std::cout<<"\n\n";
    
}