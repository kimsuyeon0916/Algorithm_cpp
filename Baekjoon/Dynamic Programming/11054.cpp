#include <iostream>

using namespace std;

void init(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int dp[1001][3]={0,};
int input[1001];

int main(){
  init();
  int n; cin >> n;
  for(int i=1;i<=n;i++) cin >> input[i];

  int result=0;
  dp[1][0]=1; dp[1][1]=1; dp[1][2]=1; //boundary condition
  for(int i=1;i<=n;i++){
    for(int j=1;j<i;j++){
      if(input[i]>input[j]) dp[i][0]=max(dp[i][0],dp[j][0]+1);
      if(input[i]<input[j]){
        dp[i][1]=max(dp[i][1],dp[j][1]+1);
        dp[i][2]=max(dp[i][2],(dp[j][0]+(dp[i][1]-dp[j][1])));
      } 
    }
    result=max(max(dp[i][0],dp[i][1]),max(dp[i][2],result));
    cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
  }

  cout << result;
  return 0;
}

//이 풀이는 안됨