#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int n = participant.size();
    map<string, int> m;
    
    for (int i = 0; i < n; i++) {
        m[participant[i]]++;
    }
    for (int i = 0; i < n - 1; i++) {
        m[completion[i]]--;
    }
    
    for (auto pair : m) {
        if (pair.second > 0) {
            answer = pair.first;
            break;
        }
    }
    
    return answer;
}
