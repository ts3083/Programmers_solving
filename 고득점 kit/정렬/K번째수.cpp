#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int count = 0; count < commands.size(); count++) {
        vector<int> temp;
        int i = commands[count][0];
        int j = commands[count][1];
        int k = commands[count][2];
        for (int h = i - 1; h < j; h++) {
            temp.push_back(array[h]);
        }
        sort(temp.begin(), temp.end());
        int result = temp[k - 1];
        answer.push_back(result);
    }    
    
    return answer;
}
