#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int visit[9] = {0,};
int uid_size = 0;
int bid_size = 0;

vector<string> uid;
vector<string> bid;

vector<int> v;

set<vector<string>> s;


// a : target, b : banned_id element
bool check(string a, string b) {
    if (a.length() != b.length())
        return false;
    
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == '*')
            continue;
        
        if (a[i] != b[i])
            return false;
    }
    
    return true;
}



/*
* DFS로 모든 (겹치지 않는, visit으로 해결 가능) 순열을 구한다
* 중복 허용하지 않는 set을 사용해 위에서 구한 순열 벡터를 sort하여 넣는다
*/

void DFS() {
    
    if (v.size() == bid_size) {
        
        bool enable = true;
        // index pair (size = size of banned_id)
        for (int i = 0; i < v.size(); i++)
        {
            int t = v[i];
            if (!check(uid[t], bid[i])) {
                enable = false;
                break;
            }
        }
        
        if (enable) {
            vector<string> tmp;
            
            for (int i = 0; i < v.size(); i++) {
                int t = v[i];
                tmp.push_back(uid[t]);
            }
            
            sort(tmp.begin(), tmp.end());
            
            if (s.find(tmp) == s.end())
                s.insert(tmp);
        }
        
        return;
    }
    
    
    
    for (int i = 0; i < uid_size; i++)
    {
        if (visit[i] == 1)
            continue;
        
        visit[i] = 1;
        v.push_back(i);
        DFS();
        v.pop_back();
        visit[i] = 0;
    }
}



int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    uid_size = user_id.size();
    bid_size = banned_id.size();
    
    bid = banned_id;
    uid = user_id;
    
    DFS();
    
    answer = s.size();
    
    return answer;
}
