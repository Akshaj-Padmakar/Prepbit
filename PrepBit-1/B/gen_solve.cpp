#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
    // x = [a,b]
    return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (int)(n)) x++;
    return x;
}

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
    segtree(int n) {
        _n = n;
        log = ceil_pow2(_n);
        size = 1 << log;
        d = vector<S>(2 * size, e());
    }

    segtree(const vector<S>& v) {
        _n = v.size();
        log = ceil_pow2(_n);
        size = 1 << log;
        d = vector<S>(2 * size, e());

        for (int i = 0; i < _n; i++) {
            d[size + i] = v[i];
        }
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);

        p += size; d[p] = x;

        for (int i = 1; i <= log; i++) {
            update(p >> i);
        }
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
private:
    int _n, size, log;
    vector<S> d;

    void update(int k) {
        d[k] = op(d[2 * k], d[2 * k + 1]);
    }
};
const int INF = 1e9;
int op(int a, int b) { return min(a, b); }
int e() { return INF; }

void solve2() {
    int n; fin >> n;

    vector<int> A(n);

    for (auto &x : A) {
        fin >> x;
    }

    segtree<int, op, e> st(n);
    st.set(n - 1, 0);

    for (int i = n - 2; i >= 0; i--) {
        int final = A[i] + i;
        final = min(final, n - 1);
        st.set(i, min(INF, st.prod(i, final + 1) + 1));
    }
    if (st.get(0) == INF) {
        fout << -1 << "\n";
        return;
    }

    vector<int> _A(A.begin(), A.end());

    reverse(_A.begin(), _A.end());

    segtree<int, op, e> _st(n);
    _st.set(n - 1, 0);

    for (int i = n - 2; i >= 0; i--) {
        int final = _A[i] + i;
        final = min(final, n - 1);
        _st.set(i, min(INF, _st.prod(i, final + 1) + 1));
    }

    if (_st.get(0) == INF) {
        fout << -1 << "\n";
        return;
    }

    fout << _st.get(0) + st.get(0) << "\n";
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