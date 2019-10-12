/**
 * File: main.cpp
 * Author: Jered Stevens / Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: 10/10/2019
 * Description:
 * Main driver of an Array based implementation of a stack.
 */

#include <iostream>
#include "stack.h"
#include "stdlib.h"
#include <fstream>

using namespace std;

/**
 * Main Program
 * 
 */
int main() {
  //srand(34234); // seed random number gen
  

  Stack S1; // Instance of our stack default constructor
 // Stack S2(200);  // Instance of our stack specified size

  // Load the stack with random nums
  // for (int i = 0; i <= 95; i++) {
  //   S1.Push(i);
  // }

  // make sure it looks correct
  //S1.Print();
  //cout << endl;

 //Pop some items off the top  
  // S1.Pop();
  // S1.Pop();
  // S1.Pop();
  // S1.Pop();

  // cout << endl;
  
   S1.checkResize();

  //Pop some to reduce the size
   for (int i = 0; i <= 80; i++) {
     S1.Pop();
   }
  
  //Test reduce
  S1.checkResize();

  // Check for correct behavior again
  S1.Print();
  return 0;
}