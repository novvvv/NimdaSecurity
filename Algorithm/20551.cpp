#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    
    int N, M; // 원소의 개수 N, 질문의 개수 M
    cin >> N >> M;  
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < M; i++) {

        int target;
        cin >> target; 

        int left = 0;
        int right = N - 1;
        int ans = 0;
        bool flag = false; 

        while (left <= right) {
            
            int mid = (left + right) / 2;

            // 탐색 성공 
            if (arr[mid] == target) {
                flag = true;
            }

            if (arr[mid] >= target) {
                right = mid - 1;
                ans = mid;
            }

            else {
                left = mid + 1;  
            }
        }

        if (flag) cout << ans << '\n';
        else cout << "-1"  << '\n';
    }

}