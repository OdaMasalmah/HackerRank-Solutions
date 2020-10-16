#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        map<int, int> f;

        for (int i= 0; i< n; i++) {
                int x; cin >> x;
                f[x]++;
        }

        int an= f[0], sm= f[0]- 1;

        for (int i= 1; i< n; i++) {
                sm+= f[i];
                an= ((an% mod)* (sm% mod))% mod;
                sm-= 1;
        }

        cout << an<< "\n";
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
