//ML LAB 8

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;

void printOut(int** grid){
  cout << "GRID: " << endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

void iterate(int** grid, int** gridNew, vector<int*> directions, vector<int> numDirections, float discount){
  cout << "Iterating\n" << endl;
  int c = 0;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      //cout << "Node " << c << " directions:" << endl;
      //cout << "Num directions: " << numDirections[c] << endl;
      cout << "Node S" << c+1 << ": " << endl;
      for(int k = 0; k < numDirections[c]; k++){
        float value = gridNew[i][j];
        switch(directions[c][k]){
          case 0://Left
            cout << "Left" << endl;
            break;
          case 1://Up
            cout << "Up" << endl;
            break;
          case 2://Right
            cout << "Right" << endl;
            
            break;
          case 3://Down
            cout << "Down" << endl;
            break;

        }
      }
      c++;
    }
  }

}

int main(int argc, char *argv[]) {

  cout << "REINFORCEMENT LEARNING LAB 8\n\n" << endl;

  //Initialize array
  int** grid = new int*[2];
  for (int i = 0; i < 2; i++){
    grid[i] = new int[3];
  }

  int** gridNew = new int*[2];
  for (int i = 0; i < 2; i++){
    gridNew[i] = new int[3];
  }

  float discount = 0.8f;
  //Left = 0; Up = 1; Right = 2; Down = 3;
  vector<int*> directions = vector<int*>();
  vector<int> numDirections = {2,3,0,2,3,2};
  int direction1[2] = {2,3};
  int direction2[3] = {0,2,3};
  int direction3[0] = {};
  int direction4[2] = {1,2};
  int direction5[3] = {0,1,2};
  int direction6[2] = {0,1};

  directions.push_back(direction1);
  directions.push_back(direction2);
  directions.push_back(direction3);
  directions.push_back(direction4);
  directions.push_back(direction5);
  directions.push_back(direction6);

  iterate(grid, gridNew, directions, numDirections, discount);



  return 0;
}
