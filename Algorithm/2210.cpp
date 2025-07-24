#include <iostream>
#include <set>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string board[6][6] = {"0", };

set<string> digits;

void dfs(int y, int x, int cnt, string str) {
    
    string cur_str = str;
    if (cnt == 5) {
        digits.insert(str);
        return;
    }
    
    cnt++;
    
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || nx < 0 || nx >= 5 || ny >= 5) continue;
        dfs(ny, nx, cnt, str + board[ny][nx]);
    }
    
}

int main () {
    
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, 0, board[i][j]);
        }
    }
    
    cout << digits.size() << '\n';
    
}
