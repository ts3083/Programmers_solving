#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size(), len = moves.size();
    vector<stack<int>> graph(n);
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (board[i][j] == 0) {
                break;
            }
            graph[j].push(board[i][j]);
        }
    }
    
    stack<int> st;
    int now_index, now_doll, count = 0;
    for (int i = 0; i < len; i++) {
        now_index = moves[i] - 1;
        if (graph[now_index].empty()) { // 해당 바구니가 비어있다면
            continue;
        }
        now_doll = graph[now_index].top();
        graph[now_index].pop();
        
        
        if (!st.empty() && st.top() == now_doll) { // 같은 인영이면 터트려야 함
            st.pop();
            count++;
        }
        else { // 같은 인형 아님
            st.push(now_doll);
        }
    }
      
    return count * 2;
}
