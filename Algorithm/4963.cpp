#include <iostream>
#include <cstring>
using namespace std;

int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int board[51][51] = {0, };
bool is_visit[51][51] = {false, }; // 방문처리 배열
int area; // 섬의 개수
int w, h;


void dfs(int y, int x) {
    
    is_visit[y][x] = true;
    for (int dir = 0; dir < 8; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || nx < 0 || ny > h || nx > w) continue;
        if (is_visit[ny][nx] || board[ny][nx] == 0) continue;
        dfs(ny, nx);
    }
    return;
    
}

int main () {
        
    while(cin >> w >> h) {
        
        if (w == 0 && h == 0) break;
        
        memset(board, 0, sizeof(board));
        memset(is_visit, false, sizeof(is_visit));
        area = 0;
        
        // input
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
            }
        }
        
        // dfs
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!is_visit[i][j] && board[i][j] == 1) {
                    area++;
                    dfs(i, j);
                }
            }
        }
        cout << area << endl;

    }
    
}

