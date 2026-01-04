#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

long long memo[100][100];

// i: 當前 stack 內的元素數量
// j: 尚未入 stack 的元素數量
long long solveDP(int in_stack, int not_in_stack) {
    if (not_in_stack == 0) return 1; // 剩下的全在 stack 裡，順序固定
    if (memo[in_stack][not_in_stack] != -1) return memo[in_stack][not_in_stack];

    long long count = 0;
    // 選擇 1: Push (前提是還有元素可以入棧)
    count += solveDP(in_stack + 1, not_in_stack - 1);
    
    // 選擇 2: Pop (前提是 stack 裡面有東西)
    if (in_stack > 0) {
        count += solveDP(in_stack - 1, not_in_stack);
    }

    return memo[in_stack][not_in_stack] = count;
}

int main() {
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        string item;
        vector<string> source;
        while (ss >> item) source.push_back(item);

        string target;
        if (!getline(cin, target)) break;
        stringstream ss2(target);
        ss2 >> target;

        int k = -1;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target) {
                k = i + 1; // 找到它是第幾個進入的
                break;
            }
        }

        if (k == -1) {
            cout << 0 << endl;
            continue;
        }

        // 初始化 memo
        for(int i=0; i<100; ++i) 
            for(int j=0; j<100; ++j) memo[i][j] = -1;

        // 當 target (第 k 個元素) 是第一個輸出的字元時：
        // 必須先將 1...k 通通 Push 進去，然後立刻把 k 彈出。
        // 此時狀態：Stack 內有 k-1 個元素，尚未入 Stack 的有 n-k 個。
        int n = source.size();
        cout << solveDP(k - 1, n - k) << endl;
    }
    return 0;
}
