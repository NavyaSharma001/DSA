#include<iostream>
using namespace std;
#define MAX 100
class CircularQueue{
int arr[MAX], front, rear;
public:
CircularQueue(){front=-1; rear=-1;}
bool isEmpty(){return front==-1;}
bool isFull(){return (front==(rear+1)%MAX);}
void enqueue(int x){
if(isFull()) return; 
if(isEmpty()) front=0; 
rear=(rear+1)%MAX; 
arr[rear]=x;}
int dequeue(){
if(isEmpty()) return -1; 
int val=arr[front]; 
if(front==rear) front=rear=-1; 
else front=(front+1)%MAX; 
return val;}
int peek(){return isEmpty()?-1:arr[front];}
void display(){
if(isEmpty()) return; 
int i=front; 
while(true){cout<<arr[i]<<" "; if(i==rear) break; i=(i+1)%MAX;} 
cout<<endl;}
};
int main(){
CircularQueue q; int choice,x;
while(true){
cout<<"1.Enq 2.Deq 3.Peek 4.Display 5.Exit\n"; 
cin>>choice;
switch(choice){
case 1: cin>>x; q.enqueue(x); break;
case 2: cout<<q.dequeue()<<" "; break;
case 3: cout<<q.peek()<<" "; break;
case 4: q.display(); break;
case 5: return 0;
}
}
}