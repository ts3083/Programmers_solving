#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    int dp[1001][1001] = {0,};
    vector<int> sum_arr(n);
    vector<int> count(n);
    int sum = 0;
    
    for(int i = 0; i < report.size(); i++) {
        string f, s;
        int x, y;
        f = report[i].substr(0, report[i].find(" "));
        s = report[i].substr(report[i].find(" ") + 1, report[i].length());
        
        for (x = 0; x < n; x++) {
            if (id_list[x].compare(f) == 0)
                break;
        }
        for (y = 0; y < n; y++) {
            if (id_list[y].compare(s) == 0)
                break;
        }
        dp[x][y] = 1;
    }
    
    for (int j = 0; j < n; j++) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += dp[i][j];
        }
        sum_arr[j] = sum;
    }
    
    for (int j = 0; j < n; j++) {
        if (sum_arr[j] >= k) {
            for (int i = 0; i < n; i++) {
                if (dp[i][j] == 1) {
                    count[i]++;
                }
            }
        }
    }
    
    vector<int> answer = count;
    return answer;
}
