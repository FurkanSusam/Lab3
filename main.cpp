#include <iostream>
using namespace std;
class Node {
public:
    int data;
    struct Node *next;
    Node(int k)
    {data=k;}
};
Node *front = NULL;
Node *rear = NULL;

void enqueue(int x){
    Node *y = new Node(x);
    if(rear == nullptr){
        rear = y;
        rear->next= nullptr;
        front = y;
    }

    else{
        rear->next = y;
        y->next = nullptr;
        rear = y;
    }

}

void dequeue(){
    Node *z = front;
    if(front== nullptr)
        cout<<"Empty"<<endl;
    else
    {
        if(z->next != nullptr){
            cout<<"Deleted: "<<z->data<<endl;
            z = z->next;
            ::free(front);
            front = z;
        }
        else
        {
            front= nullptr;
            rear = nullptr;
        }
    }

};
int top(){

    if(front== nullptr)
        cout<<"Queue is empty";

    else
        return front->data;
}
bool isEmpty(){
    Node *tmp = front;

    if(tmp == nullptr)
        return true;

    else{
        return false;
    }

}

int size(){
    int size = 0;
    if(front == nullptr)
        cout<<"Queue is empty "<<endl;
    else{
        Node *temp = front;

        while(temp != nullptr){
            temp = temp->next;
            size++;
        }
    }
    return size;
}

int main(){
    enqueue(7);
    enqueue(11);
    enqueue(13);
    enqueue(15);
    enqueue(18);
    enqueue(75);
    enqueue(40);


    cout<<"Before dequeued"<<endl;

    Node *m = front;
    do {
        cout<<m->data<<" ";
        m= m->next;

    }
    while(m != nullptr);
    cout<<endl;

    dequeue();

    cout<<"After dequeued"<<endl;
    Node *n = front;
    do {
        cout<<n->data<<" ";
        n= n->next;

    }
    while(n != nullptr);

    cout<<endl;

    cout<<"top :"<<endl;

    cout<<top()<<endl;


    cout<<"size :"<<endl;

    cout<<size();

}