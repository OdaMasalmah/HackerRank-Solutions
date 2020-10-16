#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        string str; cin >> str;
        vector<string> an;

        for (int i= 1; i< (1<< n); i++) {
                string ne= "";
                for (int j= 0; j< n; j++) {
                        if (i& (1<< j)) {
                                ne+= str[j];
                        }
                }
                an.push_back(ne);
        }

        sort(all(an));
        for (auto X: an) cout << X<< "\n";
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
