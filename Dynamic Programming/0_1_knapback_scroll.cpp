#include <bits/stdc++.h>
#define WA() ios::sync_with_stdio(0), cin.tie(0)
#define int long long
#define endl "\n"
#define pb push_back
using namespace std;

const int MAXW = 10005;
int dp[MAXW];

signed main() {
    WA();

    string line1, line2;
    vector<int> v{0}, w{0};
    int W_max;

    // 物品價值
    if (!getline(cin, line1)) return 0;
    stringstream ss1(line1);
    int val;
    while (ss1 >> val) v.pb(val);

    // 物品重量
    if (!getline(cin, line2)) return 0;
    stringstream ss2(line2);
    int weight;
    while (ss2 >> weight) w.pb(weight);

    // 背包可承受最大重量
    if (!(cin >> W_max)) return 0;
    int n = v.size() - 1;


    for (int i = 1; i <= n; i++) {
        // 由後往前
        // 這樣 dp[j - w[i]] 抓到的才會是 上一層 的舊資料
        for (int j = W_max; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W_max] << endl;

    return 0;
}