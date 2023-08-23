#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int N, M;
int arr[8], res[8];
bool visited[8];

void BackTracking(int depth, int idx){
  if(depth==M){
    for(int i=0;i<M;i++) cout << res[i] << ' ';
    cout << '\n';
    return;
  }
  int prev=0; //이전에 들어온 수(중복 방지)
  for(int i=idx;i<N;i++){
    if(prev!=arr[i]){ //입력으로 들어오는 수가 같을 수 있고, 중복 되는 수열 거르기 위함!
      prev=arr[i];
      res[depth]=arr[i];
      BackTracking(depth+1, i);
    }
  }
}

int main()
{
  FASTIO;
  cin >> N >> M;
  for(int i=0;i<N;i++) cin >> arr[i];
  sort(arr, arr+N); //입력 배열 정렬
  BackTracking(0,0);
  return 0;
}