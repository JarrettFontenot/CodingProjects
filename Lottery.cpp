// Author : Jarrett Fontenot

#include <iostream>
using namespace std;
#include <vector>


void randomNumVector(vector<int> & randNums);

void sortVector(vector<int> & randNums);

void userVector(vector<int> & userNums);

int main() {

  vector<int> randNums; 
  vector<int> userNums; 

  int choice = 0; 
  
  cout << "Welcome to My Lotto APP" << endl;
  cout << endl;

  cout << "The purpose of this app is creating a weekly lottery."
  "Once a week," "five distinct random integers between 1 to 52"
  "(inclusive) are drawn.If you guesses all of the numbers" 
  "correctly, you win a certain amount." << endl;

  cout << endl;


  do {

  cout << " Select one of the following: " << endl;
  cout << endl;

  cout << "1 - Play Lotto." << endl;
  cout << "9 - Exit the App." << endl;
  cout << endl;

  cout << "Enter Your Choice : ";

  cin >> choice;
  
  if(choice != 1 && choice != 9) {
    cout << "Invalid Selection" << endl;
    cout << endl;
  }

  else {
  
  
  if(choice == 1) {
  cout << endl;

  cout << "Enter 5 Distinct number: ";
  
  userVector(userNums);

  int size; 

  int count = 0; 

  for(int i = 0; i < userNums.size(); i ++) {
    for(int j = 1; j < userNums.size(); j++) {
      if(userNums[i] == userNums[j]) {
        count = count + 1;
      }
    }
  }
  
  if(count >= 5) {
    cout << "Invalid. Numbers must be distinct" << endl << endl;
  }
  else {

  randomNumVector(randNums);

  sortVector(randNums);

  int count = 0; 

  for(int i = 0; i < userNums.size(); i++) {
    for(int j = 0; j < randNums.size(); j++) {
      if(randNums[i] == userNums[j]) {
        count++;
      }
    }
  }

  cout << endl;

  if(count == 5) {
    cout << "You won" << endl;
  }
  else {
    cout << "You lost" << endl << endl;
  }
  
cout << "Lottery Numbers are: ";

  for(int i = 0; i < randNums.size(); i++) {
    cout << randNums[i] << " ";
  }
  cout << endl;
  
  cout << "Your numbers: ";

  for(int i = 0; i < userNums.size(); i++) {
    cout << userNums[i] << " ";
  }
  cout << endl << endl;

  
  randNums.clear();
  userNums.clear();

  }
  }
  }
  }




  while(choice != 9); {
      
      

  
  }

  cout << endl << endl;

  cout << "Thanks for Using the Lotto APP." << endl;
  cout << "Jarrett Fontenot" << endl;
  
  
 }



void randomNumVector(vector<int> & a) { 

  srand(time(NULL));

  int b = 0;

  for(int i = 0; i < 5; i++) {
     b = rand() % 52 + 1;
		 a.push_back(b);
  }
  
}


void sortVector(vector<int> & a) {

  bool temp = true;
    while(temp)
    {
        temp = false;
        for (int i = 0; i < a.size()-1; i++)
        {
            if (a[i]>a[i+1] )
            {
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                temp = true;
            }
        }
    }
}

void userVector(vector<int> & b) {

  int userNum;

  for(int i = 0; i < 5; i++) {
    cin >> userNum;
    b.push_back(userNum);
  }
  }


