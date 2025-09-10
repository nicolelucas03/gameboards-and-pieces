#include "Gameboard.h"
#include "Header.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std; 

int readBoardDimensions(ifstream& input, unsigned int& width, unsigned int& height) {
	string str;
	if (!getline(input, str)) {
		return UnableToRead;
	}

	istringstream iss(str);
		if (!(iss >> width >> height)) {
			return IncorrectDimens;
		}

	return Success; 
}
	

int readGamePieces(std::ifstream& input, vector<game_piece>& gamepieces, unsigned int& width, unsigned int& height) {
	int count = 0; 
	string line;

	while (getline(input, line)) {
		istringstream iss(line);
		string colorString, name, display;
		unsigned int x, y;

		if (iss >> colorString >> name >> display >> x >> y) {
			piece_color color = stringToPieceColor(colorString);
			//check if the color is invalid and does not fit within the dimensions of the board 
			if (color != piece_color::InvalidColor) {
				if (x < width && y < height) {
					unsigned int index = y * width + x; 
					gamepieces[index].color = color; 
					gamepieces[index].pieceName = name; 
					gamepieces[index].display = display; 
					++count; 
				}
			}
		}
	}
	if (count > 0) {
		return Success; 
	}

	else {
		return NoValidPieces;
	}
}




int printGameBoard(const vector<game_piece>& gamepieces, unsigned int width, unsigned int height) {
	if (gamepieces.size() != width * height) {
		return IncorrectDimens; 
	}

	for (int y = height - 1; y >= 0; --y) {
		for (unsigned int x = 0; x < width; ++x) {
			unsigned int index = y * width + x; 
			cout << gamepieces[index].display ; 
		}
		cout << endl; 
	}

	return Success; 
}



//extra credit 
int printGameBoardAdjacency(const std::vector<game_piece>& gamepieces, unsigned int width, unsigned int height) {
	if (gamepieces.size() != width * height) {
		return ReturnValues::IncorrectDimens;
	}

	const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (unsigned int y = 0; y < height; ++y) {
		for (unsigned int x = 0; x < width; ++x) {
			unsigned int index = y * width + x;
			const game_piece& piece = gamepieces[index];

			if (piece.display == " ") {
				continue; 
			}

			std::cout << x << "," << y << " " << piece.pieceName << " " << pieceToLower(piece.color) << ": ";

			bool first = true;
			for (int i = 0; i < 8; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
					unsigned int neighborIndex = ny * width + nx;
					const game_piece& neighbor = gamepieces[neighborIndex];

					if (neighbor.display != " ") {
						if (!first) {
							std::cout << "; ";
						}
						std::cout << nx << "," << ny << " " << neighbor.pieceName << " " << pieceToLower(neighbor.color);
						first = false;
					}
				}
			}
			std::cout << std::endl;
		}
	}
	return ReturnValues::Success;
}