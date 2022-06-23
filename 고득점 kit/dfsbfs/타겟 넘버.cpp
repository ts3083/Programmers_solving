#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0, f, now_num, size;
    int n = numbers.size();
    
    queue<int> q;
    q.push(numbers[0]);
    q.push(-numbers[0]);
    for (int i = 1; i < n; i++) {
        now_num = numbers[i]; 
        size = q.size();
        for (int j = 0; j < size; j++) {
            f = q.front();
            q.pop();
            q.push(f + now_num);
            q.push(f - now_num);
        }
    }
    
    while(!q.empty()) {
        f = q.front();
        q.pop();
        if (f == target)
            answer++;
    }    
    
    return answer;
}
