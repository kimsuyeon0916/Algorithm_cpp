#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  vector<int> tree;
  for(int i=0;i<N;i++){
    int x; cin >> x;
    tree.emplace_back(x);
  } 
  sort(tree.begin(), tree.end()); //미리 정렬
  long long res=0;
  int low=0, high=tree[N-1]; //low를 tree[0]->0으로 바꾸니까 맞음
  while(low<=high){
    long long mid=(low+high)/2; //합치면 int 넘을 수 있음
    long long sum=0; //여기도 long long
    for(int i=0;i<N;i++){
      if(tree[i]>mid) sum+=tree[i]-mid;
    }
    if(M<=sum){ 
      low=mid+1; //높이 크게 지정 => sum 작아짐
      res=max(res,mid); //계속 갱신 시켜주는 방식(max 아니어도, 이 조건 마지막으로 통과하는 값이 최대 res)
    } 
    else high=mid-1; //높이 낮게 지정 => sum 커짐
  }
  cout << res;
  return 0;
}
