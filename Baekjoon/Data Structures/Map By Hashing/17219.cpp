#include <iostream>
#include <map>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  map<string, string> m;
  string addr, pw;
  for(int i=1;i<=N;i++){
    cin >> addr >> pw;
    m[addr]=pw;
  }
  for(int i=1;i<=M;i++){
    cin >> addr;
    cout << m[addr] <<'\n';
  }
  return 0;
}