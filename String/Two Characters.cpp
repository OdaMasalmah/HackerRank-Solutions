#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        string str; cin>> str;

        int mx= INT_MIN;

        auto alt= [&](char f, char s)->int{
                string ne= "";
                for (char c: str) {
                        if (c== f|| s== c) ne+= c;
                }

                for (int i= 1; i< ne.size(); i++) if (ne[i]== ne[i- 1]) return 0;
                return (int)ne.size();
        };

        for (char f= 'a'; f<= 'z'; f++) {
                for (int s= 'a'; s<= 'z'; s++) {
                        if (f== s) continue;
                        mx= max(mx, alt(f, s));
                }
        }

        if (mx== 1) cout << "0\n";
        else cout<< mx<< "\n";
}

int main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
