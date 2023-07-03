#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> input; vector<int> v(3);
vector<int> EOI = {-1,-1,-1};
long long dp[101][101][101];

int main(){
  while(true){
    cin >> v[0] >> v[1] >> v[2];
    if(v == EOI) break;
    else input.push_back(v);
  }
  
  dp[70][70][70]=1048576; //boundary condition
  for(long long i=0;i<=100;i++){
    for(long long j=0;j<=100;j++){
      for(long long k=0;k<=100;k++){
        if(i<=50||j<=50||k<=50) dp[i][j][k]=1;
        else if(i>70||j>70||k>70) dp[i][j][k]=dp[70][70][70];
        else if(i<j && j<k) dp[i][j][k]=dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k]; 
        else dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1]; 
      }
    }
  }

  for(int i=0;i<input.size();i++){
    cout << "w(" << input[i][0] << ", " << input[i][1] << ", " << input[i][2] << ") = ";
    cout << dp[input[i][0]+50][input[i][1]+50][input[i][2]+50] << endl;
  } 
  return 0;
}