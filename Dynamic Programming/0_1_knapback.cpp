//
// Created by user on 2025/12/24.
//

#include <bits/stdc++.h>
#define WA() ios::sync_with_stdio(0), cin.tie(0)
#define int long long
#define endl "\n"
#define pb push_back
using namespace std;

const int MAXN = 105;
const int MAXW = 10005;

int dp[MAXN][MAXW];

signed main() {
    WA();

    string line1, line2;
    vector<int>v{0}, w{0};
    int W_max;

    // 物品價值
    getline(cin, line1);
    stringstream ss1(line1);
    int val;
    while (ss1 >> val) v.pb(val);

    // 物品重量
    getline(cin, line2);
    stringstream ss2(line2);
    int weight;
    while (ss2 >> weight) w.pb(weight);

    // 背包可承受最大重量
    cin >> W_max;
    int n = v.size() - 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W_max; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[n][W_max] << endl;

    return 0;
}