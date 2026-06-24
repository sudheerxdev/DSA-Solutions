#include <bits/stdc++.h>
using namespace std;

string getRuns(const string &s) {
    string r;
    r.push_back(s[0]);

    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != s[i - 1]) {
            r.push_back(s[i]);
        }
    }
    return r;
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

        string RA = getRuns(A);
        string RB = getRuns(B);

        int j = 0;

        for (char c : RA) {
            if (j < (int)RB.size() && c == RB[j]) {
                j++;
            }
        }

        cout << (j == (int)RB.size() ? "Yes" : "No") << '\n';
    }

    return 0;
}
