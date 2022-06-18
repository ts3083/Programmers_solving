#include <string>
#include <vector>

using namespace std;

int boundary(int i, int j) {
    return 2 * (i + j) + 4;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int i = 1, j = yellow, border;
    while (i <= j) {
        border = boundary(i, j); // 필요한 테두리 블럭 개수 저장
        if (border == brown) {
            break;
        }
        i++;
        while (yellow % i != 0) {
            i++;
        }
        j = yellow / i;
    }
    answer.push_back(j + 2);
    answer.push_back(i + 2);
    
    return answer;
}
