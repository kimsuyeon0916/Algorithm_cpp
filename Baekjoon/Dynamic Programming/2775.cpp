#include <iostream>
#define MAX_INPUT 1000000

using namespace std;

int dp[15][15];
int input[MAX_INPUT][2];

int main(){
  int n;
  cin >> n;
  for(int t=0;t<n;t++) cin >> input[t][0] >> input[t][1];

  for(int i=0;i<=14;i++){
    for(int j=1;j<=14;j++){
      if(i==0) dp[i][j]=j;
      else dp[i][j]=dp[i][j-1]+dp[i-1][j];
    }
  }

  for(int t=0;t<n;t++) cout << dp[input[t][0]][input[t][1]] << endl;

  return 0;
}