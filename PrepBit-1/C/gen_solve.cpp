#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
    // x = [a,b]
    return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;


void solve2() {
    int n; fin >> n;
    vector<int> nums(n);
    for (auto &x : nums) {
        fin >> x;
    }
    const int INF = 1e18;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));

    auto check = [&](int x) {
        return x >= 0 && x < n;
    };

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            for (int mid = i; mid <= j; mid++) {
                dp[i][j] = min(dp[i][j], (i <= mid - 1 ? dp[i][mid - 1] : 0ll) + (mid + 1 <= j ? dp[mid + 1][j] : 0ll) + nums[mid] * (check(i - 1) ? nums[i - 1] : 1ll) * (check(j + 1) ? nums[j + 1] : 1ll));
            }
        }
    }
    fout << dp[0][n - 1] << "\n";
}


void solve(int x) {
    string a = to_string(x);
    if (a.size() < 2) {
        a = '0' + a;
    }

    fin.open("input" + a + ".txt");
    fout.open("output" + a + ".txt");

    int T = 1;
    // fin >> T;
    for (int i = 0; i < T; i++) {
        solve2();
    }
    fout.close();
    fin.close();
}

signed main() {
    srand (time (0));  // needs ctime header
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;

    cin >> t;

    for (int i = 0; i < t; i++) {
        solve(i);
    }

}