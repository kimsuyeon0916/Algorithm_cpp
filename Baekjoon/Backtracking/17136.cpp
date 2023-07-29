#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

int cnt=0, min_cnt = 26;
bool paper[10][10];
vector<pair<int, int>> v;
int pcnt[5] = {5,5,5,5,5};

bool promising(int idx, int size) {
  for (int i = v[idx].first; i < v[idx].first + size; i++) {
    for (int j = v[idx].second; j < v[idx].second + size; j++) {
      if (i >= 10 || j >= 10 || !paper[i][j]) return false;
      paper[i][j]=0;
    }
  }
  return true;
}

void Backtracking(int idx) {
  if (idx == v.size()) {
    min_cnt = min(min_cnt, cnt);
    return;
  } 
  if(cnt>=min_cnt) return;
  bool p[10][10]; //지역 변수로 저장
	copy(&paper[0][0], &paper[0][0]+100, &p[0][0]); 
  if (paper[v[idx].first][v[idx].second]) {
    for (int i = 5; i >= 1; i--) {
      if (pcnt[i - 1] > 0 && promising(idx, i)) {
        ++cnt; 
        --pcnt[i - 1];
        Backtracking(idx + 1);
        ++pcnt[i - 1];
        --cnt;
      }
			copy(&p[0][0], &p[0][0]+100, &paper[0][0]); //원복
    }
  } 
  else Backtracking(idx + 1);
}

int main() {
  FASTIO;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> paper[i][j];
      if (paper[i][j]) v.emplace_back(make_pair(i, j));
    }
  }
  Backtracking(0);
  cout << (min_cnt == 26 ? -1 : min_cnt);
  return 0;
}