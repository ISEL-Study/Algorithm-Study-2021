#include <iostream>

using namespace std;

int reverse_num(int num) {
    int a = num / 100;
    int b = (num % 100) / 10;
    int c = ((num % 100) % 10);

    int result = c * 100 + b * 10 + a;

    return result;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    n1 = reverse_num(n1);
    n2 = reverse_num(n2);

    if (n1 > n2) cout << n1 << endl;
    else cout << n2 << endl;

    return 0;
}
