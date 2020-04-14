#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "maze_stream.h"

using namespace std;

static string make_maze() {
	srand(time(NULL));
	int width = (rand() % 5) + 5;
	int height = (rand() % 5) + 5;
	int scrWidth = width * 2 + 3;
	int scrHeight = height * 2 + 3;
	char* data = new char[scrWidth * scrHeight];
	memset(data, 'X', scrWidth * scrHeight);
	for (int y = 1; y < scrHeight - 1; y++) {
		memset(&data[y * scrWidth + 1], ' ', scrWidth - 2);
	}
	int startX = (rand() % (width + 1)) * 2 + 1;
	int startY = (rand() % (height + 1)) * 2 + 1;
	data[startY * scrWidth + startX] = 'S';
	while (1) {
		int endX = (rand() % (width + 1)) * 2 + 1;
		int endY = (rand() % (height + 1)) * 2 + 1;
		if (abs(startX - endX) + abs(startY - endY) > 10) {
			data[endY * scrWidth + endX] = 'E';
			break;
		}
	}
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int xx = x * 2 + 2;
			int yy = y * 2 + 2;
			data[yy * scrWidth + xx] = 'X';
			switch (rand() % 4) {
			case 0:
				data[(yy - 1) * scrWidth + xx] = 'X';
				break;
			case 1:
				data[(yy + 1) * scrWidth + xx] = 'X';
				break;
			case 2:
				data[yy * scrWidth + xx - 1] = 'X';
				break;
			default:
				data[yy * scrWidth + xx + 1] = 'X';
				break;
			}
		}
	}
	stringstream result;
	for (int y = 0; y < scrHeight; y++) {
		result << string(data + y * scrWidth, scrWidth) << endl;
	}
	result << endl;
	return result.str();
}

MazeStream::MazeStream(): istringstream(make_maze()) {
}
