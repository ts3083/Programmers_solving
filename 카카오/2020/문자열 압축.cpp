#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int n = s.length(), i = 0, j, m = 1001;
    if (n == 1)
        m = 1;
    for (int k = 1; k <= n / 2; k++) {
        string answer = "";
        vector<string> vec;
        string a, c;
        i = 0;
        while (i + k < n) {
            a = s.substr(i, k);
            vec.push_back(a);
            i += k;
        }
        if (i < n) {
            c = s.substr(i);
            vec.push_back(c);
        }
        
        int count = 1;
        for (j = 0; j < vec.size() - 1; j++) {
            if (vec[j].compare(vec[j + 1]) == 0) {
                count++;
            }
            else {
                if (count == 1) {
                    answer += vec[j];
                }
                else {
                    string num = to_string(count);
                    answer += num;
                    answer += vec[j];
                    count = 1;
                }
            }
        }
        if (count == 1) {
            answer += vec[j];
        }
        else {
            string num = to_string(count);
            answer += num;
            answer += vec[j];
        }
        m = (m > answer.size() ? answer.size() : m);
    }    
    
    return m;
}
