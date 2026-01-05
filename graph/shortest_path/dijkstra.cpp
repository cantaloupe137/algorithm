//
// Created by user on 2026/1/5.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define WA() ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define pq priority_queue
#define fi first
#define se second

const int INF = 1e9;
signed main()
{
    int n;
    while (cin >> n)
    {
        // read adjacency martix
        vector<vector<int>> CM(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string s;
                cin >> s;
                if (s == "x")
                {
                    CM[i][j] = INF;
                }
                else
                {
                    CM[i][j] = stoll(s);
                }
            }
        }

        // start and end points
        int start, end;
        cin >> start >> end;

        vector<int> dist(n, INF); // distance array, initialized to INF
        dist[start] = 0;
        // priority queue：{current distance, node number}, use greater to make it is the minimum distance
        pq<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_;
        pq_.push({0, start});
        while (!pq_.empty())
        {
            int d = pq_.top().fi;
            int u = pq_.top().se;
            pq_.pop();

            // if the popped distance is greater than the recorded distance, skip
            if (d > dist[u])
                continue;

            // if the current node is the end node, break the loop
            if (u == end)
                break;

            // traverse all the next possible nodes
            for (int v = 0; v < n; v++)
            {
                // if there is an edge from u to v
                if (CM[u][v] != INF)
                {
                    // if the distance to v through u is shorter, update it
                    if (dist[u] + CM[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + CM[u][v];
                        pq_.push({dist[v], v});
                    }
                }
            }
        }
        if (dist[end] == INF)
            cout << -1 << endl;
        else
            cout << dist[end] << endl;
    }
    return 0;
}