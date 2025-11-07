#include<iostream>
using namespace std;
void improvedSelectionSort(int a[],int n)
{for(int i=0,j=n-1;i<j;i++,j--)
{int min=i,max=i;
for(int k=i;k<=j;k++)
{if(a[k]<a[min])min=k;
if(a[k]>a[max])max=k;}
swap(a[i],a[min]);
if(max==i)max=min;
swap(a[j],a[max]);}}
void printArray(int a[],int n)
{for(int i=0;i<n;i++)cout<<a[i]<<" ";
cout<<endl;}
int main()
{int a[]={64,25,12,22,11,90,3};
int n=7;
improvedSelectionSort(a,n);
printArray(a,n);
return 0;}