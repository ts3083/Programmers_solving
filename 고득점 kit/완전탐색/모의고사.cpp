#include <string>
#include <vector>

using namespace std;

int arr1[] = {1,2,3,4,5};
int arr2[] = {2,1,2,3,2,4,2,5};
int arr3[] = {3,3,1,1,2,2,4,4,5,5};

int check(vector<int>& answers, int num) {
    int count = 0;
    int k = 0;
    int size = answers.size();
    if (num == 1) {
        for (int i = 0; i < size; i++) {
            if (k % 5 == 0) {
                k = 0;
            }
            if (answers[i] == arr1[k]) {
                count++;
            }
            k++;
        }
    }
    else if (num == 2) {
        for (int i = 0; i < size; i++) {
            if (k % 8 == 0) {
                k = 0;
            }
            if (answers[i] == arr2[k]) {
                count++;
            }
            k++;
        }
    }
    else { // num == 3
        for (int i = 0; i < size; i++) {
            if (k % 10 == 0) {
                k = 0;
            }
            if (answers[i] == arr3[k]) {
                count++;
            }
            k++;
        }
    }
    return count;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a, b ,c;
    a = check(answers, 1); // 수포자 1이 맞힌 정답 수
    b = check(answers, 2);
    c = check(answers, 3);
    
    vector<int> result = {a, b, c};
    int m = 0;
    for (int i = 0; i < 3; i++) {
        if(m < result[i]) {
            m = result[i];
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (m == result[i]) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
