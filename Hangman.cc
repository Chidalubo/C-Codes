#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <map>
using namespace std;
void printmessage (string message, bool printTop = true, bool printBottom = true)
{
 if(printTop)
 {
   cout << "+--------------------------------+" << endl;
 cout << "|";
  }
 else
 {
   cout << "|";
 }
 bool front = true;
 for (int i = message.length(); i < 35; i++)
 {
   if (front)
   {
     message = " " + message;
   }
   else
   {
     message = message + " ";
   }
   front = !front;
 }
 cout << message.c_str();
 if(printBottom)
 {
   cout << "|" << endl;
   cout << "+--------------------------------+" << endl;
  }
  else
  {
    cout << "|" << endl;
  }
}
void DrawHangman(int guesscount = 0)
{
 if (guesscount >= 1)
   printmessage("|",false,false);
 else
   printmessage("",false,false);

 if (guesscount >= 2)
   printmessage("|",false,false);
 else
   printmessage("",false,false);

 if (guesscount >= 3)
   printmessage("o",false,false);
 else
   printmessage("",false,false);

 if (guesscount == 4)
  printmessage("/  ",false,false);

if (guesscount == 5)
 printmessage("/|",false,false);

 if (guesscount >= 6)
  printmessage("/|\\",false,false);
 else
    printmessage("",false,false);

    if (guesscount >= 7)
      printmessage("|",false,false);
    else
      printmessage("",false,false);

      if (guesscount == 8)
        printmessage("/",false,false);

        if (guesscount >= 9)
         printmessage("/ \\",false,false);
        else
           printmessage("",false,false);
         }
void PrintLetters(string input, char from, char to)
{
 string s;
 for (char i = from; i<= to; i++)
 {
   if(input.find(i) == string::npos)
   {
     s += i;
     s += " ";
   }
     else
     s += "  ";
 }
 printmessage(s, false, false);
}
void PrintAvailableLetters(string taken)
{
 printmessage ("Available letters");
 PrintLetters(taken, 'A','M' );
 PrintLetters(taken, 'N','Z' );
}
bool PrintWordAndCheckWin(string word, string guessed)
{
 bool won = true;
 string s;
 for(int i = 0; i < word.length(); i++)
 {
   if(guessed.find(word[i]) == string::npos)
   {
     won = false;
     s += "_ ";
   }
   else
   {
     s += word[i];
     s += " ";
   }
 }
 printmessage(s,false);
 return won;
}

int TriesLeft(string word, string guessed)
{
 int error = 0;
 for (int i = 0; i < guessed.length(); i++)
 {
   if (word.find(guessed[i]) == string::npos)
   error++;
 }
 return error;
}
int main(){
 string guesses;
 string wordToGuess;
 cout << "WELCOME TO THE HANGMAN GAME"  << endl  << endl << "YOU WOULD BE NEEDING TWO PALYERS FOR THIS GAME!" <<endl;
 cout << endl << "PLEASE ALWAYS REMEMBER TO USE CAPITAL LETTERS WHILE ANSWERING THE QUESTION." <<endl;
 cout << endl << "PLEASE KINDLY INPUT THE WORD YOU WANT PLAYER TWO TO GUESS" <<endl;
 cin >> wordToGuess;
 int tries = 0;
 bool win = false;
 do {
   system("clear");
     printmessage("HANGMAN GAME");
     DrawHangman(tries);
     PrintAvailableLetters(guesses);
     printmessage("Guess the Word");
     PrintWordAndCheckWin (wordToGuess, guesses);

   if(win)
    break;

       char x;
       cout << ">"; cin >> x;
       if (guesses.find(x) == string::npos)
       guesses += x;

       tries = TriesLeft(wordToGuess, guesses);
 } while(tries < 10);

 if (win)
printmessage("CONGRATS!!");

 else
 printmessage("FAILED!!");

 getchar();
 return 0;
}
