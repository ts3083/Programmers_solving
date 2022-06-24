#include <string>
#include <vector>

using namespace std;

int bepo = 0;
int now_prog = 0;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = speeds.size();
    vector<bool> visited(n, false);
    while (bepo < n) {
        for (int i = 0; i < n; i++) {
            if (visited[i] == true)
                continue;
            progresses[i] += speeds[i];
            if (progresses[i] >= 100) {
                visited[i] = true;
            }
        }
        
        while (visited[bepo] == true) {
            bepo++;
            if (bepo >= n)
                break;
        }
        if (bepo == now_prog)
            continue;
        int function_num = bepo - now_prog;
        answer.push_back(function_num);
        now_prog = bepo;
    }
    
    return answer;
}
