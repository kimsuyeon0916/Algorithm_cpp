#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int T; cin >> T;
  for(int i=0;i<T;i++){
    int N, A, B; cin >> N >> A >> B;
    int res, ans=0;
    for(int i=0;i<=N/min(A,B);i++){
      if((N-(min(A,B)*i))%max(A,B)==0){
        res=i+((N-(min(A,B)*i))/max(A,B));
        ans=max(ans,res);
      }
    }
    cout << "Case #" << i+1 << '\n' << ans << '\n';
  }
  return 0;
}