#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int n = scoville.size(), count = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(-scoville[i]);
    }
    
    int t = -pq.top();
    int t_next, new_sco;
    while(t < K && pq.size() >= 2) {
        pq.pop();
        t_next = -pq.top();
        pq.pop();
        new_sco = t + (t_next * 2);
        pq.push(-new_sco);
        t = -pq.top();
        count++;
    }
    
    if (pq.size() < 2 && -pq.top() < K) {
        count = -1;
    }
    
    return count;
}
