#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s, int N);

int main(){
  int s; int n;
  cin >> s >> n;
  
  cout << solution(to_string(s),n);

  return 0;
}

int solution(string s, int N) {
    int answer = 0;
    int sLength = s.length();
    for (int i = 0; i <= sLength - N; i++) {
        vector<int> used(N);
        vector<int> check(N, 1);
        string sub = s.substr(i, N);
        int subLength = sub.length();
        for (int j = 0; j < subLength; j++) {
            int digit = sub[j] - '0';
            if (digit >= 1 && digit <= N)
                used[digit - 1] = 1;
        }
        if (equal(used.begin(), used.end(), check.begin()))
            answer = max(answer, stoi(sub));
    }
    if(answer==0) answer=-1;
    return answer;
}


// int solution(string s, int N) {
//     int answer = 0;
//     for(int i=0;i<=s.length()-N;i++){
//         vector<int> used(N); vector<int> check(N,1); 
//         string sub = s.substr(i,N);
//         for(int j=0;j<N;j++){
//             if(stoi(sub.substr(j,1))>=1 && stoi(sub.substr(j,1))<=N)
//               used[stoi(sub.substr(j,1))-1]=1;
//         }
//         if(equal(used.begin(),used.end(),check.begin())) answer=max(answer,stoi(sub));
//     }
//     if(answer==0) answer=-1;
//     return answer;
// }






