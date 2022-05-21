#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
	// x = [a,b]
	return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;

void solve(int x) {
	string a = to_string(x);
	if (a.size() < 2) {
		a = '0' + a;
	}

	fout.open("input" + a + ".txt");


	int n = 2e5;

	fout << n << "\n";
	int z = rand(0, 3);
	if (z == 2) {
		for (int i = 0; i < n; i++) {
			fout << rand(1ll, (int)1e5) << " ";
		}
	} else if (z == 1 || z == 0) {
		for (int i = 0; i < n; i++) {
			fout << rand(1ll, (int)10) << " ";
		}
	} else {
		for (int i = 0; i < n; i++) {
			fout << rand(1ll, (int)100) << " ";
		}
	}

	fout << "\n";
	fout.close();
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
