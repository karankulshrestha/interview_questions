#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        int k;
        cin >> k;
        cin >> s;
        set<string> st;
        for(int i = 0; i<k-1; i++) {
            string temp = "";
            temp += s[i];
            temp += s[i + 1];
            st.insert(temp);
        };
        cout << st.size() << endl;
    };
    
};
