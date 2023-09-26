#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int dp[501];
int correct_max; // 가장 긴 증가 수열의 길이

int main()
{
  FASTIO;
  int N;
  cin >> N;
  vector<pair<int, int>> graph(N + 1); // 전깃줄
  for (int i = 1; i <= N; i++){
    cin >> graph[i].first >> graph[i].second;
  }
  sort(graph.begin(), graph.end());

  for (int i = 1; i <= N; i++){
    dp[i] = 1; // boundary condition(자기 자신 포함 길이 1)
    for (int j = 1; j < i; j++){
      if (graph[j].second < graph[i].second){ // 수열이 증가하는 경우
        dp[i] = max(dp[i], dp[j] + 1); // 해당 i번째 전깃줄의 B값까지 가능한 가장 긴 증가수열 길이 업데이트
      }
    }
    correct_max = max(correct_max, dp[i]); // 1~ N 번째 전깃줄의 B값까지 가능한 가장 긴 증가수열 길이 업데이트
  }
  cout << N - correct_max; // 전체 개수 - 없애지 않아도 되는 전깃줄의 최대 개수
  return 0;
}