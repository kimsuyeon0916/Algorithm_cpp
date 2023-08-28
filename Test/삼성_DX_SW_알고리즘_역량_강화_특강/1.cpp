#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define INF 98765432
using namespace std;

int T;
int main()
{
    FASTIO;
    int t;
    cin >> T;
    for (t = 1; t <= T; t++)
    {

        int N, M;
        cin >> N >> M;
        vector<vector<int>> manito(N, vector<int>(N, 0));

        for (int i = 0; i < M; i++)
        {
            int X, Y, C;
            cin >> X >> Y >> C;
            manito[X - 1][Y - 1] = C;
        }

        for (int k = 0; k < N; k++){
            for (int i = 0; i < N && i != k; i++){
                for (int j = 0; j < N && j != k && j != i; j++){
                    if (manito[i][k] != 0 && manito[k][j] != 0){
                        if (manito[i][j] == 0) manito[i][j] = manito[i][k] + manito[k][j];
                        else manito[i][j] = min(manito[i][j], manito[i][k] + manito[k][j]);
                    }
                }
            }
        }

        int minCost = INF;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (manito[i][j] != 0 && manito[j][i] != 0){
                    int cost = manito[i][j] + manito[j][i];
                    if (i == j) cost /= 2;
                    minCost = min(minCost, cost);
                }
            }
        }
        cout << "#" << t << " " << (minCost == INF ? -1 : minCost) << "\n";
    }
    return 0;
}