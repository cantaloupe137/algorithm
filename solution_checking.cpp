//
// Created by user on 2025/12/26.
//
#include<bits/stdc++.h>
#define int long long
#define WA() ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
using namespace std;

signed main() {
    WA();
    string line1, line2;
    if (!getline(cin, line1) || !getline(cin, line2)) return 0;

    vector<int> formula;
    vector<int> solution;
    int n;

    stringstream ss1(line1), ss2(line2);
    while (ss1 >> n) formula.push_back(n);
    while (ss2 >> n) solution.push_back(n);

    int res = formula[0];

    // 從 W1 (formula[1]) 開始加總，對應 x1 (solution[0])
    for (int i = 1; i < formula.size(); i++) {
        // formula[i] 對應的是 solution[i-1]，因為第一個是常數項
        if (i - 1 < solution.size()) {
            res += formula[i] * solution[i - 1];
        }
    }

    if (res == 0) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}