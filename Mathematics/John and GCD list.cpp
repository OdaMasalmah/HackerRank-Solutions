#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        vector<int> v(n);
        for (int i= 0; i< n; i++) {
                cin >> v[i];
        }

        auto LCM= [](int a, int b) {
                return a* b/ __gcd(a, b);
        };

        cout << v[0]<< " ";
        for (int i= 1; i< n ; i++) {
                cout << LCM(v[i- 1], v[i])<< " ";
        }
        cout << v[n- 1]<< "\n";
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
