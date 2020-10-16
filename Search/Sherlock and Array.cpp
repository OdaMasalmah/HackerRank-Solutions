#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

void solve() {
        int n; cin >> n;
        vector<int> v(n), sum(n+ 1);

        for (auto& i: v) cin>> i;
        for (int i= 1; i<= n; i++) {
                sum[i] = sum[i- 1] + v[i- 1];
        }

        bool can= 0;
        int suf= 0;
        for (int i= n- 1; i>= 0; i--) {
                int l= suf; // left sum
                int r= sum[i]; // sum of the right
                if (l== r) {
                        can= 1;
                        break;
                }
                suf+= v[i];
        }
        cout << (can? "YES\n": "NO\n");
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
