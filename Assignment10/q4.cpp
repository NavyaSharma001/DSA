#include<iostream>
using namespace std;
#define MAX 10
class Graph{
int n,e;
int parent[MAX];
int find(int i){
while(parent[i]!=i)
i=parent[i];
return i;}
void unionSet(int i,int j){
int a=find(i);
int b=find(j);
parent[a]=b;}
public:
Graph(int v,int edges){
n=v;
e=edges;}
void kruskal(int cost[MAX][MAX]){
int edgeCount=0,mincost=0;
for(int i=0;i<n;i++){
parent[i]=i;}
while(edgeCount<n-1){
int min=999,a=-1,b=-1;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(find(i)!=find(j)&&cost[i][j]<min){
min=cost[i][j];
a=i;b=j;}}}
unionSet(a,b);
cout<<a<<" - "<<b<<" : "<<min<<endl;
mincost+=min;
edgeCount++;}
cout<<"Minimum cost: "<<mincost<<endl;}};
int main(){
int cost[MAX][MAX]={{999,2,999,6,999},{2,999,3,8,5},{999,3,999,999,7},{6,8,999,999,9},{999,5,7,9,999}};
Graph g(5,7);
g.kruskal(cost);
return 0;}