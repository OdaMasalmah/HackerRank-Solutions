#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

const int N= 1000001;

vector<int> p;
bitset<10000001> b;

void sieve() {
    b[0] = b[1] = 1;
    for (int i = 2; (i * i) <= N; i++) {
        if (!b[i]) {
            for (int j = i * 2; j <= N; j += i) b[j] = 1;
        }
    }
    for (int i = 2; i <= N; i++) if (!b[i]) p.push_back(i);
}

vector<int> prime_factor(int nm) {
        vector<int> prf;
    int pf = p[0], c = 0;

    while (pf * pf <= nm) {
        while (nm % pf == 0) { nm/= pf; prf.push_back(pf); }
        pf = p[++c];
    }

    if (nm > 1) {
        prf.push_back(nm);
    }

    return prf;
}

void solve() {
        int n; cin >> n;
        sieve();
        int sm1= 0, sm2= 0;

        vector<int> pp= prime_factor(n);

        auto get= [](int n) {
                int sm= 0;
                while (n) {
                        int rem= n% 10;
                        sm+= rem;
                        n/= 10;
                }
                return sm;
        };

        for (auto& i: pp) {
                sm1+= get(i);
        }

        sm2= get(n);

        if (sm1== sm2) {
                cout << "1\n";
        }else cout << "0\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
