#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

const int N= 100001;
int dp[N][3];

void solve() {
        int n; cin >> n;
        vector<int> v(n);

        for (auto& i: v) cin >> i;

        for (int i= 0; i<= n; i++) for (int j= 0; j< 2; j++) dp[i][j]= -1;

        function<int(int, bool)> calc= [&](int idx, bool tk)->int {
                if (idx>= n) {
                        return 0;
                }

                int &ret= dp[idx][tk];
                if (ret!= -1) return ret;
                ret= 0;

                if (tk) {
                        ret= max(ret, calc(idx+ 1, tk^ 1)+ v[idx]);
                        if (idx+ 1< n) {
                                ret= max(ret, calc(idx+ 2, tk^ 1)+ v[idx]+ v[idx+ 1]);
                        }
                        if (idx+ 2< n) {
                                ret= max(ret, calc(idx+ 3, tk^ 1)+ v[idx]+ v[idx+ 1]+ v[idx+ 2]);
                        }
                } else {
                        ret= 1e18;
                        ret= min(ret, calc(idx+ 1, tk^ 1));
                        if (idx+ 1< n) {
                                ret= min(ret, calc(idx+ 2, tk^ 1));
                        }
                        if (idx+ 2< n) {
                                ret= min(ret, calc(idx+ 3, tk^ 1));
                        }
                }
                return ret;
        };

        cout << calc(0, 1)<< "\n";
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
