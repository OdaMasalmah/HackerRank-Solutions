#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        string str; cin >> str;
        int q; cin >> q;
        set<int> st;
        int cur= 0;

        for (int i= 0; i< (int)str.size(); i++) {
                if (i> 0) {
                        if (str[i]== str[i- 1]) {
                                cur+= (str[i]- 'a'+ 1);
                        } else {
                                cur= str[i]- 'a'+ 1;
                        }
                } else {
                        cur= str[i]- 'a'+ 1;
                }
                st.insert(cur);
        }

        while (q--) {
                int x; cin>> x;
                if (st.find(x)== st.end()) cout << "No\n";
                else cout << "Yes\n";
        }
}

int main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
