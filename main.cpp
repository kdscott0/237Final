#include <iostream>
#include <fstream>
#include <string>
#include "User.cpp"
using namespace std;
void ShowUserMenu(string name){
   User curr(name);
   int op;
   cout << "1) Try Your Password \n 2) Show My Stats \n 3) Return to Main Menu\n";
   cin >> op;
   switch (op)
   {
      case 1:
         /* code */
         break;
      case 2:
         /* code */
         break;
      case 3:
         ShowMainMenu; 
         break;
      default:
      cout << "Invalid Option Press Enter\n";
         cin.ignore();
         break;
   }
}

void ShowMainMenu(){
   int op;
   cout << "1) Login \n 2) Create User \n 3) View Rankings \n";
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
         cout << "Enter the name of User \n";
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