#include<iostream>
using namespace std;
int merge(int arr[],int temp[],int l,int m,int r){
int i=l,j=m,k=l,inv=0;
while(i<=m-1 && j<=r){
if(arr[i]<=arr[j]) temp[k++]=arr[i++];
else
{temp[k++]=arr[j++];
inv+=(m-i);}}
while(i<=m-1) temp[k++]=arr[i++];
while(j<=r) temp[k++]=arr[j++];
for(int p=l;p<=r;p++) arr[p]=temp[p];
return inv;}
int _mergeSort(int arr[],int temp[],int l,int r){
int inv=0;
if(l<r){
int m=(l+r)/2;
inv+=_mergeSort(arr,temp,l,m);
inv+=_mergeSort(arr,temp,m+1,r);
inv+=merge(arr,temp,l,m+1,r);}
 return inv;}
int countInv(int arr[],int n){
int *temp=new int[n];
return _mergeSort(arr,temp,0,n-1);}

int main(){
int arr[]={1,20,6,4,5};
int n=5;
cout<<"Inversions="<<countInv(arr,n)<<endl;
return 0;}
