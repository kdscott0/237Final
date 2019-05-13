#include "List.cpp"
#include <fstream>
using namespace std;
class User{
   private:
      string passkey;
      // Borrowed
      string randStr(size_t length) {
         srand(time(NULL));  //generate a seed by using the current time
         char str[length];
         str[length-1] = '\0';
         size_t i = 0;
         int r;

         for(i = 0; i < length-1; ++i) {
            for(;;) {
               r = rand() % 57 + 65; //interval between 65 ('A') and 65+57=122 ('z')
               if((r >= 65 && r <= 90) || (r >= 97 && r <= 122)) { // exclude '[' to '`'
               str[i] = (char)r;
               break;
               }
            }
         }
         return string(str);
      }
      ////////
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
         switch (status) {
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
   string getNewKey(bool last){
      string key;
      if (last){1;} else {0;}
      key = randStr(8); 
      passkey = key;
      return key;
   }
   bool CheckPassKey(string key){
      return key == passkey;
   }
   float getWinRate(){
      return float(wins.length() / (wins.length() + losses.length())) * 100.0;
   }
};