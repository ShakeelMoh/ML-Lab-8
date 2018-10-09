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

bool converged = false;

void printOut(float** grid){
  cout << "GRID: " << endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool checkConverge(float** grid, float** gridNew){
  bool flag = true;
  for(int i = 0; i < 2; i++){
     for(int j = 0; j < 3; j++){
       if (grid[i][j] != gridNew[i][j]){
         flag = false;
       }
     }
  }
  return flag;
}

float** copyToArray(float** grid, float** gridNew){

   for(int i = 0; i < 2; i++){
      for(int j = 0; j < 3; j++){
         grid[i][j] = gridNew[i][j];
      }
   }
   return grid;
}

void iterate(float** grid, float** gridNew, vector<int*> directions, vector<int> numDirections, float discount, vector<int> &optimalDirections){

  int c = 0;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      //cout << "Node " << c << " directions:" << endl;
      //cout << "Num directions: " << numDirections[c] << endl;
      //cout << "Node S" << c+1 << ": " << endl;
      for(int k = 0; k < numDirections[c]; k++){
        float value = gridNew[i][j];
        float reward = 0;

        switch(directions[c][k]){
          case 0://Left
            //cout << "Left" << endl;
            value = reward + (discount * grid[i][j-1]);
            //cout << "VALUE IS: " << value << endl;
            if (value > gridNew[i][j]){
               gridNew[i][j] = value;
               optimalDirections[c] = 0;
            }

            break;
          case 1://Up  vector<int> optimalDirections = vector<int>();
            //cout << "Up" << endl;
            if (j == 2 && i == 1){
               reward = 100.0f;
            }
            value = reward + (discount * grid[i-1][j]);
            //cout << "VALUE IS: " << value << endl;
            if (value > gridNew[i][j]){
               gridNew[i][j] = value;
               optimalDirections[c] = 1;
            }
            break;
          case 2://Right
            //cout << "Right" << endl;
            if (j == 1 && i == 0){
               reward = 50.0f;
            }
            value = reward + (discount * grid[i][j+1]);
            //cout << "VALUE IS: " << value << endl;
            if (value > gridNew[i][j]){
               gridNew[i][j] = value;
               optimalDirections[c] = 2;
            }
            break;
          case 3://Down
            //cout << "Down" << endl;
            value = reward + (discount * grid[i+1][j]);
            //cout << "VALUE IS: " << value << endl;
            if (value > gridNew[i][j]){
               gridNew[i][j] = value;
               optimalDirections[c] = 3;
            }
            break;

        }
      }
      c++;
    }
  }
  printOut(gridNew);
  if (checkConverge(grid, gridNew)){
    converged = true;
    cout << "CONVERGED!" << endl;
  }
  grid = copyToArray(grid, gridNew);
}


int main(int argc, char *argv[]) {

  cout << "REINFORCEMENT LEARNING LAB 8\n" << endl;

  //Initialize array
  float** grid = new float*[2];
  for (int i = 0; i < 2; i++){
    grid[i] = new float[3];
  }

  float** gridNew = new float*[2];
  for (int i = 0; i < 2; i++){
    gridNew[i] = new float[3];
  }

  cout << "STARTING GRID" << endl << endl;
  printOut(gridNew);


  float discount = 0.8f;
  //Left = 0; Up = 1; Right = 2; Down = 3;
  vector<int*> directions = vector<int*>();
  vector<int> numDirections = {2,3,0,2,3,2};
  vector<int> optimalDirections = {0,0,0,0,0,0};

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

  int i = 1;

  while (!converged){
    cout << "Iteration: " << i << endl;
    iterate(grid, gridNew, directions, numDirections, discount, optimalDirections);
    i++;
  }

  //Print optimnal route
  cout << "\nOPTIMAL POLICY:" << endl;
  for (int i = 0; i < optimalDirections.size(); ++i){
    cout << "Optimal move for state " << i+1 << " :";
    if (i == 2){
      cout << "- " << endl;
    } else {
      if (optimalDirections[i] == 0){
        cout << "LEFT " << endl;
      } else if (optimalDirections[i] == 1){
        cout << "UP " << endl;
      } else if (optimalDirections[i] == 2){
        cout << "RIGHT " << endl;
      } else if (optimalDirections[i] == 3){
        cout << "DOWN " << endl;
      }
    }
  }
 // printOut(grid);
  return 0;
}
