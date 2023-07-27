#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int board[10][10];
bool num[9];
vector<pair<int,int>> blank;

bool promising(pair<int,int> rc, int i){
  int s_r=((rc.first-1)/3)*3+1;
  int s_c=((rc.second-1)/3)*3+1;
  for(int k=1;k<=9;k++){
    if(board[rc.first][k]==i || board[k][rc.second]==i || board[s_r+(k-1)/3][s_c+(k-1)%3]==i){ //행,열,사각형 체크
      return false;
    } 
  }
  board[rc.first][rc.second]=i;
  return true;
}

void Backtracking(pair<int,int> rc){
  blank.pop_back();
  for(int i=1;i<=9;i++){ //처음에 promising 안에 넣었다가, 그럼 처음 호출한 인자는 백트래킹이 안되서 바꿈
    if(promising(rc,i)){
      if(blank.empty()){ //blank.size()로도 조건 줄 수 있음.
        for(int i=1;i<=9;i++){
          for(int j=1;j<=9;j++) cout << board[i][j] << ' ';
          cout << '\n';
        }
        exit(0); //출력 후 바로 종료
      } 
      pair<int,int> cur=blank.back(); //변수 선언 해놔야함
      Backtracking(cur);  
      blank.emplace_back(cur); //굳이 안빼고, 그냥 벡터 앞부터 뒤까지 인덱스로도 관리 가능
      board[cur.first][cur.second]=0; //아니면 원복
    } 
  }
}

int main()
{
  FASTIO;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      cin >> board[i][j];
      if(!board[i][j]) blank.emplace_back(make_pair(i,j));
    }
  }
  sort(blank.rbegin(),blank.rend());
  Backtracking(blank.back());
  return 0;
}