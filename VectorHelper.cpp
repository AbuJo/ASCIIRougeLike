#include "VectorHelper.h"

// Takes in an overlay vector and a base vector and places the overlay ontop of the base vector
void VectorHelper::overlayVector(vector <string> &_overlayVector, vector <string> &_baseVector, int start_x, int start_y) {
	// Loop through and overlay
	for (int y = 0; y < _overlayVector.size(); y++) {
		for (int x = 0; x < _overlayVector[y].length(); x++) {
			//For every element in insert_graphic
			_baseVector[y + start_y][x + start_x] = _overlayVector[y][x];
		}
	}
}

// loads a vector with a data from a text file
void VectorHelper::loadVector(vector <string> &_emptyVector, string fileName) {
	ifstream file;
	string inputFile = fileName;
	file.open(inputFile);
	if (file.fail()) {
		perror(inputFile.c_str());
		system("PAUSE");
		exit(1);
	}
	string line;
	while (getline(file, line)) {
		_emptyVector.push_back(line);
	}
	file.close();
}

// uses printf function to display a 2d vector
void VectorHelper::printfVector(vector <string> &_drawVector, bool slow) {
	for (int y = 0; y < _drawVector.size(); y++) {
		for (int x = 0; x < _drawVector[y].length(); x++) {
			printf("%c", _drawVector[y][x]);
		}
		if (slow == true) {
			Sleep(100);
		}
		printf("\n");
	}
}

VectorHelper::VectorHelper() {

}

VectorHelper::~VectorHelper() {

}