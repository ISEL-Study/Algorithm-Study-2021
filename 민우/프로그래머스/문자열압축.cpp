#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for (int i = 1; i <= s.length() / 2; i++)
    {
        int semi = s.length();
        string tmp = s.substr(0, i);
        int cnt = 0;
        
        for (int j = i; j <= s.length(); j += i)
        {
            //cout << s.substr(j, i) << " " << tmp << endl;
            string sub = s.substr(j,i);
            
            // 같으면
            if (sub.compare(tmp) == 0)
            {
                cnt++;    
            }
            
            // 다르면
            else
            {
                semi -= (cnt * i);
                
                if (cnt > 0 && cnt < 9)
                    semi += 1;
                else if (cnt >= 9 && cnt < 99)
                    semi += 2;
                else if (cnt >= 99 && cnt < 999)
                    semi += 3;
                else if (cnt >= 999)
                    semi += 4;
                
                cnt = 0;
            }
            
            
            
            
            tmp = s.substr(j, i);
            
        }
        
        
        answer = min(semi, answer);
        //cout << "i = " << i << ", " << answer << endl;
    }
    
    
    return answer;
}
