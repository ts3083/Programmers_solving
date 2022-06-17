#include <string>
#include <vector>

using namespace std;

void borrow(vector<int>& student, int i, int n) {
    if (i == 1) {
        if (student[i + 1] == 2) {
            student[i + 1]--;
            student[i]++;
        }
    }
    else if (i == n) {
        if (student[i - 1] == 2) {
            student[i - 1]--;
            student[i]++;
        }
    }
    else {
        if (student[i - 1] == 2) {
            student[i - 1]--;
            student[i]++;
        }
        else if (student[i + 1] == 2) {
            student[i + 1]--;
            student[i]++;
        }
    }
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int count = 0;
    vector<int> student(n + 1, 1); // 0 1 1 1 1 1
    for (int i = 0; i < reserve.size(); i++) {
        student[reserve[i]]++;
    }
    for (int i = 0; i < lost.size(); i++) {
        student[lost[i]]--;
    }
    
    for (int i = 1; i <= n; i++) {
        if (student[i] == 0) {
            borrow(student, i, n);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (student[i] == 0) {
            count++;
        }
    }
    
    return n - count;
}
