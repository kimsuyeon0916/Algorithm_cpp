#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int N;
string board[200][200];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int dist[200][200];
map<char,int> allow={{'U', 0},{'D', 1},{'L', 2},{'R', 3}}; //상하좌우
int Gres=0, Pres=0, res=0;

void DFS(int x, int y){
	if(dist[x][y]) return;
	else{
		++res;
		dist[x][y]=res;
		int idx=allow[(board[x][y])[1]];
		int cnt=(board[x][y])[0]-'0';
		int nx=(x + cnt*dx[idx])%N, ny=(y + cnt*dy[idx])%N;
		cout << '[' <<board[x][y] << ']' << ' ' << nx << ' ' << ny << '\n';
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
			cout << '[' << board[i][j] << ']';
		}
	}
	cout << '\n';
	DFS(G_R-1,G_C-1); Gres=res; 
	cout << Gres << ' ';
	res=0; fill_n(&dist[0][0],200*200,0);
	DFS(P_R-1,P_C-1); Pres=res;
	cout << Pres << ' ';
	if(Gres>Pres) cout<< "goorm" << ' ' << Gres;
	else cout << "player" << ' ' << Pres;
  return 0;
}