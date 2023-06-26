#include <iostream>
#define MAX_INPUT 1000000

using namespace std;

int dp[MAX_INPUT+1];

int main(){
  int n;
  
  cin >> n;

  //1->n 최소 연산 횟수로 만드는 걸로 생각
  dp[1]=0; //boudary condition
  for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+1;
    if(i%2==0) dp[i] = min(dp[i], dp[i/2] + 1);
    if(i%3==0) dp[i] = min(dp[i], dp[i/3] + 1);  
  }
  cout << dp[n];

  return 0;
}