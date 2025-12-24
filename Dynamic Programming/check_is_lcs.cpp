//
// Created by user on 2025/12/21.
//
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define WA() ios::sync_with_stdio(false), cin.tie(0)
#define sstream stringstream
#define MAXN 7000

int dp[MAXN][MAXN];

signed main() {
    WA();
    string line1, line2, line3;

    while (getline(cin, line1)) {
        if (line1.empty()) continue;
        if (!getline(cin, line2)) break;
        if (!getline(cin, line3)) break;

        vector<int> arr1, arr2, arr3;
        int n;

        // 解析三行輸入
        sstream ss1(line1); while (ss1 >> n) arr1.pb(n);
        sstream ss2(line2); while (ss2 >> n) arr2.pb(n);
        sstream ss3(line3); while (ss3 >> n) arr3.pb(n);

        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();

        // 1. 計算 LCS 長度
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (arr1[i - 1] == arr2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int max_length = dp[n1][n2];

        // 先看看長度是不是一樣，如果一開始就不一樣，可以直接判斷為否(greedy)
        if (n3 != max_length) {
            cout << "False\n";
        }
        else {
            // 長度正確的話，才開始檢查
            // 檢查 arr3 是不是 arr1 的子陣列
            bool flag1 = false;
            int p3 = 0, p1 = 0;
            while (p3 < n3 && p1 < n1) {
                if (arr3[p3] == arr1[p1]) p3++;
                p1++;
            }
            if (p3 == n3) flag1 = true;

            // 檢查 arr3 是不是 arr2 的子陣列
            bool flag2 = false;
            p3 = 0; int p2 = 0;
            while (p3 < n3 && p2 < n2) {
                if (arr3[p3] == arr2[p2]) p3++;
                p2++;
            }
            if (p3 == n3) flag2 = true;

            if (flag1 && flag2) cout << "True\n";
            else cout << "False\n";
        }
    }
    return 0;
}
