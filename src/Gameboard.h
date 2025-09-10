#pragma once 

#include <fstream>
#include <vector>
#include <string>

#include "Gamepieces.h"

int readBoardDimensions(std::ifstream& input, unsigned int& width, unsigned int& height);

int readGamePieces(std::ifstream& input, std::vector<game_piece>& gampieces, unsigned int& width, unsigned int& height); 

int printGameBoard(const std::vector<game_piece>& gamepieces, unsigned int width, unsigned int height);

//extra credit: 
int printGameBoardAdjacency(const std::vector<game_piece>& gamepieces, unsigned int width, unsigned int height);