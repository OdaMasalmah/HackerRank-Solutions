#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

void solve() {
        int n, k; cin >> n>> k;
        vector<int> v(n);
        for (auto& i: v) cin >> i;

        sort(all(v));

        int cur= 0, an= 0;

        auto to= [&](int nm) {
                int pos= upper_bound(all(v), nm)- v.begin();
                return pos;
        };

        while (cur< n) {
                an+= 1;
                int mid= to(v[cur]+ k);
                if (mid== n) break;
                cur= mid- 1;
                int left= to(v[cur]+ k);
                if (left== n) break;
                cur= left;
        }

        cout << an<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
