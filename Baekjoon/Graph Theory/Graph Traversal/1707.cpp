#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void BFS(int start);
void DFS(int v);

vector<int> graph[20001];
int visited[20001];

int main()
{
  FASTIO;
  int K;
  cin >> K;
  
  for (int i = 1; i <= K; i++) {
    int V, E;
    string result = "YES";
    fill_n(visited, 20001, 0); // 테케마다 초기화
    for (int i = 0; i <= 20000; i++) graph[i].clear();

    cin >> V >> E;
    int u, v;
    for (int i = 1; i <= E; i++) {
      cin >> u >> v;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }

    for (int i = 1; i <= V; i++)
      sort(graph[i].begin(), graph[i].end());

    for (int i = 1; i <= V; i++) { // 모든 정점 확인해야 함
      if (visited[i] == 0) {
        visited[i] = 1;
        DFS(i);
      }
    }

    for (int i = 1; i <= V; i++) {
      for (int vertex : graph[i]) {
        if (visited[i] == visited[vertex]) {
          result = "NO";
          break;
        }
      }
      if (result == "NO")
        break;
    }
    cout << result << '\n';
  }
  return 0;
}

void BFS(int start)
{
  queue<int> q;
  q.emplace(start);
}

void DFS(int v)
{
  for (int vertex : graph[v]) {
    if (visited[vertex] == 0) {
      visited[vertex] = -visited[v];
      DFS(vertex);
    }
  }
}
