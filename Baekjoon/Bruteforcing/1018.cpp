#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

char board[50][50];
//vector<string> chess = {"WBWBWBWB","BWBWBWBW"};
string chess1="WBWBWBWB";
string chess2="BWBWBWBW";
int main()
{
  FASTIO;
  int N, M;
  cin >> N >> M;
  string input; 
  for(int i=0;i<N;i++){
    cin >> input;
    for(int j=0;j<M;j++){
      board[i][j] = input[j];
    }
  }

  int count1, count2;
  int result=64;
  for(int i=0;i<N-7;i++){
    for(int j=0;j<M-7;j++){
      count1=0;
      count2=0;
      for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){		
          if (board[i + x][j + y]!=chess1[y]) count1++; //bw
          if (board[i + x][j + y]!=chess2[y]) count2++; //wb  
        }
				chess1.swap(chess2);
      }
      result=min(result,min(count1,count2));
    }
  }
  cout << result;
  return 0;
}