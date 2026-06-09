#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int T;
    cin >> T;

    while (T--) {

        int N;
        cin >> N;

        vector < int > arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        unordered_map < int, int > mp;
        for (auto num: arr) {
            mp[num]++;
        }
        for (int num: arr) {
            cout << mp[num] << " ";
        }
        cout << endl;

    }
    return 0;

}
