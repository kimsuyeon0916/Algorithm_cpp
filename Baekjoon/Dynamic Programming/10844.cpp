#include <iostream>
#define MOD 1000000000
using namespace std;

int dp[101][10]={0,}; //전체 0으로 초기화(쓰레기 값 방지)

int main(){
  int n; cin >> n;

  for(int i=1;i<=n;i++){
    for(int j=0;j<=9;j++){
      if(i==1 && j!=0) dp[i][j]=1; //boundary condition
      else{
        if(j!=0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
        if(j!=9) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%MOD;
      }
    }
  }

  int result=0; //초기화 안해주면 에러
  for(long i=0;i<=9;i++) result=(result+dp[n][i])%MOD;
  cout << result;

  return 0;
}
