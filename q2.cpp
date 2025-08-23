#include <iostream>
using namespace std;
#define MAX 100
class Stack{
char arr[MAX];
int top;
public:
Stack(){top=-1;}
void push(char x){
if(top==MAX-1)return;
arr[++top]=x;}
char pop(){
if(top==-1)return '\0';
return arr[top--];}
int isEmpty(){
return top==-1;}};
int main(){
char str[100];
cin.getline(str,100);
Stack s;
int i=0;
while(str[i]!='\0'){s.push(str[i]);i++;}
while(!s.isEmpty()){cout<<s.pop();}
cout<<"\n";
return 0;}