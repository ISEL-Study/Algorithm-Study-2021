#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;


/*
* 투 포인터 알고리즘 (부분합 구할 때 많이 사용)
* 특정 조건 (여기서는 모든 종류의 보석을 포함할 때) 까지 end 포인터를 증가시키고
* start 포인터를 조건이 틀리지 않을 때까지 증가시켜 거리의 최소를 구한다
*/


vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    unordered_map<string, int> m;
    set<string> s(gems.begin(), gems.end());
    
    int mini, start = 0, end = 0;
    
    // end = 모든 보석을 포함하는 첫 번째 구간
    for (string i : gems) {
        m[i] += 1;
        if (m.size() == s.size())
            break;
        end++;
    }
    
    
    mini = end - start;
    answer[0] = start + 1;
    answer[1] = end + 1;
    
    
    while(end < gems.size())
    {
        string key = gems[start];
        m[key] -= 1;
        start++;
        
      // start를 증가시켜 해당 보석을 삭제했는데 종류가 0이 될 때
        if (m[key] == 0) {
          // end 포인터를 증가시켜 뒤 보석을 포함시켜준다
            end++;
            
            for (; end < gems.size(); end++) {
                m[gems[end]] += 1;
                
                if (key == gems[end])
                    break;
            }
            
            if (end == gems.size())
                break;
        }
        
      //
        if (mini > end - start) {
            answer[0] = start + 1;
            answer[1] = end + 1;
            mini = end - start;
        }
    }
    
    return answer;
}
