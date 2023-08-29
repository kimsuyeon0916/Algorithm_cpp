#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int N;
string board[200][200];
int dx[4]={-1,1,0,0}; //상하좌우 로 움직일 때 좌표 변화
int dy[4]={0,0,-1,1};
bool visited[200][200];
map<char,int> allow={{'U', 0},{'D', 1},{'L', 2},{'R', 3}}; //상하좌우
int Gres=0, Pres=0, res=0;

void DFS(int x, int y){
	if(visited[x][y]) return;
	else{
		int idx=allow[(board[x][y].substr(board[x][y].size()-1))[0]];
		int cnt=stoi((board[x][y]).substr(0,board[x][y].size()-1));
		int nx=(x + cnt*dx[idx])<0 ? N-(abs(x + cnt*dx[idx])%N) : (x + cnt*dx[idx])%N;
    int ny=(y + cnt*dy[idx])<0 ? N-(abs(y + cnt*dy[idx])%N) : (y + cnt*dy[idx])%N;
    int mov=0;
    while(mov<cnt){
      if(visited[x][y]) return;
      visited[x][y]=true;
      ++res;
      ++mov;
      x+dx[idx]<0 ? x=N-1 : (x+dx[idx]>=N ? x=0 : x+=dx[idx]);
      y+dy[idx]<0 ? y=N-1 : (y+dy[idx]>=N ? y=0 : y+=dy[idx]);
    }
    DFS(nx,ny);
	}
}

int main()
{
  FASTIO;
	cin >> N;
	int G_R, G_C, P_R, P_C; cin >> G_R >> G_C >> P_R >> P_C;
	string input;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> board[i][j];
		}
	}
	DFS(G_R-1,G_C-1); Gres=res; 
	res=0; fill_n(&visited[0][0],200*200,0);
	DFS(P_R-1,P_C-1); Pres=res;
	if(Gres>Pres) cout<< "goorm" << ' ' << Gres;
	else cout << "player" << ' ' << Pres;
  return 0;
}