#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int M, N; cin >> M >> N;
  for(int i=M;i<=N;i++){
    if(i==1) continue; //1이 입력으로 들어올 수 있음
    int prime=1;
    for(int j=2;j<=sqrt(i);j++){ //등호 들어가야 함
      if(i%j==0){
        prime=0;
        break;
      }
    }
    if(prime) cout << i << '\n';
  }
  return 0;
}