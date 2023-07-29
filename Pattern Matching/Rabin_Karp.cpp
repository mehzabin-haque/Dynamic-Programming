#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int prime = 101; // A prime number for hashing

long long calculateHash(const string& str, int len) {
    long long hashValue = 0;
    for (int i = 0; i < len; ++i) {
        hashValue += (long long)(str[i] - 'a' + 1) * pow(prime, i);
    }
    return hashValue;
}

long long reCalculateHash(long long oldHash, char oldChar, char newChar, int patternLen) {
    long long newHash = oldHash - (oldChar - 'a' + 1);
    newHash /= prime;
    newHash += (long long)(newChar - 'a' + 1) * pow(prime, patternLen - 1);
    return newHash;
}

bool isEqual(const string& text, int start, const string& pattern) {
    for (int i = 0; i < pattern.size(); ++i) {
        if (text[start + i] != pattern[i]) {
            return false;
        }
    }
    return true;
}

vector<int> rabinKarp(const string& text, const string& pattern) {
    vector<int> occurrences;
    int patternLen = pattern.size();
    int textLen = text.size();
    long long patternHash = calculateHash(pattern, patternLen);
    long long textHash = calculateHash(text, patternLen);

    for (int i = 0; i <= textLen - patternLen; ++i) {
        if (patternHash == textHash && isEqual(text, i, pattern)) {
            occurrences.push_back(i);
        }
        if (i < textLen - patternLen) {
            textHash = reCalculateHash(textHash, text[i], text[i + patternLen], patternLen);
        }
    }

    return occurrences;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern to search for: ";
    cin >> pattern;

    vector<int> occurrences = rabinKarp(text, pattern);

    if (occurrences.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int pos : occurrences) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}
