#include <iostream>
#include <vector>
using namespace std;

int solve(string s) {
    for(int i = 0; i<s.length(); i++) {
        if(s[i] != s[i + 1] && i + 1 < s.length()) {
            return s.length() - 1;
        };
    };
    return -1;
};

int main() {
    int n;
    cin >> n;
    while (n--)
    {
        string temp;
        cin >> temp;
        int a = solve(temp);
        cout << a << endl;
    };
    
};
