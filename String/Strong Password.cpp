#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        string str; cin>> str;
        
        string numbers = "0123456789";
        string lower_case = "abcdefghijklmnopqrstuvwxyz";
        string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string special_characters = "!@#$%^&*()-+";
        
        bool N= 0, L= 0, U= 0, S= 0;

        for (int i= 0; i< n; i++) for (char c: numbers) if (c== str[i]) N= 1;
        for (int i= 0; i< n; i++) for (char c: lower_case) if (c== str[i]) L= 1;
        for (int i= 0; i< n; i++) for (char c: upper_case) if (c== str[i]) U= 1;
        for (int i= 0; i< n; i++) for (char c: special_characters) if (c== str[i]) S= 1;

        int an= (4)- (N+ L+ U+ S);
        cout << max(6- n, an);
}

int main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
