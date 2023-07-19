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
    for(int i=0;i<N && min_dist!=0;i++){ //min_dist==0; 종료 조건
      for(int j=i+1;j<N && min_dist!=0;j++){
        for(int s=j+1;s<N && min_dist!=0;s++){
          int dist=0;
          for(int k=0;k<4;k++){
            if(mbti[i].substr(k,1)!=mbti[j].substr(k,1)) dist++;
            if(mbti[j].substr(k,1)!=mbti[s].substr(k,1)) dist++;
            if(mbti[s].substr(k,1)!=mbti[i].substr(k,1)) dist++;
          }
          min_dist=min(min_dist,dist);
        }
      }
    }

    cout << min_dist << '\n';
  }  
  return 0;
}