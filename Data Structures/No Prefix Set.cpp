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

bool insert(string &str) {
        int cur= 0;
        bool can= 0, pref= 1;

        for (int i= 0; i< str.size(); i++) {
                int ind= str[i]- 'a';

                if (trie[cur].nxt[ind]== -1) {
                        pref= 0;
                        trie[cur].nxt[ind]= trie.size();
                        trie.push_back(Node());
                }

                if (trie[cur].e> 0) can= 1;

                cur= trie[cur].nxt[ind];
                trie[cur].pre++;
        }

        if (trie[cur].e> 0) can= 1;

        trie[cur].e++;
        return (can|| pref);
}

void solve() {
        trie.push_back(Node());
        int n; cin >> n;
        string bad= "";
        bool can= 0;

        while (n--){
                string str; cin >> str;
                if (bad.size()== 0&& insert(str)) bad= str;
        }

        if (bad.size()!= 0)
        cout << "BAD SET\n"<< bad<< "\n";
        else
        cout << "GOOD SET\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
