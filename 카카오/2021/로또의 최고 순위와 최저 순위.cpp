#include <string>
#include <vector>

using namespace std;

vector<int> ranked(int num, int win) { // num은 0의 개수, win은 일치하는 숫자
    int ranking = 7 - win;
    if (ranking > 6)
        ranking = 6;
    int max_rank = ranking - num;
    if (max_rank < 1)
        max_rank = 1;
    
    vector<int> result = {max_rank, ranking};
    return result;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count = 0, zero = 0;
    for (int i = 0; i < 6; i++) {
        int now = lottos[i];
        if (now == 0) {
            zero++;
            continue;
        }
        for (int j = 0; j < 6; j++) {
            if (now == win_nums[j]) {
                count++;
                break;
            }
        }
    }
    answer = ranked(zero, count);
    
    return answer;
}
