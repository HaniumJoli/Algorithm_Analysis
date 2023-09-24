#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    string s;
    getline(cin,s);
    int len = s.size();

    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            s[i] = (s[i] - 'a' - n+ 26) % 26 + 'a';

        }
    }

    cout << s << endl;
    return 0;
}
