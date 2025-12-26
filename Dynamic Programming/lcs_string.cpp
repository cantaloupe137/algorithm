//
// Created by user on 2025/12/26.
//
#include<bits/stdc++.h>
using namespace std;
#define WA() ios::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
int main() {
    string a,b;
    while (getline(cin,a) && getline(cin,b)) {
        int dp[a.length()+1][b.length()+1];
        for(int i=0;i<=a.length();i++)
            dp[i][0]=0;
        for(int i=0;i<=b.length();i++)
            dp[0][i]=0;
        for(int i=1;i<=a.length();i++)
            for(int j=1;j<=b.length();j++) {
                if(a[i-1]!=b[j-1])
                    dp[i][j]=max(max(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
                else
                    dp[i][j]=dp[i-1][j-1]+1;
            }
        cout << dp[a.length()][b.length()] << endl;
    }
}