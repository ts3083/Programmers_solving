#include <string>
#include <vector>

using namespace std;

int graph[1001][1001] = {0,};
int dx[] = {1,0,-1};
int dy[] = {0,1,-1};

int next_h(int h) {
    return h % 3; // 다음 h를 설정
}

void insert(vector<int>& answer, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            answer.push_back(graph[i][j]);
        }
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    int i = 1, j = 1, h = 0, nx, ny, count = 1;
    graph[i][j] = count;
    if (n == 1) {
        answer.push_back(1);
        return answer;
    }
    for (;;) {
        nx = i + dx[h];
        ny = j + dy[h];
        if (nx > n || ny > n || graph[nx][ny] != 0) {
            h = next_h(++h);
            nx = i + dx[h];
            ny = j + dy[h];
            if (graph[nx][ny] != 0) {
                break;
            }
            else {
                continue;
            }
        }
        if (graph[nx][ny] == 0) {
            graph[nx][ny] = ++count;
            i = nx;
            j = ny;
        }
    }
    
    insert(answer, n);
    return answer;
}
