#include <iostream>

using namespace std;

int input[501][501];
long long dp[501][501]={0,};

int main(){
  int n; cin >> n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++) cin >> input[i][j];
  }

  dp[1][1]=input[1][1]; //boundary condition
  long long result=dp[1][1];
  for(int i=2;i<=n;i++){
    for(int j=1;j<=i;j++){
      dp[i][j]=input[i][j];
      if(j>1) dp[i][j]=max(dp[i][j],input[i][j]+dp[i-1][j-1]);
      if(j<i) dp[i][j]=max(dp[i][j],input[i][j]+dp[i-1][j]);
      result=max(result,dp[i][j]);
    }
  }

  cout << result;
  return 0;
}