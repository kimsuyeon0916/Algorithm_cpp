#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  vector<int> v(N);
  for(int &n:v) cin >> n; //값의 수정이 일어날 때는, range based for로 적으려면 & 붙여야 함

  int prime_count=N;
  for(int n:v){
    if(n==1) prime_count--;
    for(int i=2;i<n;i++){
      if(n%i==0){
        prime_count--;
        break;
      }
    }
  }
  cout << prime_count;
  return 0;
}