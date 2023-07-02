#include <iostream>
#include <algorithm>
#define MAX_INPUT 5000

using namespace std;

int dp[MAX_INPUT/3+1][MAX_INPUT+1]; //열을 채울 수 있는 필요한 봉지 총 개수 (행:3KG 봉지 개수, 열:N)

int main()
{
  int n; cin >> n;
  
  int result = MAX_INPUT; 
  for(int i=0;i<=n/3;i++){
    dp[i][3*i]=i; //boundary condition
    for(int j=3*i+1;j<=n;j++){
      dp[i][j]=dp[i][j-1];
      if((j-(3*i))>0 && (j-(3*i))%5==0) dp[i][j]+=1;
    }
    if(n==3*i + 5*(dp[i][n]-i)) result = min(result, dp[i][n]);
  }
  if(result == MAX_INPUT) result=-1;

  cout << result;
  return 0;
}