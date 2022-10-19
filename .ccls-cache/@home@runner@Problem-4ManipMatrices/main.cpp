#include <iostream>
#include <iomanip>

using namespace std;

//////////////////////////// Function Prototype ///////////////////////////
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLS);

/////////////////////////////// Main Code ////////////////////////////////
int main() {

  const int N_ROWS = 10;
  const int N_COLS = 3;
  int AirQuality_Index[N_ROWS][N_COLS] = {
  {50, 68, 58}, {58, 115, 78}, {62, 110, 81}, {66 , 124, 110}, {64, 152, 121}, {46, 143, 90}, {46, 143, 90}, {25, 91, 91}, {27, 19, 59}, {17, 13, 27}}; // 1st column is Grand Junction, CO. 2nd col is Fort Collins, CO. 3rd col is Denver-Boulder, CO.
// row 1-8 is Sunday to Sunday, row 9 and 10 are Monday and Tuesday.

  cout << "The matrix contains: " << endl;
  printMatrix_3col(AirQuality_Index, N_ROWS, N_COLS);
  
}
/////////////////////// User Defined Functions //////////////////////
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLS){
  int row, col;
  for (row = 0; row < N_ROWS; row++){
    for (col = 0; col <N_COLS; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}

// Writing a function to find how many times in the past several days the air quality was "unhealthy for senstive groups" for a specific city.
 int CountUnhealthySensitive(int matrix[][3], int N_ROWS, int city_col){
   int count = 0;
   int unhealthy_level = 101;
   int row;

   for(row = 0; row < N_ROWS; row++){
     if (matrix[row][city_col] >= unhealthy_level)
       count++;
   }

   
  return;
 }