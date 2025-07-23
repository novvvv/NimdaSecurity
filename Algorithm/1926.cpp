#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int board[501][501] = {0, };
bool is_visit[501][501] = {false, };
int n, m;
vector<int> pictures;

bool compare(int i, int j) { return i > j; }

int local_area = 1, max_area = -1;
void dfs (int y, int x) {
    
    is_visit[y][x] = true;
    
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (board[ny][nx] == 1 && !is_visit[ny][nx]) {
            
            is_visit[ny][nx] = true;
            local_area++;
            dfs(ny, nx);
            
        }
    }
    
}

int main () {

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int area_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (board[i][j] == 0 || is_visit[i][j]) continue; // 이미 방문 했거나, 값이 0이면 continue
            local_area = 1;
            dfs(i, j);
            pictures.push_back(local_area);
            area_cnt++;
            
        }
    }
    
    sort(pictures.begin(), pictures.end(), compare);
    
    cout << area_cnt << endl;
    
    if (area_cnt == 0) cout << 0 << endl;
    else cout << pictures[0] << endl;

}
