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
  for(int i=0;i<N;i++) cin >> v[i];
  sort(v.begin(),v.end());
  int M; cin >> M;
  for(int i=0;i<M;i++){
    int input,res=0; cin >> input;
    int low=0, high=N-1; //while 바로 위에 있어야 하는게 맞음!
    while(low<=high){
      int mid=(low+high)/2; //소괄호 필수 & while문 안에
      if(input==v[mid]){
        res=1;
        break;
      } 
      else if(input>v[mid]) low=mid+1;
      else high=mid-1;
    }
    cout << res <<'\n';
    //cout << binary_search(v.begin(), v.end(), input) << '\n'; //STL 사용
  }
  return 0;
}