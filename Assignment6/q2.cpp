#include<iostream>
using namespace std;
struct Node{int data;Node*next;};
Node*createNode(int val)
{Node*n=new Node;
n->data=val;
n->next=NULL;
return n;}
void insertEnd(Node*&last,int val)
{Node*n=createNode(val);
if(!last){last=n;last->next=last;return;}
n->next=last->next;
last->next=n;
last=n;}
void display(Node*last)
{if(!last)return;
Node*p=last->next;
do{cout<<p->data<<" ";p=p->next;}
while(p!=last->next);
cout<<last->next->data<<endl;}
int main()
{Node*last=NULL;
insertEnd(last,20);
insertEnd(last,100);
insertEnd(last,40);
insertEnd(last,80);
insertEnd(last,60);
display(last);
return 0;}