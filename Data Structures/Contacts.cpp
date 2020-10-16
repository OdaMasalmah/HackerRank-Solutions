#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

struct Node{
        int nxt[26];
        int e, pre; //count how many word and prefix
        Node() {
                memset(nxt, -1, sizeof(nxt));
                e= 0;
                pre= 0;
        }
};

vector<Node> trie;

void insert(string &str) {
        int cur= 0;
        for (int i= 0; i< str.size(); i++) {
                int ind= str[i]- 'a';
                if (trie[cur].nxt[ind]== -1) {
                        trie[cur].nxt[ind]= trie.size();
                        trie.push_back(Node());
                }
                cur= trie[cur].nxt[ind];
                trie[cur].pre++;
        }
        trie[cur].e++;
}

int get(string &str) {
        int cur= 0;
        for (int i= 0; i< str.size(); i++) {
                int ind= str[i]- 'a';
                if (trie[cur].nxt[ind]== -1) {
                        return 0;
                }
                cur= trie[cur].nxt[ind];
        }
        return trie[cur].pre;;
}

void solve() {
        trie.push_back(Node());
        int n; cin >> n;

        while (n--){
                string str; cin >> str;
                string x; cin >> x;
                if (str[0]== 'a') insert(x);
                else {
                        cout << get(x)<< "\n";
                }
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
