#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bfs(vector<vector<char>>& arr, vector<pair<int,int>>& start){
    queue<pair<int,int>> q;
    vector<int> xd = {-1,1,0,0};
    vector<int> yd = {0,0,1,-1};
    vector<vector<int>> dist(arr.size(),vector<int>(arr[0].size(),1e9));
    for(auto x: start){
        q.push(x);
        dist[x.first][x.second] = 0;
    }
    while(q.size()){
        pair<int,int> curr = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x_value = xd[i]+curr.first;
            int y_value = yd[i]+curr.second;
            if(x_value<arr.size() && y_value<arr[0].size() && arr[x_value][y_value] !='#' && (dist[x_value][y_value] > (dist[curr.first][curr.second]+1))){
                q.push({x_value, y_value});
                dist[x_value][y_value] = (dist[curr.first][curr.second]+1);

            }
        }
    }
    return dist;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>> arr(n, vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> hero;
    vector<vector<int>> monster;
    vector<pair<int,int>> monster_start;
    vector<pair<int,int>> end_points;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 'A') {vector<pair<int,int>> value; value.push_back({i,j}); hero = bfs(arr, value);}
            if(arr[i][j] == 'M') monster_start.push_back({i,j});
            if(arr[i][j] == '.' && (i==0 || i==n-1 || j==0 || j==m-1)){
                end_points.push_back({i,j});
            }
        }
    }

    monster = bfs(arr, monster_start);

    // cout<<"endx"<<endx<<" "<<endy<<'\n';
  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[0].size();j++){
      if((i==0 || i==(arr.size()-1)) || (j==0 || j==(arr[0].size()-1))){
        if(hero[i][j] < monster[i][j]){
          cout<<"YES\n";
          return 0;
        }
      }
    }
  }
    cout<<"NO\n";



    return 0;
}