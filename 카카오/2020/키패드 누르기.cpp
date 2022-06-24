#include <string>
#include <vector>

using namespace std;

pair<int, int> prev_l(3, 0);
pair<int, int> prev_r(3, 2);
string answer = "";

void push(pair<int, int>& p, char c, int i, int j) {
    answer.push_back(c);
    p.first = i;
    p.second = j;
}

void dist(int i, int j, string& hand) {
    int left_x, left_y, right_x, right_y;
    left_x = (i > prev_l.first ? i - prev_l.first : prev_l.first - i);
    left_y = (j > prev_l.second ? j - prev_l.second : prev_l.second - j);
    right_x = (i > prev_r.first ? i - prev_r.first : prev_r.first - i);
    right_y = (j > prev_r.second ? j - prev_r.second : prev_r.second - j);
    if (left_x + left_y < right_x + right_y) {
        push(prev_l, 'L', i, j);
    }
    else if (left_x + left_y == right_x + right_y) {
        if (hand.compare("left") == 0) {
            push(prev_l, 'L', i, j);
        }
        else {
            push(prev_r, 'R', i, j);
        }
    }
    else {
        push(prev_r, 'R', i, j);
    }        
}

string solution(vector<int> numbers, string hand) {
    int n = numbers.size(), i, j;
    for (int a = 0; a < n; a++) {
        int now = numbers[a];
        if (now == 1 || now == 4 || now == 7) {
            push(prev_l, 'L', (now - 1) / 3, 0);
        }
        else if (now == 3 || now == 6 || now == 9) {
            push(prev_r, 'R', (now - 3) / 3, 2);
        }
        else {
            if (now == 0)
                i = 3;
            else
                i = (now - 2) / 3;
            j = 1;
            dist(i, j, hand);
        }
    }
    
    return answer;
}
