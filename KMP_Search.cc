#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix;

void preprocess_prefix(vector<char> pattern) {
    int i = 0;
    for (int j = 1; j < pattern.size(); j++) {
        while (i > 0 && pattern[i] != pattern[j]) {
            i = prefix[i];
        }
        if (pattern[i] == pattern[j]) {
            i++;
        }
        prefix[j] = i;
    }
}

int KMPSearch(vector<char> pattern, vector<char> txt) {
    int txtlen = txt.size();
    int i = 0, j = 0;
    while (i < txtlen) {
        if (pattern[j] == txt[i]) {
            j++; i++;
        }
 
        if (j == prefix.size()) {
            cout << i - j << endl;
            j = prefix[j - 1];
        }
 
        else if (i < txtlen && pattern[j] != txt[i]) {
            if (j != 0)
                j = prefix[j - 1];
            else
                i++;
        }
    }
}

int main () {
    string pattern, text;
    cin >> pattern >> text;
    vector<char> p(pattern.begin(), pattern.end()), 
                 t(text.begin(), text.end());
    prefix.resize(p.size());
    preprocess_prefix(p);
    KMPSearch(p, t);
    return 0;
}