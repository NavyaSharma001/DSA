#include<iostream>
using namespace std;
struct Node{char data;Node*next;Node*prev;};
Node*createNode(char c)
{Node*n=new Node;
n->data=c;
n->next=n->prev=NULL;
return n;}
void insert(Node*&head,char c)
{Node*n=createNode(c);
if(!head){head=n;return;}
Node*t=head;
while(t->next)t=t->next;
t->next=n;
n->prev=t;}
bool isPalindrome(Node*head)
{if(!head)return true;
Node*tail=head;
while(tail->next)tail=tail->next;
while(head&&tail&&head!=tail&&tail->next!=head)
{if(head->data!=tail->data)return false;
head=head->next;
tail=tail->prev;}
return true;}
int main()
{Node*head=NULL;
string s="madam";
for(char c:s)insert(head,c);
cout<<(isPalindrome(head)?"Palindrome":"Not Palindrome");
return 0;}