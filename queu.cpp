#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

class Queue
{
public:
    int data[SIZE];
    int front, rear;

    void initialise()
    {
        front = -1;
        rear = -1;
    }  
    bool isEmpty()
    {
        return (front == -1);
    }
    bool isFull()
    {
        return (rear == SIZE - 1);
    }
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        if (front == -1)
            front = 0;
        data[++rear] = value;
        cout << value << " inserted into queue." << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Cannot remove element." << endl;
            return;
        }
        cout << data[front] << " removed from queue." << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front element: " << data[front] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.initialise();
    int choice, value;

    do
    {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}