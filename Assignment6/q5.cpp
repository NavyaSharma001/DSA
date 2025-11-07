#include<iostream>
using namespace std;
struct Node{int data;Node*next;};
Node*createNode(int val)
{Node*n=new Node;
n->data=val;
n->next=NULL;
return n;}
bool isCircular(Node*head)
{if(!head)return true;
Node*t=head->next;
while(t&&t!=head)t=t->next;
return(t==head);}
int main()
{Node*a=createNode(1);
Node*b=createNode(2);
Node*c=createNode(3);
a->next=b;
b->next=c;
c->next=a;
cout<<(isCircular(a)?"Circular":"Not Circular");
return 0;}