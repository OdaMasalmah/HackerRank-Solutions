#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

void solve() {
        int n; cin >> n;
        int mn= LLONG_MAX;

        set<int> st;
        for (int i= 0; i< n; i++) {
                int x; cin >> x;

                if (i== 0) {
                        st.insert(x);
                } else {
                        auto pos= st.upper_bound(x);
                        if (pos!= st.end()) {
                                mn= min(mn, *pos- x);
                        }
                        st.insert(x);
                }
        }
        cout << mn<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
