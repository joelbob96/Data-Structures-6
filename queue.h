#include <iostream>
#include "customer.h"

#define arrSize 35

class queue{
private:

customer * customers[arrSize];
int arraySize = arrSize;
int front = 0;
int rear = 0;
int numElements = 0;
public:

void enqueue(customer * cust){
  if (!isFull()){
    customers[rear] = cust;
    //std::cout << customers[rear]->lname << " was added to the queue \n";
    rear = (rear + 1) % arraySize;
    numElements++;
  }else{
  std::cout << "The queue is full, ";
  std:: cout << customers[rear]->lname << " was not added\n";
  }
}

void enqueueArray(customer * custArray[], int size){
  for(int i = 0; i< size; i++)
    enqueue(custArray[i]);
}

customer * dequeue(){
  if(!isEmpty()){
    customer * cust = customers[front];
    front = (front + 1) % arraySize;
    numElements--;
    return cust;
  }else{
  customer * cust = new customer;
  std::cout << "The queue is empty";
  return cust;
  }
}

bool isEmpty(){
  if(numElements == 0)
  return true;
    else
    return false;
}

bool isFull(){
  if(numElements == arraySize)
    return true;
  else 
    return false;
}

int getArraySize(){
  return arraySize;
}

/*void printQueue(){
  int j = front;
  for(int i = 0; i < numElements; i++, j = (j + 1) % arraySize)
  std::cout << numbers[j] << '\n';
  //j = (j + 1) % arraySize;
}*/

};