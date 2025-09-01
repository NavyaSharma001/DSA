#include<iostream>
#include<queue>
using namespace std;
int main(){
queue<int> q; int x; 
while(cin>>x) q.push(x);
int size=q.size(), half=size/2; 
queue<int> first;
for(int i=0;i<half;i++){first.push(q.front()); q.pop();}
while(!first.empty() || !q.empty()){
if(!first.empty()){cout<<first.front()<<" "; first.pop();}
if(!q.empty()){cout<<q.front()<<" "; q.pop();}
}
cout<<endl;}