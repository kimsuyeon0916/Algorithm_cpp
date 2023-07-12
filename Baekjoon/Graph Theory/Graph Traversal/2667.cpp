#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void DFS(int v); //DFS 풀이
void BFS(int start); //BFS 풀이

vector<int> graph[625]; //0~24
bool visited[625]={0,};
vector<int> result;
int c=0;
int main()
{
  FASTIO;
  int N; cin >> N;
  vector<vector<bool>> m(N,vector<bool>(N));
  for(int i=0;i<N;i++){
    string input; cin >> input;
    bitset<25> bits(input);
    for(int j=0;j<N;j++){
      m[i][j]=bits[(N-1)-j];
      if(i>0){
        if((m[i][j]&m[i-1][j])==1){
          graph[i*N+j].emplace_back((i-1)*N+j);
          graph[(i-1)*N+j].emplace_back(i*N+j);
        }
      }
      if(j>0){
        if((m[i][j]&m[i][j-1])==1){
          graph[i*N+j].emplace_back(i*N+(j-1));
          graph[i*N+(j-1)].emplace_back(i*N+j);
        }
      }
    }
  }

  for(int i=0;i<N*N;i++) sort(graph[i].begin(), graph[i].end());
  for(int i=0;i<N*N;i++){
    if(m[i/N][i%N]==1 && !visited[i]){
      c=0;
      //DFS(i);
      BFS(i);
      result.emplace_back(c);
    } 
  }
  sort(result.begin(),result.end());
  
  cout << result.size() << '\n';
  for(int r : result) cout << r << '\n';
  return 0;
}

void DFS(int v){
  visited[v]=true;
  ++c;
  for(int vertex : graph[v]){
    if(!visited[vertex]) DFS(vertex);
  }
}

void BFS(int start){
  queue<int> q;
  q.emplace(start);
  visited[start]=true;
  c=0;
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    ++c;
    for(int vertex : graph[cur]){
      if(!visited[vertex])
        q.emplace(vertex);
        visited[vertex]=true;
      }
    }
}
