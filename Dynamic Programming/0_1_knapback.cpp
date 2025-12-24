//
// Created by user on 2025/12/24.
//

#include <bits/stdc++.h>
#define WA() ios::sync_with_stdio(0), cin.tie(0)
#define int long long
#define endl "\n"
using namespace std;

const int MAXN = 105;
const int MAXW = 10005;

int dp[MAXN][MAXW];
int v[MAXN], w[MAXN];

signed main() {
    WA();

    string line1, line2;
    int W_max;

    // 物品價值
    getline(cin, line1);
    stringstream ss1(line1);
    int n = 0, val;
    while (ss1 >> val) {
        v[++n] = val; // 從index 1 開始存
    }

    // 物品重量
    getline(cin, line2);
    stringstream ss2(line2);
    for (int i = 1; i <= n; ++i) {
        ss2 >> w[i];
    }

    // 背包可承受最大重量
    cin >> W_max;


    // 初始化
    for (int j = 0; j <= W_max; j++) dp[0][j] = 0;

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