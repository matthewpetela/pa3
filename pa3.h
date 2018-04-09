
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


class CodeClass{
    
    private:
        bool hardCodedKeywordsBool[3];
        bool hardCodedOperatorsBool[6];
        bool hardCodedDelimitersBool[2];
        
        int nestedDepth;
        int leftPara;
        int rightPara;
        int comma;
        int semiColon;
        std::vector<std::string> keywords;
        std::vector<std::string> operators;
        std::vector<std::string> delimiters;
        
        std::vector<std::string> identifiers;
        std::vector<std::string> syntaxErrors;
        std::vector<std::string> constants;
        
    public:
        CodeClass();
        CodeClass(std::vector<std::string> finalVector);
        //~CodeClass();
        
        void setAllWords(std::vector<std::string> finalVector);
        void printScreen();
        
        int getNestedDepth();
        std::vector<std::string> getIdentifiers();
        std::vector<std::string> getConstants();
        std::vector<std::string> getSyntaxErrors();
};



#endif //header guard