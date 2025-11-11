#include<iostream>
using namespace std;
class Graph{
int n;
int adj[10][10];
int visited[10];
public:
Graph(int v){
n=v;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
adj[i][j]=0;}
visited[i]=0;}}
void addEdge(int u,int v){
adj[u][v]=1;
adj[v][u]=1;}
void DFSUtil(int v){
visited[v]=1;
cout<<v<<" ";
for(int i=0;i<n;i++){
if(adj[v][i]&&!visited[i]){
DFSUtil(i);}}}
void DFS(int start){
for(int i=0;i<n;i++){
visited[i]=0;}
cout<<"DFS: ";
DFSUtil(start);
cout<<endl;}};
int main(){
Graph g(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,3);
g.addEdge(3,4);
g.DFS(0);
return 0;}