#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int T; cin >> T;
  for(int i=1;i<=T;i++){
    int K; cin >> K;
    vector<int> v(K);
    int res=0;
    for(int j=0;j<K;j++) cin >> v[j];
    for(int i=0;i<K-1;i++){
      sort(v.rbegin(), v.rend()); //내림차순 정렬
      int s = v[K-1-i]+v[K-2-i]; 
      v.pop_back(); v.pop_back(); //제일 작은 원소 2개 빼고
      v.emplace_back(s); //합한 값을 원소로 넣기
      res+=s; //파일 합치는 비용 누적
      cout << s << ' ';
    }
    cout << "\n결과: " << res << '\n';
  }
  return 0;
}
/*
모든 장을 합치는데 필요한 최소비용 => 최솟값 누적하면서 업데이트

과정에 필요한 것들을 더함 => 필요 횟수 = 파일 개수 -1


40 30 30 50

30 + 30 = 60 => 60 40 50
40 + 50 = 90 => 60 90
60 + 90 => 150 

1 3 3 4 4 5 5 5 14 17 21 21 32 35 98

1 3 3 4
1 + 3 = 4
3 + 4 = 7
4 + 7 = 11

1 + 3 = 4
3 + 4 = 7
4 + 7 = 11


=> 더하고 정렬한 뒤, 작은 것을 더해 나가면서 누적

테케 맞지 X => 이 임시파일이나 원래의 파일을 계속 두 개씩 합쳐서 소설의 여러 장들이 "연속"이 되도록 파일을 합쳐나가고, 최종적으로는 하나의 파일로 합친다.
  => 정렬 하면 X. 완전 접근 잘못함....
  
40분 초과
*/