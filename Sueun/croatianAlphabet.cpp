#include <iostream>
#include <string>

using namespace std;

int main() {
    string alphabet;
    getline(cin, alphabet);

    int count = 0;
    int array_count = 0;

    for (int i = 1; i < alphabet.length(); i++) {
        if (alphabet[i] == '=' || alphabet[i] == '-' || alphabet[i] == 'j') {
            if (alphabet[i] == 'j' && alphabet[i-1] != 'l' && alphabet[i-1] != 'n') {
                count++;
                array_count++;
                continue;
            }
            count++;
            array_count += 2;
            if (alphabet[i-1] == 'z' && alphabet[i-2] == 'd') array_count++;
            
        }
    }

    count += (alphabet.length() - array_count);
    cout << count << endl;

    return 0;
}

