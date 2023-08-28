#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

int T;
int main()
{
  FASTIO;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> cell(N, vector<int>(M));
    vector<int> column(N);
    vector<int> row(M);
    for (int i = 0; i < N; i++){
      int max_row, max_column = 0;
      for (int j = 0; j < M; j++){
        cin >> cell[i][j];
        if (cell[i][j] > cell[i][column[i]]) column[i] = j;
        if (cell[i][j] > cell[row[j]][j]) row[j] = i;
      }
    }

    int sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++){
      if (row[column[i]] == i) count++;
    }

    int x, y, z;
    for (int i = 0; i < Q; i++){
      cin >> x >> y >> z;
      cell[x - 1][y - 1] = z;
      if (row[y - 1] == x - 1 && column[x - 1] == y - 1){
        sum += count;
        continue;
      }
      if (z > cell[x - 1][column[x - 1]]){
        if (row[column[x - 1]] == x - 1) count--;
        column[x - 1] = y - 1;
      }
      if (z > cell[row[y - 1]][y - 1]){
        if (column[row[y - 1]] == y - 1) count--;
        row[y - 1] = x - 1;
      }
      if (row[y - 1] == x - 1 && column[x - 1] == y - 1) count++;
      
      sum += count;
    }
    cout << "#" << t << " " << sum << '\n';
  }
  return 0;
}