#include<iostream>
using namespace std;
struct Element{
   int r,c,val;};

struct Sparse{
 int m,n,num;
 Element *ele;
 Sparse(int row,int col,int numE){
 m=row; n=col; num=numE;
 ele=new Element[num];
   }
   void read()
{ for(int i=0;i<num;i++){
 cin>>ele[i].r>>ele[i].c>>ele[i].val;}}
void display(){
int k=0;
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
if(k<num && ele[k].r==i && ele[k].c==j)
cout<<ele[k++].val<<" ";
else cout<<"0 ";}
cout<<endl;}}
Sparse transpose(){
Sparse t(n,m,num);
int k=0;
for(int i=0;i<n;i++){
for(int j=0;j<num;j++){
if(ele[j].c==i){
t.ele[k].r=i;
t.ele[k].c=ele[j].r;
t.ele[k].val=ele[j].val;
k++;}}}
 return t;}};
int main(){
Sparse s(3,3,3);
s.read();
s.display();
Sparse t=s.transpose();
t.display();
return 0;
}
