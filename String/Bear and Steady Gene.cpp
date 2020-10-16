#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        string str; cin >> str;
        
        assert(n% 4 == 0);

        int fr= n/ 4;
        int f[27]= {0};

        for (char c: str) f[c- 'A'+ 1]++;
        string t= "ATGC";

        auto d= [&](char c, int cnt) {
                f[c- 'A'+ 1]+= cnt;
        };

        auto ck= [&]() {
                for (int i= 0; i< (int)t.size(); i++) {
                        if (f[t[i]- 'A'+ 1]> fr) return 1;
                }
                return 0;
        };

        int en= 0, mx= INT_MAX;
        for (int i= 0; i< n; i++) {
                while (en< n&& ck()) {
                        d(str[en], -1);
                        en++;
                }
                if(!ck()) mx= min(mx, (en- i));
                d(str[i], 1);
        }

        cout << mx<< "\n";
}

int main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
return 0;
}
