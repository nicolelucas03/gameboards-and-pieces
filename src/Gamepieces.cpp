

#include "Gamepieces.h"
#include "Header.h"

#include<string>
#include <algorithm>

using namespace std; 


string pieceToLower(piece_color color) {
	switch (color) {
	case piece_color::Red:
		return "red";
	case piece_color::Black:
		return "black";
	case piece_color::White:
		return "white";
	case piece_color::InvalidColor:
		return "invalid";
	case piece_color::NoColor:
		return "no color";
	default: 
		return "unknown"; 
	}
}

piece_color stringToPieceColor(const string& colorString) {
	string lowercaseColor = colorString; 

	transform(lowercaseColor.begin(), lowercaseColor.end(), lowercaseColor.begin(), [](unsigned char c) {
		return tolower(c);
		}); 

	if (lowercaseColor == "red") {
		return piece_color::Red; 
	}
	else if (lowercaseColor == "black") {
		return piece_color::Black; 
	}
	else if (lowercaseColor == "white") {
		return piece_color::White;
	} 
	else {
		return piece_color::InvalidColor;
	}
}