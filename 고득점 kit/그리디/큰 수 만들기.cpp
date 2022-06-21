#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int x = number.size() - k;
    int max_elem = 0, i = 0, index = -1;
    while (x > 0) {
        max_elem = -1;
        for (i = index + 1; i <= number.size() - x; i++) {
            if (max_elem < number[i] - '0') {
                max_elem = number[i] - '0';
                index = i;
            }
        }
        answer.push_back(number[index]);
        x--;
    }  
    
    return answer;
}
