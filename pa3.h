
/*
    
    pa3.h
    Matthew Petela
    04/09/2018
    COP3503 Section: 1B02

*/

#ifndef PA3_H //start of the header guard
#define PA3_H

std::string getFileName(); //returns filename to open
void fileCanBeOpened(std::string codeFileName); //checks to see if the file can be opened
std::vector<std::string> fileVectorOpen(std::string codeFileName); //opens the file and stores it as a vector
std::vector<std::string> removeSpaces(std::vector<std::string> vectorOpen); //removes spaces from the vector



#endif //header guard