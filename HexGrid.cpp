#include "HexGrid.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

HexGrid::HexGrid() {
  posY = 0.0f;
  posX = 0;
  maxDistance = 0;
}

void HexGrid::loadDirection(string fileName) {
  string line;
  ifstream myfile(fileName);
  if (myfile.is_open()) {
    getline(myfile, line);
    directions = splitStringBy(line, ',');

    myfile.close();
  }

  else
    cout << "Unable to open file" << '\n';
}

void HexGrid::step(string direction) {
  if (direction.compare("ne") == 0) {
    posX = posX + 1;
    posY = posY + 0.5;
  } else if (direction.compare("se") == 0) {
    posX = posX + 1;
    posY = posY - 0.5;
  } else if (direction.compare("nw") == 0) {
    posX = posX - 1;
    posY = posY + 0.5;
  } else if (direction.compare("sw") == 0) {
    posX = posX - 1;
    posY = posY - 0.5;
  } else if (direction.compare("s") == 0) {
    posY = posY - 1;
  } else if (direction.compare("n") == 0) {
    posY = posY + 1;
  }
}

vector<string> HexGrid::splitStringBy(string str, char c) {
  stringstream ss(str);
  string segment;
  vector<string> strings;

  while (std::getline(ss, segment, ',')) {
    strings.push_back(segment);
  }

  return strings;
}

void HexGrid::doSteps() {
  for (vector<string>::iterator it = directions.begin(); it != directions.end();
       ++it) {
    step(*it);
    maxDistance = max(maxDistance, getDistance());
  }
  cout << "posX: " << posX << "posY: " << posY << endl;
}

int HexGrid::getDistance() {
  float y = abs((float)posY);
  int x = abs(posX);

  if (y * 2 <= x) {
    return x;
  }

  int inc = (y * 2 - x) / 2;
  return x + inc;
}

int HexGrid::getMaxDistance() { return maxDistance; }
