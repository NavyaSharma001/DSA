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
int degree(int v){
int d=0;
for(int i=0;i<n;i++){
d+=adj[v][i];}
return d;}
void adjacent(int v){
cout<<"Adjacent vertices of "<<v<<": ";
for(int i=0;i<n;i++){
if(adj[v][i]){
cout<<i<<" ";}}
cout<<endl;}
int edgeCount(){
int c=0;
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(adj[i][j]){
c++;}}}
return c;}
void display(){
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout<<adj[i][j]<<" ";}
cout<<endl;}}};
int main(){
Graph g(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,3);
g.addEdge(3,4);
g.display();
cout<<"Degree of 1: "<<g.degree(1)<<endl;
g.adjacent(1);
cout<<"Number of edges: "<<g.edgeCount()<<endl;
return 0;}