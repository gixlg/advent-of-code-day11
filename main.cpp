// AoC 2017
#include <iostream>
#include "HexGrid.h"

int main() {
  HexGrid hexGrid;
  hexGrid.loadDirection("input.txt");
  hexGrid.doSteps();
  cout << "Steps: " << hexGrid.getDistance() << endl;
  cout << "Max Distance: " << hexGrid.getMaxDistance() << endl;
}