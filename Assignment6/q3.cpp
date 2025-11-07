#include<iostream>
using namespace std;
struct Node{int data;Node*next;Node*prev;};
Node*createNode(int val)
{Node*n=new Node;
n->data=val;
n->next=n->prev=NULL;
return n;}
void insertDLL(Node*&head,int val)
{Node*n=createNode(val);
if(!head){head=n;return;}
Node*t=head;
while(t->next)t=t->next;
t->next=n;
n->prev=t;}
int sizeDLL(Node*head)
{int c=0;
while(head){c++;head=head->next;}
return c;}
struct CNode{int data;CNode*next;};
CNode*createCNode(int val)
{CNode*n=new CNode;
n->data=val;
n->next=NULL;
return n;}
void insertCLL(CNode*&last,int val)
{CNode*n=createCNode(val);
if(!last){last=n;last->next=last;return;}
n->next=last->next;
last->next=n;
last=n;}
int sizeCLL(CNode*last)
{if(!last)return 0;
int c=0;
CNode*p=last->next;
do{c++;p=p->next;}
while(p!=last->next);
return c;}
int main()
{Node*head=NULL;
insertDLL(head,10);
insertDLL(head,20);
insertDLL(head,30);
cout<<"Size of DLL:"<<sizeDLL(head)<<endl;
CNode*last=NULL;
insertCLL(last,1);
insertCLL(last,2);
insertCLL(last,3);
cout<<"Size of CLL:"<<sizeCLL(last)<<endl;
return 0;}