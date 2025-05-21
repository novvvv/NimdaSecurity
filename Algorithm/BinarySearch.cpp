#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int target = 6;
    
    int left = 1; // 가장 왼쪽 값
    int right = 7; // 가장 오른쪽 값
    
    while (left <= right) {
        int mid = (left + right) / 2; // 중앙값 (탐색 데이터)
        // 탐색에 성공한 경우
        if (mid == target) {
            cout << "탐색 성공" << '\n';
            break;
       }

       // 중앙값이 타깃 데이터보다 크다면
       // 우측 데이터를 현재 탐색중인값에서 1 작은 값으로 설정
       else if (mid > target) {
            right = mid - 1; 
       }

       // 중앙값이 타깃 데이터보다 작다면
       // 왼쪽 데이터를 현재 탐색중인값보다 1 큰 값으로 설정
       else {
            left = mid + 1;
       }
    }

}

