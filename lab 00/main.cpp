/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: valen
 *
 * Created on September 1, 2021, 7:35 PM
 */

#include <cstdlib>
#include <iostream>




#include <iostream>

#define MAX_INT 2147483647

using namespace std;
  

int main(int argc,char **argv) {

  int* seq;
  int array_size = 1;

  // fetch Sequence size
  cout << " what do you want the array size to be?"<< endl;
  cin >> array_size;
  seq = new int[array_size];
    
  // Read Sequence 
  cout << "Input your values" << endl;
  for(int i=0; i<array_size; i++)
    cin >> seq[i];
   
  // Initializing max and min
  int MaxNumb = seq[0];
  int MinNumb = seq[0];

  // Updating max and min
  for(int i=1; i<array_size; i++)
  {
    if (seq[i] > MaxNumb)
      MaxNumb = seq[i];
    if (seq[i] < MinNumb)
      MinNumb = seq[i];
  }

  // output
  cout << MaxNumb 
       << ";" 
       << MinNumb;

  
  delete[] seq;

}
