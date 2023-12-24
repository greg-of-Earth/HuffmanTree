//Gregory Calderon
//881477990
//CS 236 Advanced Data Structures Online
//Fall 2023


#include <iostream>
using namespace std;

#include "Huffman.h"
#include <limits>

void ShowMenu();
void GetInput();


enum MenuOptions{
  INPUT = 1,
  QUIT = 0,
};

int main() {
  ShowMenu();
}

//get user input string to be coded
void GetInput(){
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string input;
  int inpSze;
  cout << "\nEnter a string to be encoded: ";
  getline(cin, input);
  inpSze = input.size();
  Huffman newHuff(input);
  newHuff.MapValues();
  
}

//display main menu
void ShowMenu() {
  int option;

  do{
    cout << "\n**** MENU ****";
    cout << "\n1. Input";
    cout << "\n0. Quit";
    cout << "\nEnter Choice: ";

    cin >> option;

    switch(option){
      case INPUT:
        GetInput();
        break;
    case QUIT:
        cout << "\nPROGRAM TERMINATED\n";
      break;
    default:
        cout << "\nINVALID OPTION. TRY AGAIN\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
  }while(option != QUIT);
}
  

  /*TEST
  

  **** MENU ****
  1. Input
  0. Quit
  Enter Choice: 1

  Enter a string to be encoded: book
  Huffman Codes are:
  b: 10
  k: 11
  o: 0

  COMPRESSED MESSAGE: 100011

  DECOMPRESSED MESSAGE: book

  **** MENU ****
  1. Input
  0. Quit
  Enter Choice: 1    

  Enter a string to be encoded: bananas
  Huffman Codes are:
  a: 0
  b: 110
  n: 10
  s: 111

  COMPRESSED MESSAGE: 1100100100111

  DECOMPRESSED MESSAGE: bananas

  **** MENU ****
  1. Input
  0. Quit
  Enter Choice: 1

  Enter a string to be encoded: run a lot
  Huffman Codes are:
   : 111
  a: 010
  l: 011
  n: 000
  o: 001
  r: 101
  t: 100
  u: 110

  COMPRESSED MESSAGE: 101110000111010111011001100

  DECOMPRESSED MESSAGE: run a lot

  **** MENU ****
  1. Input
  0. Quit
  Enter Choice: 1

  Enter a string to be encoded: book sss
  Huffman Codes are:
   : 100
  b: 00
  k: 101
  o: 01
  s: 11

  COMPRESSED MESSAGE: 000101101100111111

  DECOMPRESSED MESSAGE: book sss
  
  **** MENU ****
1. Input
0. Quit
Enter Choice: 1

Enter a string to be encoded: data compression algorithm
Huffman Codes are:
 : 1010
a: 011
c: 11000
d: 11100
e: 11101
g: 11001
h: 11010
i: 000
l: 10111
m: 1111
n: 10110
o: 010
p: 11011
r: 1001
s: 1000
t: 001

COMPRESSED MESSAGE: 11011000100000001010110101001110111110010101001000001110101111

DECOMPRESSED MESSAGE: data compression algorithm

**** MENU ****
1. Input
0. Quit
Enter Choice: 0

PROGRAM TERMINATED
  
  
  
  
  
  
  
  
  
  
  
  
  */