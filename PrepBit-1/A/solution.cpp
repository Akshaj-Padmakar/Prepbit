#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<long long> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (auto x : A) {
		cout << __builtin_popcountll(x) << " ";
	}

	return 0;
}
