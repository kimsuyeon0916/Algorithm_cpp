#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, M, res=0; 
  string input;
  cin >> N >> M >> input;
  for(int i=1;i<input.size();i++){
    int count=0; //IOI의 개수
    if(input[i-1]=='I'){
      while(input[i]=='O' && input[i+1]=='I'){
        i+=2; //인덱스 뛰어 넘기
        ++count;
        if(count==N){
          --count; //오른쪽으로 +2만큼 이동할텐데 이때 k값이 바뀌지 않게 하나 빼줌
          ++res;
        }
      }
    }
  }
  cout << res;
  return 0;
}