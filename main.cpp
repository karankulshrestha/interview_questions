#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        int n;
        cin >> n;
        cin >> s;
        vector<int> c(n);
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt == 0) c[i] = c[i - 1];
            else c[i] = cnt > 0 ? 1 : 2;
        };
        if(*min_element(all(c)) == 2) {
            for(auto &x : c) x = 1;
        }
        if(cnt != 0) cout << -1 << endl;
        else {
            cout << *max_element(all(c)) << endl;
            for(auto e : c) {
                cout << e << " ";
            };
        }
    }
}