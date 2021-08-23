#include <iostream>
#include <fstream>
#include <string>

struct customer{
int ID = 0;
std::string fname = "default";
std::string lname = "default";
double amount = 0;
char transType = 'o';
double balance = 0;
int atime = 0; // arrival time
int stime = 0; // service time
int TellerNo = 0; // Teller number
};

void printCustomer(customer * cust){
  std::string type;
if(cust->transType == 'd')
type = "Deposit,";
else if(cust->transType == 'w')
type = "Withdraw,";

std::cout << cust->ID << " " << cust->fname << " " << cust->lname << " Amount:" << cust->amount << " " << type  << " Balance:" << cust->balance << " Arrival T:" << cust->atime << " Wait T:" << cust->stime << " Teller:" << cust->TellerNo << '\n';
}

void printCustomertoFile(customer * cust, std::string outputFile){
std::string type;
if(cust->transType == 'd')
type = "Deposit,";
else if(cust->transType == 'w')
type = "Withdraw,";

std::ofstream output;
  output.open(outputFile, std::ios_base::app);
  if(output.is_open()){
output << cust->ID << " " << cust->fname << " " << cust->lname << " Amount:" << cust->amount << " " << type  << " Balance:" << cust->balance << " Arrival T:" << cust->atime << " Wait T:" << cust->stime << " Teller:" << cust->TellerNo << '\n';
  }
  output.close();
}

void inputCustomer(customer * cust, std::string inputString){
  cust->ID = std::stoi(inputString.substr (0,4));
  
  cust->fname = inputString.substr (4, 8);
  
  cust->lname = inputString.substr(12, 8);
  
  cust->amount = std::stod(inputString.substr(20, 4));
  
  cust->transType = inputString.substr(24, 1)[0];
  
  cust->balance = std::stoi(inputString.substr(25,10));

  cust->TellerNo = (rand() % 3) + 1;
}

void generateCustArray(customer * custArray[], std::string file, int num){
  std::ifstream input;  //input file
  input.open(file);  // opens input file
  std::string inputString; // input storage

  for(int i = 0; i< num; i++){
    custArray[i] = new customer;  // creates new customer in array
    std::getline(input, inputString); // get input from file
    inputCustomer(custArray[i], inputString); // stores input in array
  }
  input.close();
}