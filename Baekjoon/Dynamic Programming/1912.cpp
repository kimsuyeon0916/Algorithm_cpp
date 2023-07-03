#include <iostream>
#include <algorithm>

using namespace std;

long long input[100001]; long long dp[100001]={0,};

int main(){
  int n; cin >> n;
  for(int i=1;i<=n;i++) cin >> input[i];

  long long result=-1000;
  for(int i=1;i<=n;i++){
    dp[i]=max(input[i], dp[i-1]+input[i]);
    result=max(result, dp[i]);
  }

  cout << result;
  return 0;
}