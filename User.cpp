#include "List.cpp"
#include <fstream>
using namespace std;
class User{
   private:
      string passkey;
   public:
      string name;
      int rank;
      float win_rate;
      List wins;
      List losses;
      ifstream infile;
      User(){};
      User(string Name){
         name = Name;
         init();
      }
   void init(){
      string pass;
      int status;
      infile.open(name + ".txt");
      while(infile >> pass >> status) {
         switch (status)
         {
            case 1:
               wins.append(pass);
               break;
            case 0:
               losses.append(pass);
               break;
            case -1:
               passkey = pass;
               break;
         }
      }
      infile.close();
   }
   string getNewKey(){
      string key;
      key = "verg5k4we";
      return key;
   }
   bool CheckPassKey(string key){
      return key == passkey;
   }
   float getWinRate(){
      return (wins.length() / (wins.length() + losses.length())) * 100;
   }
};