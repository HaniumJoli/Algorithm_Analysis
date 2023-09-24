#include<bits/stdc++.h>
using namespace std;

string addbinary(string s, string t) {
    int ns = s.size() - 1;
    int nt = t.size() - 1;
    int carry = 0;
    string ans = "";

    while (ns >= 0 || nt >= 0 || carry) {
        int sum = carry;

        if (ns >= 0) {
            sum += s[ns] - '0';
            ns--;
        }
        if (nt >= 0) {
            sum += t[nt] - '0';
            nt--;
        }

        carry = sum / 2;
        sum = sum % 2;

        ans = to_string(sum) + ans;
    }

    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    string ans = addbinary(s, t);
    cout << ans << endl;
    return 0;
}
