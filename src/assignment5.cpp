//How can you expect me to do an assignment when you haven't taught the material? 
#include <iostream>
#include <cmath>
#include <stack>
#include <string>

using namespace std;

struct Item {
    int Value;
    Item* next;
};

struct List {
Item* head;
Item* tail;
int size;

};

void addItem(List* list, int val){
//Create the item first
Item* item = new Item;  //Item* points to Item, then references new Item. 
item -> Value = val;
item -> next = nullptr;

if(list->head){ //list (lower case?) is not empty, head will have something in it, if this happens then do the lext line.
  list ->tail->next = item; //This adds to the tail of the list. 
}else{  //If list is empty
  list ->head = item; //The tail becomes the head. 
}
 list -> tail = item;
 list->size++;

}