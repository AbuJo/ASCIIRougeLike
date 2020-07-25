#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class VectorHelper
{
public:
	VectorHelper();
	~VectorHelper();

	void overlayVector(vector <string> &_overlayVector, vector <string> &_baseVector, int start_x, int start_y);
	void loadVector(vector <string> &_emptyVector, string fileName);
	void printfVector(vector <string> & _drawVector, bool slow);
};

