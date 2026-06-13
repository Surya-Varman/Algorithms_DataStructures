#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  //bfs algo starts from here;
  int start, end;
  cin>>start>>end;
  queue<int> q;
  q.push(start);
  vector<int>dist(n+1, 1e9);
  dist[start] = 0;
  while(q.size()){
    int curr = q.front();
    q.pop();
    for(int i: adj[curr]){
      if(dist[i] > dist[curr]+1){
        dist[i] = dist[curr]+1;
        q.push(i);
      }
    }
  }
  
  if(dist[end]>=1e9){
    cout<<0;
  }
  else{
    cout<<dist[end]<<endl;
  }
  
  return 0;
}