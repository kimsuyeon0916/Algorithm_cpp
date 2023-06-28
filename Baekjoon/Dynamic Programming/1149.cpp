#include <iostream>
#include <algorithm>
#define MAX_COST 1000
using namespace std;

int dp[1001][3]={0,};
int input[1001][3];
int main(){
  int n; cin >> n;
  for(int t=1;t<=n;t++) cin >> input[t][0] >> input[t][1] >> input[t][2];

  int result;
  for(int t=1;t<=n;t++){
    result = t * MAX_COST;
    for(int j=0;j<3;j++){
      if(j==0) dp[t][j]=input[t][j]+min(dp[t-1][1],dp[t-1][2]);
      else if(j==1) dp[t][j]=input[t][j]+min(dp[t-1][0],dp[t-1][2]);
      else dp[t][j]=input[t][j]+min(dp[t-1][0],dp[t-1][1]);
      result=min(result, dp[t][j]);
    }
  }
  
  cout << result;
  return 0;
}

