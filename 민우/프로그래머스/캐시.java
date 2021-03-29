import java.util.*;

class Solution {
  public int solution(int cacheSize, String[] cities) {
    int answer = 0;
    
    // 캐시 크기가 0이면 모두 miss이므로 miss cost인 5를 곱해 리턴
    if (cacheSize == 0)
      return cities.length * 5;
    
    
    //이 문제는 Queue를 이용해야 한다 (FIFO)
    //자바에서는 Linked List가 Queue로 구현되어 있으므로 이를 사용한다
    LinkedList<String> cache = new LinkedList<>();
    
    for (int i = 0; i < cities.length; i++)
    {
      //대소문자 구분 없이 모두 소문자로 통일
      String city = cities[i].toLowerCase();
      
      /*
      LinkedList에 String city를 제거할 수 있다면
      즉, city가 이미 존재하므로 cache hit이며
      이미 지웠으므로 맨 앞에 추가해주고, hit cost를 증가
      */
      
      if (cache.remove(city))
      {
        cache.addFirst(city);
        answer++;
      }
      
      /*
      지울 수 없으면 cache miss
      캐시가 가득 차 있다면 LRU 방식이므로 맨 마지막을 제거한다 (오래된 것)
      */
      else {
        if (cacheSize == cache.size()) {
          // Linked List에도 pop() 메서드가 있지만, 맨 앞이 지워짐
          cache.pollLast();
        }
        
        cache.addFirst(city);
        answer++;
      }
    }
    
    return answer;
  }
