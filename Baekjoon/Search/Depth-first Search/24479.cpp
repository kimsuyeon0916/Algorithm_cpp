#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void DFS(int v);

int n, m, r;
vector<int> graph[100001]; //인접 리스트 이용
int visited[100001]={0,};
int main() {
    FASTIO;
    cin >> n >> m >> r;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end());
    DFS(r);

    for (int i = 1; i <= n; i++) cout << visited[i] << '\n';
    return 0;
}

int s = 0;
void DFS(int v) {
    visited[v] = ++s;
    for (int i=0;i<graph[v].size();i++) {
      if(visited[graph[v][i]]==0) DFS(graph[v][i]);
    }
}