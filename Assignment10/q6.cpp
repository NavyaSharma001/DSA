#include<iostream>
using namespace std;
#define INF 999
class Graph{
int n;
int cost[10][10];
public:
Graph(int v){
n=v;}
void dijkstra(int G[10][10],int start){
int dist[10],visited[10];
for(int i=0;i<n;i++){
dist[i]=INF;
visited[i]=0;}
dist[start]=0;
for(int c=0;c<n-1;c++){
int min=INF,u;
for(int i=0;i<n;i++){
if(!visited[i]&&dist[i]<=min){
min=dist[i];
u=i;}}
visited[u]=1;
for(int v=0;v<n;v++){
if(!visited[v]&&G[u][v]&&dist[u]+G[u][v]<dist[v]){
dist[v]=dist[u]+G[u][v];}}}
cout<<"Vertex Distance from Source\n";
for(int i=0;i<n;i++){
cout<<i<<"\t"<<dist[i]<<endl;}}};
int main(){
int G[10][10]={{0,4,0,0,0,0,0,8,0},{4,0,8,0,0,0,0,11,0},{0,8,0,7,0,4,0,0,2},{0,0,7,0,9,14,0,0,0},{0,0,0,9,0,10,0,0,0},{0,0,4,14,10,0,2,0,0},{0,0,0,0,0,2,0,1,6},{8,11,0,0,0,0,1,0,7},{0,0,2,0,0,0,6,7,0}};
Graph g(9);
g.dijkstra(G,0);
return 0;}