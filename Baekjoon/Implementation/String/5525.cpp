#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, M, res=0; //res는 초기화 안해주면 틀림
  string input;
  cin >> N >> M >> input;
  for(int i=1;i<input.size();i++){
    int count=0;
    if(input[i-1]=='I'){
      while(input[i]=='O' && input[i+1]=='I'){
        i+=2;
        ++count;
        if(count==N){
          --count;
          ++res;
        }
      }
    }
  }
  cout << res;
  return 0;
}