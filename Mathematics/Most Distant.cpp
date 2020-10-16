#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000000 

void solve() {
        int n; scanf("%d", &n);

        double mxX= INT_MIN, mnX= INT_MAX;
        double mxY= INT_MIN, mnY= INT_MAX;

        while (n--) {
                double x, y; cin >> x>> y;
                if (y== 0){
                        mxX= max(mxX, x);
                        mnX= min(mnX, x);
                }
                if (x== 0){
                        mxY= max(mxY, y);
                        mnY= min(mnY, y);
                }
        }

        double ans= max(mxX- mnX, mxY- mnY);

        double an1= sqrt(mxX*mxX+ mxY*mxY);
        double an2= sqrt(mxX*mxX+ mnY*mnY);

        double an3= sqrt(mnX*mnX+ mnY*mnY);
        double an4= sqrt(mnX*mnX+ mxY*mxY);

        printf("%0.10f\n", max(ans, max(an1, max(an2, max(an3, an4)))));
}

int32_t main(){
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
