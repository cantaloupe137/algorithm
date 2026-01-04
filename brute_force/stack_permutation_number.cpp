#include <bits/stdc++.h>
#define sstream stringstream
#define WA() ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    // WA();
    string line;
    // 讀取第一行：字母序列，讀到 EOF 為止
    while (getline(cin, line)) {
        if (line.empty()) continue;

        sstream ss(line);
        string item;
        vector<string> source;
        while (ss >> item) {
            source.pb(item);
        }

        // 讀取第二行：指定的起始字元
        string targetStart;
        if (!getline(cin, targetStart)) break;
        
        // 處理可能包含空格的輸入字元
        sstream ss2(targetStart);
        if (!(ss2 >> targetStart)) continue;

        // 檢查起始字元是否存在於 source 中
        bool exists = false;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == targetStart) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            cout << 0 << endl;
            continue;
        }

        // 準備進行全排列 (Brute Force)
        vector<string> current = source;
        sort(current.begin(), current.end()); // next_permutation 運作前提

        int validCount = 0;
        do {
            // 條件 1: 檢查第一個字元是否為指定字元
            if (current[0] != targetStart) continue;

            // 條件 2: 模擬 Stack 操作檢查該排列是否合法
            stack<string> s;
            int srcIdx = 0;
            bool possible = true;

            for (int i = 0; i < current.size(); ++i) {
                string targetItem = current[i];

                // 如果 stack 為空或頂端不是我們要的，則依照 source 順序 push
                while (s.empty() || s.top() != targetItem) {
                    if (srcIdx >= source.size()) {
                        possible = false;
                        break;
                    }
                    s.push(source[srcIdx++]);
                }
                
                if (!possible) break;

                // 檢查頂端是否正確並彈出
                if (s.top() == targetItem) {
                    s.pop();
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                validCount++;
            }

        } while (next_permutation(current.begin(), current.end()));

        cout << validCount << endl;
    }

    return 0;
}
// O(n!)
// 另解 : 動態規劃
