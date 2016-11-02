#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int N;
    string word;
    
    while (cin >> N && N && cin >> word) {
        reverse(word.begin(), word.end());
        for (char &ch: word) {
            int new_ch;
            if (isalpha(ch))
                new_ch = ch - 'A';
            else if (ch == '_')
                new_ch = 26;
            else
                new_ch = 27;

            new_ch = (new_ch + N) % 28;

            if (new_ch <= 25)
                ch = 'A' + new_ch;
            else if (new_ch == 26)
                ch = '_';
            else
                ch = '.';
        }
        cout << word << "\n";
    }
}
