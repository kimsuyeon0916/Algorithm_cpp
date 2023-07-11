#include <iostream>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int dp[1001][2]={0,};
int input[1001];

int main(){
  FASTIO;
  int n; cin >> n;
  for(int i=1;i<=n;i++) cin >> input[i];

  int plus=1; //순방향 증가 수열
  for(int i=1;i<=n;i++){
    dp[i][0]=1; //boundary condition
    for(int j=1;j<i;j++){
      if(input[i]>input[j]) dp[i][0]=max(dp[i][0],dp[j][0]+1);
    }
    plus=max(dp[i][0],plus);
  }

  int minus=1; //역방향 증가 수열
  for(int i=n;i>=1;i--){
    dp[i][1]=1; //boundary condition
    for(int j=n;j>i;j--){
      if(input[i]>input[j]) dp[i][1]=max(dp[i][1],dp[j][1]+1);
    }
    minus=max(dp[i][1],minus);
  }

  int result=1; //순방향 증가 수열 + 역방향 증가 수열
  for(int i = 1; i<=n; i++){
		result = max(result, dp[i][0] + dp[i][1] -1);
	}
  cout << result;
  return 0;
}