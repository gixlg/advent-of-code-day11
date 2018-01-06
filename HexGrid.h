#include <string>
#include <vector>

using namespace std;

class HexGrid {
 public:
  HexGrid();
  vector<string> directions;
  void loadDirection(string fileName);
  void doSteps();
  int getDistance();
  int getMaxDistance();

 private:
  vector<string> splitStringBy(string str, char c);
  void step(string direction);
  float posY;
  int posX;
  int maxDistance;
};