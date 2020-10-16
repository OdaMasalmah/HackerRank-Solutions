#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000000

const int N= 1001;
int ncr[N][N];

void init() { // you can do this in k space;
        for (int i= 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (j == 0 || j == i) {
                                ncr[i][j]= 1;
                        } else {
                                ncr[i][j]= ((ncr[i - 1][j - 1])%mod + (ncr[i - 1][j])%mod)% mod;
                        }
                }
        }
}

void solve() {
        int n, m; cin >> n>> m;
        cout << ncr[n+ m- 1][m]<< " ";
        cout << "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        init();
        cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
