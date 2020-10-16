#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 998244353

stack <pair<int, int>> st;

void solve() {
        int x; cin >> x;
        if (x== 1) {
                int y; cin >> y;
                if (st.empty()) {
                        st.push({y, y});
                } else {
                        pair<int, int> last= st.top();
                        st.push({y, max(y, last.second)});
                }
        } else if (x== 2) {
                st.pop();
        } else {
                cout << st.top().second<< "\n";
        }
}

int main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
