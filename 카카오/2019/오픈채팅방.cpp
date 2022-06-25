#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> answer;
vector<vector<string>> result;
map<string, string> user; // uid, id

void split(string& str) {
    vector<string> temp;
    int pos = str.find(" ");
    while (pos != string::npos) {
        temp.push_back(str.substr(0, pos));
        str = str.substr(pos + 1);
        pos = str.find(" ");
    }
    temp.push_back(str);
    
    if (temp[0].compare("Enter") == 0) {
        user[temp[1]] = temp[2]; // uid id
        result.push_back(temp);
    }
    else if (temp[0].compare("Leave") == 0) {
        temp.push_back(user[temp[1]]);
        result.push_back(temp);
    }
    else {
        user[temp[1]] = temp[2]; // id가 temp[1]인 사용자의 닉네임을 temp[2]로 change
    }
}

vector<string> solution(vector<string> record) {
    int n = record.size();
    for (int i = 0; i < n; i++) {
        split(record[i]);
    }
    
    for (int i = 0; i < result.size(); i++) {
        if (result[i][0].compare("Enter") == 0) {
            answer.push_back(user[result[i][1]] + "님이 들어왔습니다.");
        }
        else {
            answer.push_back(user[result[i][1]] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}
