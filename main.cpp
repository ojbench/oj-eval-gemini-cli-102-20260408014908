#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int charToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return 0;
}

char intToChar(int v) {
    if (v >= 0 && v <= 9) return '0' + v;
    return 'A' + (v - 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, B;
    if (!(cin >> m >> n >> B)) return 0;
    string str1, str2;
    cin >> str1 >> str2;

    int len1 = m - 1;
    int len2 = n - 1;
    int maxLen = max(len1, len2);

    string res = "";
    int carry = 0;
    int i = str1.length() - 1;
    int j = str2.length() - 1;

    for (int k = 0; k < maxLen; ++k) {
        int v1 = (i >= 0) ? charToInt(str1[i]) : 0;
        int v2 = (j >= 0) ? charToInt(str2[j]) : 0;
        int sum = v1 + v2 + carry;
        res += intToChar(sum % B);
        carry = sum / B;
        i--;
        j--;
    }

    reverse(res.begin(), res.end());
    cout << res << "\n";

    return 0;
}
