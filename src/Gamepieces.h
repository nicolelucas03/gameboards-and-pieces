# pragma once 

#include <string>
#include<vector>

enum class piece_color {
	Red,
	Black,
	White,
	InvalidColor,
	NoColor,
};

struct game_piece {
	piece_color color; 
	std::string pieceName; 
	std::string display;

	game_piece() : color(piece_color::NoColor), pieceName(""), display("") {}

	game_piece(piece_color c, const std::string& name, const std::string disp) : color(c), pieceName(name), display(disp) {}
	

};

std::string pieceToLower(piece_color color); 
piece_color stringToPieceColor(const std::string& colorString);

