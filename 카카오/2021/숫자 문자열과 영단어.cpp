#include <string>
#include <vector>

using namespace std;

int index;

char find_word(string& s, int i) {
    if(s[i] == 'z') { // zero
        index = i + 4;
        return '0';
    }
    else if(s[i] == 'o') {
        index = i + 3;
        return '1';
    }
    else if(s[i] == 't') {
        if (s[i + 1] == 'w') {
            index = i + 3;
            return '2';
        }
        else if (s[i + 1] == 'h') {
            index = i + 5;
            return '3';
        }
    }
    else if(s[i] == 'f') {
        if (s[i + 1] == 'o') {
            index = i + 4;
            return '4';
        }
        else if (s[i + 1] == 'i') {
            index = i + 4;
            return '5';
        }
    }
    else if(s[i] == 's') {
        if (s[i + 1] == 'i') {
            index = i + 3;
            return '6';
        }
        else if (s[i + 1] == 'e') {
            index = i + 5;
            return '7';
        }
    }
    else if(s[i] == 'e') {
        index = i + 5;
        return '8';
    }
    else if(s[i] == 'n') {
        index = i + 4;
        return '9';
    }
    return '0';
}

int solution(string s) {
    int answer = 0;
    string result = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 90) {
            result += s[i]; //result.push_back(s[i]);
        }
        else { // 문자이면
            char c = find_word(s, i);
            result += c; //result.push_back(c);
            i = index - 1;
        }
    }
    answer = stoi(result);
    
    return answer;
}
