#include <iostream>
#include "queue.h"

struct teller{
  int transactions = 0;
  int deposits = 0;
  int withdraws = 0;
};

void transaction(customer * cust, teller &t, int &timer){
  if(cust->transType == 'w'){ // withdraws
  cust->balance = cust->balance - cust->amount;
  t.withdraws++;
  }else if(cust->transType == 'd'){ // deposits
  cust->balance = cust->balance + cust->amount;
  t.deposits++;
  }
  int randomtime = (rand() % 10) + 1;
  timer = timer + randomtime;
  t.transactions++;
  cust->atime = timer;
}

void queueTransactions(queue queue1, teller t[], int &timer, int &clock){
customer * temp;
int wait = 0;
int size = queue1.getArraySize();
  for(int i = 0; i < size; i++){
    wait = (rand() % 5) +1;
    clock = clock + wait;
    temp = queue1.dequeue();
    transaction(temp, t[temp->TellerNo], timer);
    temp->stime = clock;
    //printCustomer(temp);
  }

}

void printTeller(teller t, int number){
  std::cout << "Teller " << number << " deposits: "
  << t.deposits << " Withdraws: " << t.withdraws 
  << " Total transactions: " << t.transactions << '\n';
}

void printTellertoFile(teller t, int number, std::string outputFile){
  std::ofstream output;
  output.open(outputFile, std::ios_base::app);
  if(output.is_open()){
  output << "Teller " << number << " deposits: "
  << t.deposits << " Withdraws: " << t.withdraws 
  << " Total transactions: " << t.transactions << '\n';
  }
  output.close();
}

void clearOutputFile(std::string outputFile){
  std::ofstream output;
  output.open(outputFile);
  output << '\n';
  output.close();
}

void report(customer * custArray[], teller tellers[], int custSize, int tellerSize, std::string outputFile, int time){
double totaltrans;
double size = tellerSize;
clearOutputFile(outputFile);

for(int i = 0; i < custSize; i++){
  printCustomer(custArray[i]);
  printCustomertoFile(custArray[i], outputFile);
}

for(int i = 1; i < tellerSize + 1; i++){
  totaltrans = tellers[i].transactions + totaltrans;
  printTeller(tellers[i], i);
  printTellertoFile(tellers[i], i, outputFile);
}
double average = totaltrans/size;
  std::ofstream output;
  output.open(outputFile, std::ios_base::app);
  if(output.is_open()){
    output << "Total Wait time: " << time << " Average transactions per teller: " << average << '\n';
  }
  output.close();

  std::cout << "Total Wait time: " << time << " Average transactions per teller: " << average << '\n';
}