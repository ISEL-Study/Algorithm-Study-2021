#include <iostream>
#include <string>

using namespace std;

int wordToTime(char c) {
    int time = 3;
    time += (c - 'A') / 3;

    if (c == 'S' || c == 'V' || c == 'Y' || c == 'Z') time--;
    
    return time;
}

int main() {
    string word;
    getline(cin, word);

    int total = 0;

    for (int i = 0; i < word.length(); i++) {
        total += wordToTime(word[i]);
    }

    cout << total << endl;

    return 0;
}
