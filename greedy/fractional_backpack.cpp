//
// Created by user on 2025/12/24.
//
#include<bits/stdc++.h>
#define int long long
#define WA() ios::sync_with_stdio(false), cin.tie(0)
#define pb  push_back
#define PI pair<int, int>
#define fi first
#define se second
#define sstream stringstream
using namespace std;
signed main() {
    WA();
    string line1, line2;
    double capacity;
    if (!getline(cin, line1)) return 0;
    if (!getline(cin, line2)) return 0;
    cin >> capacity;
    sstream ss1(line1);
    sstream ss2(line2);

    vector<double> value, weight;
    double val, w;
    while (ss1 >> val) value.pb(val);
    while (ss2 >> w) weight.pb(w);

    int size = value.size();
    vector<pair<double, int>> ratioidx;
    for (int i = 0; i < size; i++) {
        double ratio = value[i] / weight[i];
        ratioidx.pb({ratio, i});
    }
    sort(ratioidx.begin(), ratioidx.end(), greater<pair<double, int>>());

    double totalval = 0;

    for (int i = 0; i < size; i++) {
        if (capacity <= 0) break;

        int idx =  ratioidx[i].second;
        double currweight = weight[idx];
        double currval = value[idx];

        if (currweight <= capacity) {
            capacity -= currweight;
            totalval += currval;
        }else {
            totalval += capacity * ratioidx[i].fi;
            capacity = 0;
        }
    }
    cout << (int)round(totalval) << "\n";

    return 0;
}