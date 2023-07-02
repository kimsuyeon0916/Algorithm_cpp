#include <iostream>
#include <algorithm>
#define MAX_INPUT 1000000

using namespace std;

int input[MAX_INPUT]; //0 ~ 40

int main(){
  int n;
  cin >> n;
  for(int t=0;t<n;t++) cin >> input[t];

  int dp[2][41];

  dp[0][0]=1; dp[1][0]=0; //boudary conditions
  dp[0][1]=0; dp[1][1]=1;
  for(int t=0;t<n;t++){ 
    if(input[t]>=2){
      for(int i=2;i<=input[t];i++){
        dp[0][i] = dp[0][i-1] + dp[0][i-2];
        dp[1][i] = dp[1][i-1] + dp[1][i-2];
      }
    } 
    cout << dp[0][input[t]] << " " << dp[1][input[t]] << endl;
  }
  return 0;
}