#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> notes(N);

    for (int i = 0; i < N; i++)
        scanf("%d", &notes[i]);

    map<int, int> hash;
    vector<int> K(N), diff(N);

    K[0] = 0;
    diff[0] = 0;
    for (int i = 1; i < N; i++) {
        diff[i] = notes[i] - notes[0];
        if (notes[i] == notes[i - 1])
            K[i] = K[i - 1];
        else if (notes[i] > notes[i - 1])
            K[i] = K[i - 1] + 1;
        else
            K[i] = K[i - 1] - 1;

        if (K[i] != 0)
            if (diff[i] % K[i] == 0)
                if (diff[i] / K[i] >= 0)
                    hash[diff[i] / K[i]]++;
    }
    
    int ansK = 0, answer = 0;

    for (auto it = hash.begin(); it != hash.end(); it++)
        if (it->second > answer) {
            ansK = it->first;
            answer = it->second;
        }

    for (int i = 0; i < notes.size(); i++)
        if (notes[i] == notes[0] && K[i] == 0)
            answer++;

    printf("%d\n%d\n", answer, ansK);
}
