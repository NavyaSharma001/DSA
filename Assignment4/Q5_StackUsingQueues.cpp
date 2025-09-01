#include<iostream>
#include<queue>
using namespace std;
class StackTwoQueues{
queue<int> q1,q2; 
public:
void push(int x){q1.push(x);}
int pop(){
if(q1.empty()) return -1; 
while(q1.size()>1){q2.push(q1.front()); q1.pop();}
int val=q1.front(); q1.pop(); 
swap(q1,q2); 
return val;}
};
class StackOneQueue{
queue<int> q; 
public:
void push(int x){q.push(x); for(int i=0;i<q.size()-1;i++){q.push(q.front()); q.pop();}}
int pop(){if(q.empty()) return -1; int val=q.front(); q.pop(); return val;}
};
int main(){
StackTwoQueues s2; StackOneQueue s1; int choice,x;
while(true){
cout<<"1.Push2Two 2.Pop2Two 3.Push1 4.Pop1 5.Exit\n"; 
cin>>choice;
switch(choice){
case 1: cin>>x; s2.push(x); break;
case 2: cout<<s2.pop()<<" "; break;
case 3: cin>>x; s1.push(x); break;
case 4: cout<<s1.pop()<<" "; break;
case 5: return 0;
}
}
}