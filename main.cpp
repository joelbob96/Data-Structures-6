#include <iostream>
#include <fstream>
#include <ctime>
#include "teller.h"

int main() {
  srand(time(0)); // set random seed
  customer * custArray[arrSize]; //generate array of cutomers
  generateCustArray(custArray, "input.txt", arrSize);
  queue queue1; // initialize queue
  teller tellers[4]; //creates 4 tellers but only uses 1-3
  int timer = 0;
  int clock = 0;
  queue1.enqueueArray(custArray, arrSize); // stores new array element into queue

  // executes transactions
  queueTransactions(queue1, tellers, timer, clock);
  //prints results to screen and file output.txt
  report(custArray, tellers, arrSize, 3, "output.txt", clock);
  
}