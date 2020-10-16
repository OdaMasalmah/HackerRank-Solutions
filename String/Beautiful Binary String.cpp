#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        string str; cin >> str;
        int cnt= 0;

        for (int i= 0; i< n- 2; i++) {
                if (str[i]== '0'&& str[i+ 1]== '1'&& str[i+ 2]== '0') {
                        cnt+= 1;
                        str[i+ 2]= '1';
                }
        }
        cout << cnt<< "\n";
}

int main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
return 0;
}
