#include<iostream>
using namespace std;

class Diagonal{
   int *arr,n;
   public:
   Diagonal(int size){
      n=size;
      arr=new int[n];
   }
   void set(int i,int j,int x){
      if(i==j) arr[i-1]=x;
   }
   int get(int i,int j){
      if(i==j) return arr[i-1];
      else return 0;
   }
   void display(){
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            cout<<get(i,j)<<" ";
         }
         cout<<endl;}}};
class TriDiagonal{
   int *arr,n;
   public:
   TriDiagonal(int size){
      n=size;
      arr=new int[3*n-2];
   }
   void set(int i,int j,int x){
      if(i-j==0) arr[n-1+i-1]=x;
      else if(i-j==1) arr[i-2]=x;
      else if(i-j==-1) arr[2*n-1+i-1]=x;
   }
   int get(int i,int j){
      if(i-j==0) return arr[n-1+i-1];
      else if(i-j==1) return arr[i-2];
      else if(i-j==-1) return arr[2*n-1+i-1];
      else return 0;}};
class LowerTri{
   int *arr,n;
   public:
   LowerTri(int size){
      n=size;
      arr=new int[n*(n+1)/2];
   }
   void set(int i,int j,int x){
      if(i>=j) arr[i*(i-1)/2+j-1]=x;
   }
   int get(int i,int j){
      if(i>=j) return arr[i*(i-1)/2+j-1];
      else return 0;}};
class UpperTri{
   int *arr,n;
   public:
   UpperTri(int size){
      n=size;
      arr=new int[n*(n+1)/2];
   }
   void set(int i,int j,int x){
      if(i<=j) arr[j*(j-1)/2+i-1]=x;
   }
   int get(int i,int j){
      if(i<=j) return arr[j*(j-1)/2+i-1];
      else return 0;}};

class Symmetric{
   int *arr,n;
   public:
   Symmetric(int size){
      n=size;
      arr=new int[n*(n+1)/2];
   }
   void set(int i,int j,int x){
      if(i>=j) arr[i*(i-1)/2+j-1]=x;
      else arr[j*(j-1)/2+i-1]=x;
   }
   int get(int i,int j){
      if(i>=j) return arr[i*(i-1)/2+j-1];
      else return arr[j*(j-1)/2+i-1];}}:
int main(){
   Diagonal d(3);
   d.set(1,1,5);
   d.set(2,2,7);
   d.set(3,3,9);
   d.display();
   return 0;
}
