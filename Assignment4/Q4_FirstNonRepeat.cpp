#include<iostream>
#include<queue>
using namespace std;
int main(){
string s; cin>>s; 
queue<char> q; int freq[256]={0};
for(int i=0;i<s.size();i++){
char c=s[i]; 
freq[c]++; 
q.push(c); 
while(!q.empty() && freq[q.front()]>1) q.pop(); 
cout<<(q.empty()?-1:q.front())<<" ";}
cout<<endl;}