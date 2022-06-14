#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    string first = to_string(a);
    string second = to_string(b);
    
    string temp_str1 = "";
    temp_str1.append(first);
    string temp_str2 = "";
    temp_str2.append(second);
    
   temp_str1.append(second);
    temp_str2.append(first);

    int temp_i1 = stoi(temp_str1);
    int temp_i2 = stoi(temp_str2);
    if (temp_i1 > temp_i2) {
        return true;
    }
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    
    for(int i = 0; i < numbers.size(); i++) {
        string temp = to_string(numbers[i]);
        answer.append(temp);
    }
    
    bool check_zero = true;
    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] != '0') {
            check_zero = false;
            break;
        }
    }
    if (check_zero == true) {
        answer = "0";
    }   
    return answer;
}
