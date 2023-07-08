#include <iostream>
#include <algorithm>
using namespace std;

void init(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int input[100];
int main(){
  init();
  int n, m; cin >> n >> m;
  for(int i=0;i<n;i++) cin >> input[i];

  int result=input[0];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        if((i!=j && j!=k && k!=i) && m-(input[i]+input[j]+input[k])>=0) 
          result = m-min(m-result,m-(input[i]+input[j]+input[k]));
      }
    }
  }

  cout << result;
  return 0;
}
