#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int eq1 = brown / 2 + 2; // a + b = eq1
    int eq2 = brown + yellow;   // a * b = eq2

    //정사각형인지 판별
    int x = sqrt(yellow);
    bool ist = (x*x == yellow ? true : false);

    if (ist)
    {
        answer.push_back(eq1/2);
        answer.push_back(eq1/2);
        return answer;
    }

    else
    {
        int t1 = pow(eq1, 2);
        int t2 = t1 - 4*eq2;

        int t3 = sqrt(t2);
        int t4 = (eq1 + t3) / 2;
        int t5 = eq1 - t4;
        answer.push_back(t4);
        answer.push_back(t5);
    }

    return answer;
}
