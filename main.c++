//uzd 2.2
#include <iostream>

#define MAX_SIZE 100 // Maximum size of the stack

class Stack {
private:
    int top; // Index of the top element
    int arr[MAX_SIZE]; // Array to store elements
public:
    // Constructor to initialize top
    Stack() : top(-1) {}

    // Function to push an element onto the stack
    void push(int val) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    // Function to pop an element from the stack
    int pop() {
        if (top == -1) {
            std::cout << "Stack Underflow\n";
            return -1; // Assuming -1 represents an error or empty stack
        }
        return arr[top--];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Function to get the top element of the stack without removing it
    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty\n";
            return -1; // Assuming -1 represents an error or empty stack
        }
        return arr[top];
    }
};

int main() {
    // Create a stack object
    Stack stack;

    // Push some elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(2456);
    stack.push(30);

    // Display the top element of the stack
    std::cout << "Top element: " << stack.peek() << std::endl;

    // Pop elements from the stack and display them
    std::cout << "Popping elements: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}