#include <string>
using namespace std;
class List{
   private:
      struct Node { 
         string data; 
         struct Node *next; 
      }; 
      struct Node* head = NULL;   
   public:
      List(){}     
      
      void push(string new_data){
         struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
         new_node->data = new_data; 
         new_node->next = head; 
         head = new_node;
      }

      void append(string new_data){
         if(head == NULL){push(new_data); return;}
         struct Node* ptr;
         ptr = head;
         while (ptr->next != NULL) { 
            ptr = ptr->next;
         }
         struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
         new_node->data = new_data; 
         new_node->next = NULL; 
         ptr->next = new_node;
      }

      void insert(string new_data, int index) { 
         if(head == NULL){push(new_data); return;}
         struct Node* ptr;
         ptr = head;
         for (int i = 0; i != index; i++){

         }
         } 
      
      void display() { 
         struct Node* ptr;
         ptr = head;
         while (ptr != NULL) { 
            cout<< ptr->data <<" \n"; 
            ptr = ptr->next; 
         } 
      } 
   int length(){
      struct Node* ptr;
      ptr = head;
      int len = 0;
      while (ptr!=NULL){
         len++;
         ptr = ptr->next;
      }
      return len;
   }
};
