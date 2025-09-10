/**
 * Main.cpp
 * CSE 332S
 * Lab Num: 2
 * Author: Nicole Lucas
 * Email: lucas.n@wustl.edu
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


#include "Header.h"
#include "Gameboard.h"
#include "Gamepieces.h"


using namespace std;

ReturnValues usageMessage(const string &programName, const string &usageInfo) {
    cout << "Usage:" << programName << " " << usageInfo << endl; 
    return ReturnValues::IncorrectUsage;

}

void becomeLowerCase(string& str) {
    for (char& c : str) {
        if (c >= 'A' && c <= 'Z') {
            //finds position within upper case letters and subtracts it to become lowercase
            c = c - 'A' + 'a'; 
        }
    }
}



int main(int argc, char* argv[]) {
    if (argc != ExpectedArgs) {
        return usageMessage(argv[ArrayIndex::ProgramName], "<InputFileName>");
    }

    ifstream inputFile(argv[ArrayIndex::InputFileName]);

    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file." << endl; 
        return ReturnValues::UnableToRead; 
    }

    unsigned int width, height; 

    int result = readBoardDimensions(inputFile, width, height); 
    while (result == ReturnValues::Failure) {
        result = readBoardDimensions(inputFile, width, height); 
    }

    if (result != ReturnValues::Success) {
        cout << "Error: Unable to read board dimensions." << endl; 
        return result; 
    }

    vector<game_piece> gamepieces(width * height); 
    
    for (unsigned int y = 0; y < gamepieces.size(); ++y) {
        gamepieces[y] = game_piece(); 
        gamepieces[y].display = " "; 
        
    }

    result = readGamePieces(inputFile, gamepieces, width, height); 
    if (result != ReturnValues::Success) {
        cout << "Error: Unable to read game pieces." << endl; 
        return result;
    }

    result = printGameBoard(gamepieces, width, height); 
    if (result != ReturnValues::Success) {
        cout << "Error: Unable to print game board. " << endl;
        return result; 
    }

    //extra credit: 
    result = printGameBoardAdjacency(gamepieces, width, height);
    if (result != ReturnValues::Success) {
        std::cout << "Error: Unable to print game board with adjacency information." << std::endl;
        return result;
    }




    return ReturnValues::Success;
}



