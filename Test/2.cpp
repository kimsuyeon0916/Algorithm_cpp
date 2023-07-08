#include <string>
#include <vector>

using namespace std;
int criteria=-1; int Old=0; int New=0;
int solution(vector<vector<int>> relationships, int target, int limit) {
    int answer = 0; 
    for(int i=0;i<relationships.size();i++){
        if(limit==0) return 0;
        else{
            if(relationships[i][0]==target){
                if(criteria==-1) Old++;
                else New++;
                relationships.erase(relationships.begin()+i); // 범위는 [first,last)
                solution(relationships,relationships[i][1],limit-1);
                criteria++;
            } 
            else if(relationships[i][1]==target){
                if(criteria==-1) Old++;
                else New++;
                relationships.erase(relationships.begin()+i); // 범위는 [first,last)
                solution(relationships,relationships[i][0],limit-1);
                criteria++;
            }
        } 
    }
    answer=Old*5+New*10+New;
    return answer;
}