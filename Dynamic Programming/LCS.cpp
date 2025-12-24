//
// Created by user on 2025/12/21.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define WA() ios::sync_with_stdio(false), cin.tie(0)
#define sstream stringstream
#define MAXN 1000

int dp[MAXN][MAXN];
signed main() {
    WA();
    string line1, line2;

    while (getline(cin, line1)) {

        // 處理空行
        if (line1.empty()) continue;
        if (!getline(cin, line2)) break;

        vector<int> arr1, arr2;
        int n;

        sstream ss1(line1);
        while (ss1 >> n) arr1.pb(n);

        sstream ss2(line2);
        while (ss2 >> n) arr2.pb(n);

        int n1 = arr1.size();
        int n2 = arr2.size();

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (arr1[i - 1] == arr2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[n1][n2] << "\n";
    }
    return 0;
}