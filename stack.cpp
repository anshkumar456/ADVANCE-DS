#include<iostream>
using namespace std;
int n=5;
int stack[5];
int top=-1;

bool isempty(){
    return top<= -1;
}

bool isfull(){
    return top>=n-1;
}

void push(int item){
    if(isfull()){
        cout<<" Overflow"<<endl;
    }
    else{
        top++;
        stack[top]=item;
    }
}
void pop(){
    if(isempty()){
        cout<<" Underflow"<<endl;
    }
    else{
        cout<<" Popped element is "<<stack[top]<<endl;
        top--;
    }
}
void traverse(){
    int i;
    if(isempty()){
        cout<<" Stack elements are: ";
        for(i=top;i>=0;i--){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
        cout<<"top element is: "<<stack[top]<<endl;
    }
    else
    {
        cout<<" Stack is empty"<<endl;
    }
}
int main(){
    int ch, item;

    cout<<"1)push"<<endl;
    cout<<"2)pop"<<endl;
    cout<<"3)traverse"<<endl;
    cout<<"4)exit"<<endl;

    do{
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the element to be pushed: ";
                cin>>item;
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(ch!=4);

    return 0;
}