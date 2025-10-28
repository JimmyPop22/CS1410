#include <iostream>
#include <cmath> //HUGE_VAL needs this
#include <iomanip> //setw

using namespace std;

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
 
void Push(Stack* stack, double num){
 Item* newItem = new Item; 
 newItem->value = num;
 newItem->next = stack->top;
 stack->top = newItem; 
 stack->size++;
}

double top(Stack* stack){
if (stack->top == nullptr){
  return HUGE_VAL;
}
else {
  return stack->top->value;
 }
}

void pop(Stack* stack) {
  if (stack->top != nullptr){
    Item* temp = stack->top;
    stack->top = stack->top->next;

    delete temp;
    stack->size--;
  }
}

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



