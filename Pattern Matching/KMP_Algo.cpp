#include <iostream>
#include <vector>

using namespace std;

vector<int> calculateLPS(const string& pattern) {
    int patternLength = pattern.length();
    vector<int> lps(patternLength, 0);

    int length = 0;  // Length of the previous longest prefix suffix

    for (int i = 1; i < patternLength; ++i) {
        if (pattern[i] == pattern[length]) {
            ++length;
            lps[i] = length;
        } else {
            if (length != 0) {
                length = lps[length - 1];
                --i; // Decrement 'i' to compare the current character again
            } else {
                lps[i] = 0;
            }
        }
    }

    return lps;
}

void KMPSearch(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    vector<int> lps = calculateLPS(pattern);

    int textIndex = 0; // Index for traversing the text
    int patternIndex = 0; // Index for traversing the pattern

    while (textIndex < textLength) {
        if (pattern[patternIndex] == text[textIndex]) {
            ++patternIndex;
            ++textIndex;
        }

        if (patternIndex == patternLength) {
            cout << "Pattern found at index " << textIndex - patternIndex << endl;
            patternIndex = lps[patternIndex - 1];
        } else if (textIndex < textLength && pattern[patternIndex] != text[textIndex]) {
            if (patternIndex != 0) {
                patternIndex = lps[patternIndex - 1];
            } else {
                ++textIndex;
            }
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    KMPSearch(text, pattern);

    return 0;
}
