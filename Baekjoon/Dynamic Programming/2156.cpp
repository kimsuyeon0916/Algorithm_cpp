#include <iostream>

using namespace std;

int input[10001];
long long dp[10001][3]={0,};

int main(){
  int n; cin >> n;
  for(int i=1;i<=n;i++) cin >> input[i];

  long long result=0;
  dp[1][0]=input[1]; dp[2][0]=input[2]+dp[1][0]; dp[2][1]=input[2]; //boudary condition
  for(int i=1;i<=n;i++){
    if(i>=3){
      dp[i][0]= input[i]+ max(max(dp[i-1][0], dp[i-1][1]), input[i]+dp[i-1][2]);
      if(dp[i-1][0]==input[i-1]+dp[i-2][0] || dp[i-1][0]==input[i-1]+dp[i-2][1] || dp[i-1][0]==input[i-1]+dp[i-2][2])
      dp[i][0]=input[i]+max(dp[i-1][1],dp[i-1][2]);
      dp[i][1]= input[i]+max(max(dp[i-2][0],dp[i-2][1]),dp[i-2][2]);
      dp[i][2]= input[i]+max(max(dp[i-3][0],dp[i-3][1]),dp[i-3][2]);
    }
    result=max(result, max(max(dp[i][0], dp[i][1]),dp[i][2]));
  }

  cout << result;
  return 0;
}