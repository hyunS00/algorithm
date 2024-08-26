#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;  // n: 사진틀의 개수, r: 총 추천 횟수

    vector<int> frame;  // 사진틀
    vector<int> count(101, 0);  // 각 학생의 추천 횟수
    vector<int> time(101, 0);   // 각 학생이 올라간 시간

    for (int t = 1; t <= r; t++) {
        int student;
        cin >> student;

        // 1. 이미 사진틀에 있는 경우
        if (find(frame.begin(), frame.end(), student) != frame.end()) {
            count[student]++;
        }
        // 2. 사진틀에 없는 경우
        else {
            // 2-1. 사진틀에 여유가 있는 경우
            if (frame.size() < n) {
                frame.push_back(student);
            }
            // 2-2. 사진틀이 가득 찬 경우
            else {
                int remove_idx = 0;
                for (int i = 1; i < n; i++) {
                    // 추천 횟수가 적거나, 추천 횟수가 같다면 더 오래된 학생 선택
                    if (count[frame[i]] < count[frame[remove_idx]] || 
                       (count[frame[i]] == count[frame[remove_idx]] && time[frame[i]] < time[frame[remove_idx]])) {
                        remove_idx = i;
                    }
                }
                // 선택된 학생 제거
                count[frame[remove_idx]] = 0;
                time[frame[remove_idx]] = 0;
                frame[remove_idx] = student;
            }
            count[student] = 1;
            time[student] = t;
        }
    }

    // 결과 정렬 및 출력
    sort(frame.begin(), frame.end());
    for (int student : frame) {
        cout << student << " ";
    }
    cout << endl;

    return 0;
}