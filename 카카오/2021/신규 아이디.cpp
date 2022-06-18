#include <string>
#include <vector>

using namespace std;

void level1(string& id) {
    for (int i = 0; i < id.length(); i++) {
        if (id[i] >= 'A' && id[i] <= 'Z') {
            id[i] += 32;
        }
    }
}

void level2(string& id) {
    for (int i = 0; i < id.length(); i++) {
        if (id[i] >= 'a' && id[i] <= 'z')
            continue;
        if (id[i] >= '0' && id[i] <= '9')
            continue;
        if (id[i] == '_' || id[i] == '-' || id[i] == '.')
            continue;
        id.erase(id.begin() + i);
        i--;
    }
}

void level3(string& id) {
    for (int i = 0; i < id.length() - 1; i++) {
        if (id[i] == '.') {
            if (id[i + 1] == '.') {
                id.erase(id.begin() + i);
                i--;
            }
        }
    }
}

void level4(string& id) {
    if (id.front() == '.') {
        id.erase(id.begin());
    }
    if (id.back() == '.') {
        id.pop_back();
    }
}

void level5(string& id) {
    if (id.length() == 0) {
        id.push_back('a');
    }
}

void level6(string& id) {
    if (id.length() >= 16) {
        id.erase(id.begin() + 15, id.end());
    }
    level4(id);
}

void level7(string& id) {
    char temp = id.back();
    while (id.length() <= 2) {
        id.push_back(temp);
    }
}

string solution(string new_id) {
    level1(new_id);
    level2(new_id);
    level3(new_id);
    level4(new_id);
    level5(new_id);
    level6(new_id);
    level7(new_id);

    return new_id;
}
