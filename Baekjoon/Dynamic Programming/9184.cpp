#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> input; vector<int> v;
vector<int> EOI = {-1,-1,-1};
int dp[1000001];

int main(){
  while(true){
    cin >> v[0] >> v[1] >> v[2];
    if(v == EOI) break;
    else input.push_back(v);
  }
  
  for(int i=0;i<input.size();i++){
    if(input[i][0]<=0||input[i][1]<=0||input[i][2]<=0)
  }
  
   
  return 0;
}

// 15 16 17

// 15 16 16 + 15 15 16 - 15 15 17

// 20 20 20
// 19 20 20 + 19 19 20 + 19 