#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, int> m;
    
    for (int i = 0; i < skill.length(); i++)
        m[skill[i]] = i + 1;
    
    
    for (int i = 0; i < skill_trees.size(); i++)
    {
        string t = skill_trees[i];
        int cnt = 1;
        bool brek = false;
        
        for (int j = 0; j < t.length(); j++)
        {
            int r = m[t[j]];
            
            if (cnt < r) {
                brek = true;
                break;
            }
            
            else if (cnt == r)
                cnt++;
        }
        
        if (!brek)
            answer++;
    }
    
    return answer;
}
