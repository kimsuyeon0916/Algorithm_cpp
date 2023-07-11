#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int dp[1000001]={0,};
string num[1000001];
int main(){
  FASTIO;
  int n; cin >> n;

  num[1]="1"; //boundary condition
  for(int i=2;i<=n;i++){
    string x=to_string(i);
    dp[i]=dp[i-1]+1;
    num[i] = to_string(i) + " " + num[i-1];
    if(i%2==0){
      dp[i]=min(dp[i],dp[i/2]+1);
      if(dp[i]==dp[i/2]+1)  num[i] = to_string(i) + " " + num[i/2];
    } 
    if(i%3==0){
      dp[i]=min(dp[i],dp[i/3]+1);
      if(dp[i]==dp[i/3]+1)  num[i] = to_string(i) + " " + num[i/3];
    } 
    
  }
  cout << dp[n] << '\n' << num[n];

  return 0;
}
