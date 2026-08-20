#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node* next;

    Node(int data)
    {
        info = data;
        next = NULL;
    }
};

Node* front;
Node* rear;

bool isEmpty()
{
    return front == NULL;
}

void traverse()
{
    if (front == NULL)
    {
        cout << "Empty Queue" << endl;
        return;
    }

    Node* temp = front;

    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
    cout << "Front" << endl;
}

void enqueue(int info)
{
    Node* newNode = new Node(info);

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    int info;

    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    info = front->info;

    Node* temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }

    delete temp;

    return info;
}

int main()
{
    front = rear = NULL;

    if (isEmpty())
        cout << "Queue is initially empty" << endl;

    enqueue(5);
    enqueue(10);
    enqueue(15);

    cout << "Queue elements: ";
    traverse();

    cout << "Dequeued: " << dequeue() << endl;

    cout << "Queue after dequeue: ";
    traverse();

    return 0;
}





   