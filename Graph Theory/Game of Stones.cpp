#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

const int N= 1001;
int win[N];

void solve() {
        int n; cin >> n;
        cout << (win[n]? "First": "Second")<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;

        vector<int> v= {2, 3, 5};

        win[0]= 1;
        win[1]= 0;
        win[2]= 1;
        win[3]= 1;
        win[4]= 1;
        win[5]= 1;

        for (int i= 6; i< N; i++) {
                bool can= 1;
                for (int j= 0; j< 3; j++) {
                        if (i- v[j]>= 0) can&= win[i- v[j]];
                }
                win[i]= (can? 0: 1);
        }
        
        while ( T-- ) {
                solve();
        }
return 0;
}
