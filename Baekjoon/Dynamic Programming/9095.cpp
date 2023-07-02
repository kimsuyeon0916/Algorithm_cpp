#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n; int input[10];
  cin >> n; //테스트 케이스 개수
  for(int t=0;t<n;t++) cin >> input[t];
  
  int dp[11];

  dp[0] = 1; //boundary condition
  for(int t=0;t<n;t++){
    for(int i=1;i<=input[t];i++){
      dp[i] = dp[i-1];
      if(i>=2) dp[i]+=dp[i-2];
      if(i>=3) dp[i]+=dp[i-3];
    }
    cout << dp[input[t]] << endl;
  }
  
  return 0;
}