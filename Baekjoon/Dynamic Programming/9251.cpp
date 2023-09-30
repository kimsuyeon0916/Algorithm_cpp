#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int dp[1001][1001]; //dp[0][i] & dp[i][0] => boundary condition

int main()
{
  FASTIO;
  string s1,s2; cin >> s1 >> s2;
  for(int i=1;i<=s1.length();i++){
    for(int j=1;j<=s2.length();j++){
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]); //문자 다르면, 왼쪽 혹은 위쪽 중 큰 것으로 업데이트
      if(s1[i-1]== s2[j-1]) dp[i][j]=dp[i-1][j-1]+1; //해당 문자면, 좌측 위 대각선 + 1
    }
  }
  cout << dp[s1.length()][s2.length()]; // dp 자체가 계속 누적 업데이트 되므로, 가장 마지막 글자끼리 비교한 것이 정답
  return 0;
}
