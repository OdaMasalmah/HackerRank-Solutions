#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353


void solve() {
        int n, k; cin >> k>> n;
        vector<int> v(n);
        for (auto& i: v) cin >> i;

        map<int, int> mp;
        for (int i= 0; i< n; i++) {
                int t= k- v[i];
                if (mp.count(t)) {
                        cout << mp[t]<< " "<< i+ 1<< "\n";
                        return;
                }
                mp[v[i]]= (i+ 1);
        }
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
