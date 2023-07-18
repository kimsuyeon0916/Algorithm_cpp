#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//계수 정렬(Counting Sort)
//:원소들간 비교 없이 정렬을 할 수 있는 알고리즘이다
//음수, 소수에는 불가능,수의 범위가 상대적으로 작은 경우에 유용한 정렬)
vector<int> v(10001);
int main()
{
  FASTIO;
  int N; cin >> N; 
  int input;
  for(int i=1;i<=N;i++){
    cin >> input;
    v[input]++;
  } 
  for(int i=1;i<=10000;i++){
    for(int j=0;j<v[i];j++){
      cout << i << '\n';
    }
  }  
  return 0;
}