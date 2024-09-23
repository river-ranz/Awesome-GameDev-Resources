#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Point2D {
  int x, y;
};

int main()
{
  cout << "input columns, lines, and index (0-99)" << endl << endl;
  int columns, lines, index;
  cin >> columns >> lines >> index;

  // if the index is out of range
  if (index < 0 || index > 99)
    index = 0;

  // board of visited
  vector<bool> board = vector<bool>(columns * lines, false);
  // stack of came from
  stack<Point2D> backtrack_path;
  // walls data structure
  

  backtrack_path.push(Point2D(0, 0));

  while (!backtrack_path.empty()) {
    // check if there are neighbors to visit and if the candidate is not in the queue
    if (/*that check*/) {
      // random select neighbor
      //add to stack
      // destroy wall
    }
    else {
      backtrack_path.pop();
    }
  }
}


