//
// Created by user on 2026/1/4.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定義一個代表無限大的數值，確保兩數相加不溢位
const int INF = 1e9;

void floydWarshall(int n, vector<vector<int>>& dist) {
    // 核心三層迴圈
    for (int k = 0; k < n; k++) {         // 中間轉折點
        for (int i = 0; i < n; i++) {     // 起點
            for (int j = 0; j < n; j++) { // 終點
                // 如果經過 k 點的路徑更短，則更新
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n = 4; // 頂點數量

    // 初始化相鄰矩陣 (0代表自己到自己, INF代表不連通)
    vector<vector<int>> dist = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(n, dist);

    // 輸出結果
    cout << "The shortest path between any two points : " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}