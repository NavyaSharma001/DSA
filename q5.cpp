#include <iostream>
#include <cctype>
using namespace std;
#define MAX 100
class Stack{
int arr[MAX];
int top;
public:
Stack(){top=-1;}
void push(int x){
if(top==MAX-1)return;
arr[++top]=x;}
int pop(){
if(top==-1)return -1;
return arr[top--];}
int isEmpty(){
return top==-1;}};
int main(){
char exp[200];
cin.getline(exp,200);
Stack s;
int i=0;
while(exp[i]!='\0'){
if(isdigit(exp[i])){
int num=0;
while(isdigit(exp[i])){
num=num*10+(exp[i]-'0');
i++;}
s.push(num);}
else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
int v1=s.pop();
int v2=s.pop();
switch(exp[i]){
case '+':s.push(v2+v1);break;
case '-':s.push(v2-v1);break;
case '*':s.push(v2*v1);break;
case '/':s.push(v2/v1);break;}
i++;}
else{i++;}}
cout<<s.pop()<<"\n";
return 0;}