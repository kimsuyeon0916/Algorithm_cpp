#include <iostream>

using namespace std;

int dp[1001];

int main(){
  int n; cin >> n;
  
  dp[1]=1; dp[2]=2; //boundary condition
  for(int i=3;i<=1000;i++) dp[i]=((1*dp[i-1])+(1*dp[i-2]))%10007; //dp[i-2]에서 dp[i-1]랑 겹치는거 제외한 경우
  
  cout << dp[n];
  return 0;
}