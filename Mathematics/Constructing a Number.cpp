#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        int sm= 0;

        for (int i= 0; i< n; i++) {
                int x; cin >> x;
                while (x) {
                        int dij= x% 10;
                        if (dij) sm+= dij;
                        sm%= 3;
                        x/= 10;
                }
        }
        sm%= 3;
        if (sm) {
                cout << "No\n";
        }else cout << "Yes\n";
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
