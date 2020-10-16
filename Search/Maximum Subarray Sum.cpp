#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

void solve() {
        int n, m; cin >> n>> m;
        vector<int> v(n);

        for (auto& i: v) cin>> i;
        for (auto& i: v) i%= m;

        int mx= LLONG_MIN, sm= 0;
        set<int> st;

        for (int i= 0; i< n; i++) {
                sm+= v[i];
                sm%= m;
                mx= max(mx, sm);
                mx= max(mx, v[i]);
                if (i> 0) {
                        auto el= st.upper_bound(sm);
                        if (el== st.end()) {
                                mx= max(mx, sm);
                        } else
                                mx= max(mx, sm- *el+ m);
                }
                st.insert(sm);
        }

        cout << mx<< "\n";
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
