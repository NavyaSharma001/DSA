#include <iostream>
#include <cctype>
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
return top==-1;}
char peek(){
if(top==-1)return '\0';
return arr[top];}};
int prec(char c){
if(c=='+'||c=='-')return 1;
if(c=='*'||c=='/')return 2;
if(c=='^')return 3;
return -1;}
int main(){
char infix[200];
cin.getline(infix,200);
char postfix[200];
int k=0;
Stack s;
int i=0;
while(infix[i]!='\0'){
if(isalnum(infix[i])){
postfix[k++]=infix[i];}
else if(infix[i]=='('){
s.push('(');}
else if(infix[i]==')'){
while(!s.isEmpty()&&s.peek()!='('){
postfix[k++]=s.pop();}
if(!s.isEmpty()){s.pop();}}
else{
while(!s.isEmpty()&&((prec(infix[i])<prec(s.peek()))||(prec(infix[i])==prec(s.peek())&&infix[i]!='^'))){
postfix[k++]=s.pop();}
s.push(infix[i]);}
i++;}
while(!s.isEmpty()){
postfix[k++]=s.pop();}
postfix[k]='\0';
cout<<postfix<<"\n";
return 0;}