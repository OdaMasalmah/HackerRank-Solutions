#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define lp(i, n) for(int i = 0; i < n; i++)
#define sz(v) (int)(v).size()
#define mod 998244353

const int N= 444;
int n, m, q;
int g[N][N];
int dis[N][N];

void  Floyd_Warshall() {
        for (int k = 1; k <= n; k++) {
                        for (int i = 1; i <= n; i++) {
                                for (int j = 1; j <= n; j++) {
                                        dis[i][j] = min(dis[i][j], dis[i][k]+ dis[k][j]);
                        }
                                }
        }

}

void solve() {
        cin >> n>> m;
        lp(i, N) lp(j, N) g[i][j] = 1e18;

        lp(i, m) {
                int u, v, c; cin >> u>> v>> c;
                g[u][v]= c;
        }

        for (int i= 1; i<= n; i++) {
                for (int j= 1; j<= n; j++) {
                        if (i== j) dis[i][i]= 0;
                        else if (g[i][j]){
                                dis[i][j]= g[i][j];
                        } else dis[i][j]= 1e18;

                }
        }

        Floyd_Warshall();

        cin >> q;
        while ( q-- ) {
                int a, b; cin >> a>> b;
                cout << (dis[a][b] == 1e18? -1: dis[a][b])<< "\n";
        }
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
