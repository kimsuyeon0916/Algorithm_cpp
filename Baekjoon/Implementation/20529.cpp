#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

string mbti[100000];
int main()
{
  FASTIO;
  int T; cin >> T;
  for(int t=1;t<=T;t++){
    int N; cin >> N;
    for(int i=0;i<N;i++) cin >> mbti[i];

    int min_dist=12;
    vector<int> dist;
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        for(int s=j+1;s<N;s++){
          int dist=0;
          for(int k=0;k<4;k++){
            if(mbti[i].substr(k,1)!=mbti[j].substr(k,1)) dist++;
            if(mbti[j].substr(k,1)!=mbti[s].substr(k,1)) dist++;
            if(mbti[s].substr(k,1)!=mbti[i].substr(k,1)) dist++;
          }
          min_dist=min(min_dist,dist);
          if(min_dist==0) break; //종료 조건만 추가했더니 바로 통과됨..
        }
        if(min_dist==0) break;
      }
      if(min_dist==0) break;
    }

    cout << min_dist << '\n';
  }  
  return 0;
}