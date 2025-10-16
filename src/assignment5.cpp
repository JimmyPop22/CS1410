#include <iostream>
#include <cmath> //HUGE_VAL needs this
#include <iomanip> //setw

using namespace std;

//Create a program that implements and tests a stack data structure that can store an unlimited number
// of double-valued items. Every item in the stack must be an object of the following structure:
struct Item {
    double value;
    Item* next;
};

struct Stack {
  Item* top;
  int size;
};

//Initialize empty stack
void InitializeStack(Stack* stack){
stack->top = nullptr;
stack->size = 0; 
}

//Uses the new operator to create an item whose value is the argument num and whose next is the current stack top. 
//It makes the created item the new stack top and increments stack size by 1. If this is the only item in the stack,
//then its next should be nullptr. 
void Push(Stack* stack, double num){
 Item* newItem = new Item; 
 newItem->value = num;
 newItem->next = stack->top;
 stack->top = newItem; 
 stack->size++;
}
// Returns the value of the item at the top. If the stack is empty,
// it returns the constant variable HUGE_VAL which is defined in the <cmath> header file.
double top(Stack* stack){
if (stack->top == nullptr){
  return HUGE_VAL;
}
else {
  return stack->top->value;
}
}


// Removes the item at the top from the stack and makes item underneath it
// the new stack top. It uses the delete operator to return the memory of 
//the removed top item back to the operating system and decrements stack size by 1.
void pop(Stack* stack) {
  if (stack->top != nullptr){
    Item* temp = stack->top;
    stack->top = stack->top->next;

    delete temp;
    stack->size--;
  }
}

// Prints the values of the stack items to the console, one item per line, top to bottom.
// The output should indicate where the top of the stack is and how many items are there.
// Use setw for this. Your output must be similar to the sample outcome below.
void print(Stack* stack){
cout << "Top of Stack (" << stack->size << " items):" << endl;
Item* current = stack->top;

    while (current != nullptr) {
        cout << setw(10) << current->value << endl;
        current = current->next;
    }
    cout << "_______________________" << endl;
}
void CleanStack(Stack, double);
void CleanStack(Stack* stack){
while (stack->top != nullptr){
  pop(stack);
}

}

//In the main() function, define a stack object and test it by 
//calling the above functions to push, pop, and print out arbitrary double values. 
int main(){
Stack myStack;
InitializeStack(&myStack);
    cout << "Pushing 12.5, 22.27, 34.72:" << endl;
    Push(&myStack, 12.5);
    Push(&myStack, 22.27);
    Push(&myStack, 34.72);
    Push(&myStack, 69.42);
    Push(&myStack, 133.94);
    Push(&myStack, 161.61);
    Push(&myStack, 243.88);

    cout << "Top value is: " << top(&myStack) << endl;

    cout << "\nPopping top item:" << endl;
    pop(&myStack);
    print(&myStack);

    cout << "New top value is: " << top(&myStack) << endl;

    cout << "\nPopping another item:" << endl;
    pop(&myStack);
    print(&myStack);

    cout << "Final top value is: " << top(&myStack) << endl;

        CleanStack(&myStack);

    return 0;
}



