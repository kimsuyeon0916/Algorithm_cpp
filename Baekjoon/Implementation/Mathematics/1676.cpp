#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  int result=0;
  for(int i=N;i>=1;i--){
    int num=i;
    while(num%5==0){
      result++;
      num/=5; 
    }
  }
  cout << result;
  return 0;
}