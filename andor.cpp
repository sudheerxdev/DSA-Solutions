#include <bits/stdc++.h>
using namespace std;

int countRuns(const string &s) {
    int runs = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != s[i - 1]) runs++;
    }
    return runs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string A, B;

        cin >> N;
        cin >> A;
        cin >> B;

        if (A == B) {
            cout << "Yes\n";
            continue;
        }

        int ra = countRuns(A);
        int rb = countRuns(B);

        cout << (rb < ra ? "Yes" : "No") << '\n';
    }

    return 0;
}
