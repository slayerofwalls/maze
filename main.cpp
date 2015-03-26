#include <iostream>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <string>
#include "room.h"
#include <stack>

using namespace std;

int const MAXSIZE = 100;
int getMazeSize(string fileName);
void loadMaze(room maze[MAXSIZE][MAXSIZE], string fileName,int curSize);
room loadRoom(char fileCharacter);
void printMaze(room maze[MAXSIZE][MAXSIZE], int currentSize);
void clearMaze(room maze[MAXSIZE][MAXSIZE], int currentSize);


int main() {
	string fileName;
	string tempString;
	stack<room> mazeRoute;
	int currentSize = 0;

	room roomMaze[MAXSIZE][MAXSIZE];

	cout << "Hello, please put the name of the file which contains the maze you are trying to solve." << endl;
	cin >> fileName;
	currentSize = getMazeSize( fileName );
	cout << "Current size stored as: " << currentSize << endl;

	loadMaze(roomMaze[MAXSIZE][MAXSIZE], fileName, currentSize);

	return 0;
}

int getMazeSize(string fileName) {
	int getSize;
	bool fileGot = false;
	string tempString;
	string tempFileName = fileName;


	while (!fileGot) { 
		ifstream file(tempFileName.c_str());
		if (file.is_open()) {
			getline(file, tempString);
			getSize = atoi(tempString.c_str());
			cout << "Size pulled from file = " << getSize << endl;
			file.close();
			fileGot = true;
		}
		else {
			cout << "Invalid input for your file's name, please retype: "
				<< endl;
			cin >> tempFileName;
			cout << endl;
		}
	}
	return getSize;
}

void loadMaze(room maze[MAXSIZE][MAXSIZE], string fileName, int curSize) {
	string tempFileName = fileName;
	string tempString;
	char tempChar;
	int counter = 0;
	bool read = false;

	string *stringArray;
	stringArray = new string[curSize];

	while (!read) {
		ifstream file(tempFileName.c_str());
		if (file.is_open()) {
			getline(file, tempString);//should skip the int at beginning;
			while (getline(file, tempString)) {
				stringArray[counter] = tempString;
				counter++;
				if (counter==curSize) {
					file.close();
					read = true;
				}

				else {
					cout << "Invalid input for your file's name, please retype: "
					<< endl;
					cin >> tempFileName;
					cout << endl;
				}
			}	
	
			for (int i=0;i<curSize; i++) {
				cout << stringArray << endl;
			}
		}
	}
}
