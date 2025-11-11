#include<iostream>
using namespace std;
#define MAX 10
#define INF 999
class Graph{
int n;
int cost[MAX][MAX];
public:
Graph(int v){
n=v;}
void prim(int G[MAX][MAX]){
int selected[MAX]={0},no_edge=0,min,x,y;
selected[0]=1;
cout<<"Edges in MST:\n";
while(no_edge<n-1){
min=INF;
x=0;y=0;
for(int i=0;i<n;i++){
if(selected[i]){
for(int j=0;j<n;j++){
if(!selected[j]&&G[i][j]){
if(min>G[i][j]){
min=G[i][j];
x=i;y=j;}}}}}
cout<<x<<" - "<<y<<" : "<<G[x][y]<<endl;
selected[y]=1;
no_edge++;}}};
int main(){
int G[MAX][MAX]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
Graph g(5);
g.prim(G);
return 0;}