#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


string recursion(string p) {
    if (p.length() == 0)
        return "";
    
    string first = "";
    string second = "";
    
    int sp = 0;
    int left = 0;
    int right = 0;
    
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
            left++;
        else
            right++;

        if (left == right) {
            sp = i;
            break;
        }
    }
        
    first = p.substr(0, sp + 1);
    second = p.substr(sp + 1);
    
    
    bool complete = true;
    int n = first.length();

    
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (first[i] == '(')
            t++;
        else {
            if (t == 0) {
                complete = false;
                break;
            }
            
            t--;
        }
    }

    if (complete) {
        return first + recursion(second);
    }
    
    else {
        string tmp = "(" + recursion(second) + ")";
        
        string tmp2 = first.substr(1, first.length() - 2);
        
        for (int i = 0; i < tmp2.length(); i++)
        {
            if (tmp2[i] == '(')
                tmp += ")";
            else
                tmp += "(";
        }
        
        
        return tmp;
    }
}


string solution(string p) {
    string answer = "";
    
    if (p.length() == 0)
        return answer;
    
    answer = recursion(p);

    return answer;
}
