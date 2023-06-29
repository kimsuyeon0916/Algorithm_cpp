#include <iostream>
#include <algorithm>

using namespace std;

int dp[301][2]={0,}; int input[301];

int main(){
  int n; cin >> n;
  for(int i=1;i<=n;i++) cin >> input[i];

  int result=0; dp[0][0]=0; dp[0][1]=0; dp[1][0]=input[1]; dp[1][1]=input[1]; dp[2][0]=input[1]+input[2]; dp[2][1]=input[2];
  for(int i=3;i<=n;i++){
    int k=0;
    for(int j=0;j<2;j++){
      if(i>=3 && (dp[i-3][j]+input[i-2]+input[i-1]!=dp[i-1][0] || dp[i-3][j]+input[i-2]+input[i-1]!=dp[i-1][1])){
        dp[i][0]=input[i]+max(dp[i-1][0],dp[i-1][1]);
      }
      k=max(k,dp[i][0]);
    }
    dp[i][0]=k;
    dp[i][1]=input[i]+max(dp[i-2][0],dp[i-2][1]);
    result=max(dp[i][0],dp[i][1]);
    cout << dp[i][0] << " " << dp[i][1] << endl;
  }

  cout << result;
  return 0;
}
