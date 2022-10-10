// Author : Jarrett Fontenot


#include <iostream>
using namespace std;
#include <fstream>
#define HASHCLASS_H_


class hash1 {
  private:
    int hash_pos;
    string books[16];

  public:
    hash1();
    void fill();
    void insert(string);
    void insert2(string);
    int search(string, int&);
    int search2(string, int&);
    int Hash(string);
    int reHash(int);
    void Delete(string, int&);
    void Display();
};


hash1::hash1() {
  for(int i = 0; i < 16; i++) {
     books[i] = '*';
 }

}


void hash1::fill() {
  ifstream inStream;
  inStream.open("Books.txt");

  string bookName;


 for(int i = 0; i < 14; i++) {
   inStream >> bookName;
   insert(bookName);
 }

  
}


void hash1::insert(string book) {
 int count = 0;

 hash_pos = Hash(book);
 
  if(hash_pos >= 16) {
     hash_pos = 0;
 }
 
 while(books[hash_pos] != "*"){
   hash_pos = reHash(hash_pos);
   count++;
     
   if(count >= 16) {
     hash_pos = 0;
     break;
 }
 
}
 
  if(books[hash_pos] == "*"){
     books[hash_pos] = book;
 }
 

}


void hash1::insert2(string book) {
 int count = 0;
 

 hash_pos = Hash(book);
 
  if(hash_pos >= 16) {
     hash_pos = 0;
 }
 
 while(books[hash_pos] != "*"){
   hash_pos = reHash(hash_pos);
   count++;
     
   if(count >= 16) {
     cout << "Insert a New Book Name ( " << book 
     << " ) in the Table. " << endl;
     cout << "Table is Full ";
     hash_pos = 0;
     break;
 }
 
}
 
  if(books[hash_pos] == "*"){
     books[hash_pos] = book;
    cout << "Insert a New Book Name ( " << book 
    << " ) in the Table. " << endl;
    cout << "Book Name ( " << book << "  ) in inserted in location " 
    << hash_pos;
 }
 
}


int hash1::Hash(string book) {
 return book[0] % 10;
}


int hash1::reHash(int i) {
 if(i == 9) {
   return (i + 1) % 11;
 }
 if(i == 10) {
   return (i + 1) % 12;
 }
 if(i == 11) {
   return (i+1) % 13;
 }
 if(i == 12) {
   return (i+1) % 14;
 }
 if(i == 13) {
   return (i + 1) % 15;
 }
 if(i == 14) {
   return (i + 1) % 16;
 }
 if(i == 15) {
   return (0);
 }
  else {
   return  (i + 1) % 10;
 }
}


int hash1::search(string book, int& probes) {

  int index = Hash(book);
  int place = 0;
   
  while (books[index] != book) {
    place++;
    probes++;
    index = reHash(index);
        
    if (index == 16) {
        index = 0;
      }
        
    if (place == 16) {
      cout <<  "Searching For a Book Name ( " << book 
      << " ) in the Table. " << endl;
      cout << "The book name " << book  
      << " was not found in table" << endl;
            return -1;
        }
    }
    
cout <<  "Searching For a Book Name ( " << book << " ) in the Table. " 
<< endl;
cout << "The book name " << book  << " was found in location " 
<< index << endl;
    return index;
}


int hash1::search2(string book, int& probes) {

  int index = Hash(book);
  int place = 0;
  
  while (books[index] != book) {
    place++;
    probes++;
    index = reHash(index);
        
    if (index == 16) {
        index = 0;
      }
        
    if (place == 16) {
        return -1;
        }
    }
    
    return index;
}


void hash1::Delete(string book, int& probes) {
  
  int index = search2(book, probes);
    if (index == -1) {
      cout << "Delete a Book Name ( " << book << " ) from the Table " 
      << endl;
      cout << "Book Name ( " << book << " ) was not found in the Table";
        return;
    }
  
    cout << "Delete a Book Name ( " << book << " ) from the table. "
    << endl;
    cout << "Book Name ( " << book << " ) is deleted ";
    
    books[index] = "*";
  }  


void hash1::Display() {
 for(int i = 0; i < 16; i++) {
     if (i % 4 == 0)
        cout << endl;
        cout << books[i] << "  ";
    }
  }

int main() {

int probes1 = 0; 
int probes2 = 0; 
int count = 0; 
hash1 h; 


  cout << "Welcome to my Hashing Program" << endl << endl << endl;

  for(int i = 0; i < 30; i++) {
    cout << "-" << " ";
  }

  h.fill();

cout << endl << endl;
  
  cout << "A. Creates a string array of size 16. Assigning - to each" 
  << endl;
  cout << "   location in the array indicating that the array is empty." 
  << endl;
  cout << "B. Populates 14 elements of the array with book names" 
  << endl;
  cout << "C. If a collision occurs, linear probing will find the next" 
  << endl;
  cout << "   available position / location." << endl;
  cout << "D. The generated array will be displayed in 4 lines." << endl;
  cout << "   Each line contains 4 book name separated by 2 spaces." << 
  endl << endl << endl;


  cout << "The Generated Array.";
  h.Display();
  cout << endl << endl << endl;
  h.search("Animal-Farm", probes1);
  cout << endl << endl;
  h.search("Emma", probes1);
  cout << endl << endl;
  h.insert2("Hamlet");
  cout << endl << endl << endl;
  h.insert2("A-Passage-To-India");
  cout << endl << endl << endl;
  cout << "The Table After the 2 books were inserted:";
  h.Display();
  cout << endl << endl << endl;
  h.insert2("Relativity");
  cout << endl << endl << endl;
  h.Delete("Emma", probes2);
  cout << endl << endl << endl;
  h.Delete("Verity", probes2);
  cout << endl << endl << endl;
  cout << "The Table After 1 book was deleted:";
  h.Display();
  cout << endl << endl << endl;
  cout << "The number of linear probes when each number is hashed "
  "and collision " << endl;
  cout << "occurred when searching for a book in the array is " 
  << probes1;
  cout << endl << endl;
  cout << "The number of linear probes when each number is hashed "
  "and collision " << endl;
  cout << "occurred when deleting a book in the array is " 
  << probes2;
  cout << endl << endl << endl;
  cout << "This hashing program was implemented by" << endl;
  cout << "Jarrett Fontenot – 4 – 28 - 2022";
}

