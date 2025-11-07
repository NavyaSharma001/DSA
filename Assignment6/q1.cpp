#include<iostream>
using namespace std;
struct Node{int data;Node*next;Node*prev;};
Node*createNode(int val)
{Node*n=new Node;
n->data=val;
n->next=n->prev=NULL;
return n;}
void insertFirstDLL(Node*&head,int val)
{Node*n=createNode(val);
if(!head){head=n;return;}
n->next=head;
head->prev=n;
head=n;}
void insertLastDLL(Node*&head,int val)
{Node*n=createNode(val);
if(!head){head=n;return;}
Node*t=head;
while(t->next)t=t->next;
t->next=n;
n->prev=t;}
void insertAfterDLL(Node*&head,int key,int val)
{Node*t=head;
while(t&&t->data!=key)t=t->next;
if(!t)return;
Node*n=createNode(val);
n->next=t->next;
if(t->next)t->next->prev=n;
t->next=n;
n->prev=t;}
void deleteNodeDLL(Node*&head,int key)
{Node*t=head;
while(t&&t->data!=key)t=t->next;
if(!t)return;
if(t==head)head=head->next;
if(t->prev)t->prev->next=t->next;
if(t->next)t->next->prev=t->prev;
delete t;}
bool searchDLL(Node*head,int key)
{while(head){if(head->data==key)return true;head=head->next;}
return false;}
void displayDLL(Node*head)
{while(head){cout<<head->data<<" ";head=head->next;}
cout<<endl;}
void insertFirstCLL(Node*&last,int val)
{Node*n=createNode(val);
if(!last){last=n;last->next=last;return;}
n->next=last->next;
last->next=n;}
void insertLastCLL(Node*&last,int val)
{Node*n=createNode(val);
if(!last){last=n;last->next=last;return;}
n->next=last->next;
last->next=n;
last=n;}
void insertAfterCLL(Node*last,int key,int val)
{if(!last)return;
Node*p=last->next;
do{
if(p->data==key)
{Node*n=createNode(val);
n->next=p->next;
p->next=n;
if(p==last)last=n;
return;}
p=p->next;}
while(p!=last->next);}
void deleteNodeCLL(Node*&last,int key)
{if(!last)return;
Node*p=last->next;
Node*prev=last;
do{
if(p->data==key)
{if(p==last&&p->next==last){delete p;last=NULL;return;}
prev->next=p->next;
if(p==last)last=prev;
delete p;
return;}
prev=p;
p=p->next;}
while(p!=last->next);}
bool searchCLL(Node*last,int key)
{if(!last)return false;
Node*p=last->next;
do{if(p->data==key)return true;p=p->next;}
while(p!=last->next);
return false;}
void displayCLL(Node*last)
{if(!last){cout<<endl;return;}
Node*p=last->next;
do{cout<<p->data<<" ";p=p->next;}
while(p!=last->next);
cout<<endl;}
int main()
{Node*headDLL=NULL;
Node*lastCLL=NULL;
int ch,listType,val,key;
while(true)
{cout<<"1.DLL 2.CLL 3.Exit\nEnter list type:";
cin>>listType;
if(listType==3)break;
if(listType==1)
{cout<<"1.InsertFirst 2.InsertLast 3.InsertAfter 4.Delete 5.Search 6.Display 7.Back\n";
cin>>ch;
if(ch==1){cin>>val;insertFirstDLL(headDLL,val);}
else if(ch==2){cin>>val;insertLastDLL(headDLL,val);}
else if(ch==3){cin>>key>>val;insertAfterDLL(headDLL,key,val);}
else if(ch==4){cin>>key;deleteNodeDLL(headDLL,key);}
else if(ch==5){cin>>key;cout<<(searchDLL(headDLL,key)?"Found\n":"Not Found\n");}
else if(ch==6)displayDLL(headDLL);
else if(ch==7)continue;}
else if(listType==2)
{cout<<"1.InsertFirst 2.InsertLast 3.InsertAfter 4.Delete 5.Search 6.Display 7.Back\n";
cin>>ch;
if(ch==1){cin>>val;insertFirstCLL(lastCLL,val);}
else if(ch==2){cin>>val;insertLastCLL(lastCLL,val);}
else if(ch==3){cin>>key>>val;insertAfterCLL(lastCLL,key,val);}
else if(ch==4){cin>>key;deleteNodeCLL(lastCLL,key);}
else if(ch==5){cin>>key;cout<<(searchCLL(lastCLL,key)?"Found\n":"Not Found\n");}
else if(ch==6)displayCLL(lastCLL);
else if(ch==7)continue;}}
return 0;}