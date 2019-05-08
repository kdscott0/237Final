#include <iostream>
#include <fstream>
#include <string>
#include "User.cpp"
using namespace std;
void ShowMainMenu();
void ShowUserMenu(string name){
   User curr(name);
   int op;
   string attempt;
   bool result; 
   cout << "1) Try Your Password \n2) Show My Stats \n3) Return to Main Menu\n";
   cin >> op;
   switch (op)
   {
      case 1:
         cout << "Take your guess... or type 'exit'\n";
         cin >> attempt;
         if (attempt=="exit"){
            break;
         } else {
            result = curr.CheckPassKey(attempt);
            if(result){
               cout << "Heyyy Good Job ";
            } else {
               cout << "Sorry maybe next time ";
            } 
            cout << "heres your new passkey\n" << curr.getNewKey() << endl;
         }
         break;
      case 2:
         cout << "Hello " << curr.name << ",\n";
         cout << "You've got a guess success rate of " << curr.getWinRate() << "%\n";
         if (curr.getWinRate() > 50){
            cout << "Keep Up the Good Work\n";
         } else {
            cout << "You should try writing down your passkey\n";
         }
         cout << "Enter to Continue\n";
         cin.ignore();
         break;
      case 3:
         ShowMainMenu(); 
         break;
      default:
      cout << "Invalid Option Press Enter\n";
         cin.ignore();
         break;
   }
   ShowUserMenu(name);
}

void ShowMainMenu(){
   int op;
   cout << "1) Login \n2) Create User \n3) View Rankings \n";
   cin >> op;
   
   string name;
   switch (op) {
      case 1:
      while (name != "exit"){
         cout << "Enter the name of User or type 'exit' to return to main menu\n";
         cin >> name;
         if (true) {//fexist(name + ".txt"){
            ShowUserMenu(name);
         } else {
            cout << "No User by that name exists try again\n";
         }}
         break;
      case 2:
         cout << "Enter the name of User\n";
         cin >> name;
         ShowUserMenu(name);
         break;
      case 3:
         cout << "/////UNDER CONSTRUCTION//////\nEnter to Continue";
         cin.ignore();
         break;
      default:
         cout << "Invalid Option Press Enter\n";
         cin.ignore();
         break;
   }
   return ShowMainMenu();
}

int main() { 
   User a("Nile");
   User b("John");
   User c("Osa");
   cout << "The User has a " << a.getWinRate()<< " WinRate\n";
   ShowMainMenu();
   return 0; 
}