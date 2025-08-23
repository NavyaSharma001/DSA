#include <iostream>
using namespace std;
#define MAX 100
class Stack{
int arr[MAX];
int top;
public:
Stack(){top=-1;}
void push(int x){
if(top==MAX-1){cout<<"overflow\n";}else{arr[++top]=x;}}
int pop(){
if(top==-1){cout<<"underflow\n";return -1;}else{return arr[top--];}}
int peek(){
if(top==-1)return -1;
return arr[top];}
int isEmpty(){
if(top<=-1){return 1;}else{return 0;}}
int isFull(){
if(top>=MAX-1){return 1;}else{return 0;}}
void display(){
for(int i=top;i>=0;i--){cout<<arr[i]<<" ";}cout<<"\n";}};
int main(){
Stack s;
int ch,x;
do{
cin>>ch;
if(ch==1){cin>>x;s.push(x);}
else if(ch==2){cout<<s.pop()<<"\n";}
else if(ch==3){cout<<s.isEmpty()<<"\n";}
else if(ch==4){cout<<s.isFull()<<"\n";}
else if(ch==5){s.display();}
else if(ch==6){cout<<s.peek()<<"\n";}}while(ch!=0);
return 0;}