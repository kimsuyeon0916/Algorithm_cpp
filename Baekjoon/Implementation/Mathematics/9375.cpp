#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int T; cin >> T;
  for(int i=1;i<=T;i++){
    int n; cin >> n;
    map<string, int> m; //각 종류 별 옷 개수 저장 (나중에 수식 계산 위함)
    set<string> s; //각 종류 (중복되지 않게 타입 개수 세기 위함)
    for(int i=1;i<=n;i++){
      string cloth, type;
      cin >> cloth >> type;
      ++m[type];
      s.emplace(type);
    }
    int cnt = 1;
    for(string type : s) cnt*=(m[type]+1); //각각의 종류 집합에서 원소를 고를 경우의 수 - 공집합
    cout << cnt-1 << '\n';
  }
  return 0;
}
