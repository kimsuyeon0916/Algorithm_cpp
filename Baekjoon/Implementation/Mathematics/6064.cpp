#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int T; cin >> T;
  for(int i=1;i<=T;i++){ //각 테스트 데이터에 대해, 정수 k를 한 줄에 출력한다
    int M, N, x, y;
    cin >> M >> N >> x >> y;

    int LCM, n=1;
    while(n<=N){ //최소 공배수 구하기
      if((M*n) % N == 0){
        LCM=M*n;
        break;
      } 
      ++n;
    }
    
    int k=0, res=-1; //k를 1->0 바꾸니 맞음(이유: M을 한바퀴 이상 안돌리는 경우 빼먹음)
    while(M*k+x<=LCM){ 
      if((M*k+x-y)%N==0){
        res=M*k+x;
        break;
      } 
      ++k;
    }

    cout << res << '\n';
  }
  return 0;
}