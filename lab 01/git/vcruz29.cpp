/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 8/28/2018
*    Description: Sorting an inputted array using insertion sort
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sort(int values[], int length) {
  for(int i = 1; i < length; i++) {    
    int key = values[i], j = i - 1;
    while(j >= 0 && key > values[j]) {
      values[j + 1] = values[j];
      j--;
    }
    values[j + 1] = key;
  }
}

int main() {
  /*First Input: Length of Array*/
  int length;
  //cout << "Input\n";
  cin >> length;
  int values[length];
  /*Take in Array Values*/
  for (int i = 0; i < length; i++) {
      cin >> values[i];
  }
  /*Sort Array*/
  sort(values, length);
  /*Print Sorted Array*/
  //cout << "Output\n";
  for (int i = 0; i < length; i++) {
      cout << values[i] << ";";
  }
  return 0;
}