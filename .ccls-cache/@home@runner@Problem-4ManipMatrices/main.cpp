#include <iomanip>
#include <iostream>

using namespace std;

//////////////////////////// Function Prototype ///////////////////////////
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLS);
int CountUnhealthySensitive(int matrix[][3], int N_ROWS, int city_col);
int meanAirQualityIndex(int matrix[][3], int N_ROWS, int city_col);

/////////////////////////////// Main Code ////////////////////////////////
int main() {

  const int N_ROWS = 10;
  const int N_COLS = 3;
  int AirQuality_Index[N_ROWS][N_COLS] = {
      {50, 68, 58},   {58, 115, 78}, {62, 110, 81}, {66, 124, 110},
      {64, 152, 121}, {46, 143, 90}, {46, 143, 90}, {25, 91, 91},
      {27, 19, 59},   {17, 13, 27}}; // 1st column is Grand Junction, CO. 2nd
                                     // col is Fort Collins, CO. 3rd col is
                                     // Denver-Boulder, CO.
  // row 1-8 is Sunday to Sunday, row 9 and 10 are Monday and Tuesday.

  cout << "The matrix contains: " << endl;
  printMatrix_3col(AirQuality_Index, N_ROWS, N_COLS); 
  cout << endl; 

  cout << "From 10/4/2020 to 10/13/2020 the air quality was unhealty for "
          "sensitive groups in: ";
  cout << "Grand Junction: "
       << CountUnhealthySensitive(AirQuality_Index, N_ROWS, N_COLS) << " times."
       << endl;
  cout << "Fort Collins: "
       << CountUnhealthySensitive(AirQuality_Index, N_ROWS, N_COLS) << " times."
       << endl;
  cout << "Denver/Boulder: "
       << CountUnhealthySensitive(AirQuality_Index, N_ROWS, N_COLS) << " times."
       << endl;

  // call code for city mean
  meanAirQualityIndex(AirQuality_Index, N_ROWS, N_COLS);
}
/////////////////////// User Defined Functions //////////////////////
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLS) {
  int row, col;
  for (row = 0; row < N_ROWS; row++) {
    for (col = 0; col < N_COLS; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}

// Writing a function to find how many times in the past several days the air
// quality was "unhealthy for senstive groups" for a specific city.
int CountUnhealthySensitive(int matrix[][3], int N_ROWS, int city_col) {
  int count = 0;
  int unhealthy_level = 101;
  int row;

  for (row = 0; row < N_ROWS; row++) {
    if (matrix[row][city_col] >= unhealthy_level)
      count++;
  }
  return count;
}

// function that detrmines the mean for each city
int meanAirQualityIndex(int matrix[][3], int N_ROWS, int city_col) {
  int sum = 0;
  int row, avg;

  for (row = 0; row < N_ROWS; row++) {
    sum = sum + matrix[row][city_col];

    avg = sum / N_ROWS;

    return avg;
  }
}