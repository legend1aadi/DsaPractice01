#include <iostream>
#include <string>
using namespace std;

void kmp(string pattern, string txt) {
    int M = pattern.length(), N = txt.length();
    int lps[100];//
    lps[0] = 0;
    for (int i = 1, prev = 0; i < M;) {
        if (pattern[i] == pattern[prev]) lps[i++] = ++prev;
        else if (prev != 0) prev = lps[prev - 1];
        else lps[i++] = 0;
    }
    int i = 0, j = 0;
    while (i < N) {
        if (pattern[j] == txt[i]) { i++; j++; }
        if (j == M) {
            cout << i - j << " ";
            j = lps[j - 1];
        } else if (i < N && pattern[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    kmp("ABABCABAB", "ABABDABACDABABCABAB");
    return 0;
}