#include<iostream>
using namespace std;
class Graph{
int n;
int adj[10][10];
public:
Graph(int v){
n=v;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
adj[i][j]=0;}}}
void addEdge(int u,int v){
adj[u][v]=1;
adj[v][u]=1;}
void BFS(int start){
int visited[10]={0},q[10],front=0,rear=0;
visited[start]=1;
q[rear++]=start;
cout<<"BFS: ";
while(front<rear){
int v=q[front++];
cout<<v<<" ";
for(int i=0;i<n;i++){
if(adj[v][i]&&!visited[i]){
visited[i]=1;
q[rear++]=i;}}}
cout<<endl;}};
int main(){
Graph g(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,3);
g.addEdge(2,4);
g.BFS(0);
return 0;}