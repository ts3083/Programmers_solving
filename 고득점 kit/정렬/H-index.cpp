#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    
    sort(citations.begin(), citations.end());
    
    int m = citations.back();
    int count = 0;
    for (int i = m; i >= 0; i--) {
        count = 0;
        for (int j = 0; j < size; j++) {
            if (citations[j] >= i) {
                count++;
            }
        }
        if (count >= i) {
            answer = i;
            break;
        }
    }
        
    return answer;
}
