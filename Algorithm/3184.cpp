#include <iostream>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char board[251][251] = {'.', };
bool is_visit[251][251] = {false, };
int R, C;
int sheep_cnt = 0, wolf_cnt = 0;
int sheep = 0, wolf = 0;

void dfs(int y, int x) {
    
    is_visit[y][x] = true;
    
    if (board[y][x] == 'o') sheep++;
    if (board[y][x] == 'v') wolf++;
    
    for (int dir = 0; dir < 4; dir++) {
        
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if (ny <= 0 ||  nx <= 0 || ny > R || nx > C) continue;
        if (is_visit[ny][nx] || board[ny][nx] == '#') continue;
        
        dfs(ny, nx);
    }
    
}

int main () {
    
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!is_visit[i][j] && board[i][j] != '#') {
                
                dfs(i, j);
                
                if (wolf < sheep) sheep_cnt += sheep;
                else wolf_cnt += wolf;
                
                sheep = 0;
                wolf = 0;
            }
        }
    }
    
    cout << sheep_cnt << " " << wolf_cnt << endl;
    
}

// '.' - 빈 필드, '#' - 울타리, 'o' - 양, 'v' - 늑대
// 영역 안의 양의 수 > 영역 안의 늑대의 수 - 늑대를 쫒아낸다.
// 영역 안의 양의 수 < 영역 안의 늑대의 수 - 양을 모두 먹는다.

// 아침이 도달했을 때 살아남은 양과 늑대의 수를 출력하라.

