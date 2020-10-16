#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

const int N= 100001;
int nxtR[N], nxtL[N];

void solve() {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i: v) cin >> i;

        stack<pair<int, int>> st;
        for (int i= n- 1; i>= 0; i--) {
                while (st.size()&& st.top().first>= v[i]) {
                        st.pop();
                }
                if (st.size()) {
                        nxtR[i]= st.top().second;
                } else nxtR[i]= n;
                st.push({v[i], i});
        }
        while (st.size()) st.pop();

        for (int i= 0; i< n; i++) {
                while (st.size()&& st.top().first>= v[i]) {
                        st.pop();
                }
                if (st.size()) {
                        nxtL[i]= st.top().second;
                } else nxtL[i]= -1;
                st.push({v[i], i});
        }
        int mx= INT_MIN;

        for (int i= 0; i< n; i++) {
                mx= max(mx, v[i]* (nxtR[i]- nxtL[i]- 1));
        }

        cout << mx<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
