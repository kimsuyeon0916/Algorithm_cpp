#include <iostream>

using namespace std;

int input[1001]={0,};
int dp[1001]={0,};
int main(){
  int n; cin >> n;
  for(int i=1;i<=n;i++) cin >> input[i];

  int result = 1;
  for(int i=1;i<=n;i++){
    dp[i]=1; //boudary condition
    for(int j=1;j<i;j++){
      if(input[j]<input[i]) dp[i] = max(dp[j]+1, dp[i]);
    }
    result=max(dp[i],result);
  }
  
  cout << result;
  return 0;
}