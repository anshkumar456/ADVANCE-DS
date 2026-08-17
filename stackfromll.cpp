#include <iostream>

// Define the Node structure
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Define the Stack class
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor initializes top to nullptr
    Stack() {
        top = nullptr;
    }

    // Destructor to free remaining memory when stack is destroyed
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push an item onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top; // Link the new node to the current top
        top = newNode;       // Move top to the new node
        std::cout << "Pushed " << value << " to stack\n";
    }

    // Pop an item from the stack
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! The stack is empty.\n";
            return -1; // Return an error value
        }

        Node* temp = top;        // Temporarily hold the top node
        top = top->next;         // Move top pointer to the next node
        int poppedData = temp->data;
        
        delete temp;             // Explicitly free memory in C++
        return poppedData;
    }

    // Peek at the top item without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }
};

// Main function to test the stack
int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element is: " << myStack.peek() << "\n";

    std::cout << "Popped: " << myStack.pop() << "\n";
    std::cout << "Popped: " << myStack.pop() << "\n";

    std::cout << "Top element is: " << myStack.peek() << "\n";

    return 0;
}
