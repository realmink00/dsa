#include <iostream>
using namespace std;
//M max  orders are 10;
class Cqueue{
    int q[10];
    int front=-1;
    int rear=-1;
    int max_size=10;
    public:
    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return (rear+1)%max_size==front;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow!!"<<endl;
            return;
        }
        if(isEmpty()){
            front=0;
        }
        rear=(rear+1)%max_size;
        q[rear]=x;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow!!";
            return -1;
        }
        int x=q[front];
        if(front==rear){
            front=rear=-1;
        }
        else{
        front=(front+1)%max_size;
        }
        cout<<"Served Order: "<<x<<endl;
        return x;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty!!"<<endl;
            return;
        }
        int i=front;
        cout<<"Pending orders: "<<endl;
        while(true){
            cout<<q[i]<<" "; //print first
            if(i==rear) return;
            i=(i+1)%max_size;
        }
        cout<<endl;
    }
};

int main(){
    int choice,order_id=101;
    Cqueue parlour;
    while(true){
        cout<<"\n1)Place Order\n2)serveorder\n3)display all orders\n4)Exit system\n";
        cin>>choice;
        if(choice==1){
            parlour.enqueue(order_id++);
        }
        else if(choice==2){
            parlour.dequeue();
        }
        else if(choice==3){
            parlour.display();
        }
        else if(choice==4){
            cout<<"Exitting program!!"<<endl;
            break;
        }
        else{
            cout<<"Invalid Choice";
        }
    }
    return 0;
}