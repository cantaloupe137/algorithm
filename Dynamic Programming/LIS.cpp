//
// Created by user on 2025/12/22.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define WA() ios::sync_with_stdio(false),cin.tie(0)
#define sstream stringstream
#define MAXN 5050
int dp[5050];

signed main() { WA();
    string s;
    getline(cin, s);
    sstream ss(s);
    vector<int> v;
    int n;
    while (ss >> n) v.pb(n);
    int n1 = v.size();
    if (!n1) {
        cout << "0\n";
        return 0;
    }
    int max_length = 0;
    for (int i = 0; i < n1; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            // 題目沒有說是嚴格遞增，所以也可以等於
            if (v[j] <= v[i]) dp[i] = max(dp[j] + 1, dp[i]);
        }
        max_length = max(max_length, dp[i]);
    }
    cout << max_length << "\n";
    return 0;
}