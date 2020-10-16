#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

vector<int> adj[101];
int sz[101], nm;

void DFS(int u, int par) {
        sz[u]= 1;
        for (auto X: adj[u]) if (X!= par) {
                DFS(X, u);
                sz[u]+= sz[X];
        }
        if (par!= -1&& sz[u]% 2== 0) {
                nm++;
        }
}

void solve() {
        int n, m; cin >> n>> m;
        for (int i= 0; i< m; i++) {
                int u, v; cin >> u>> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        DFS(1, -1);
        cout << nm<< "\n";
}

int main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
return 0;
}
