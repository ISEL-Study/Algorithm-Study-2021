import java.util.*;

class Solution {
  public String solution(String m, String[] musicinfos) {
    //매치되는 곡이 없으면 "(None)"으로 리턴해야 되므로 미리 초기화
    String answer = "(None)";
    String start = "";
    String end = "";
    String name = "";
    String actual = "";
    int max = 0;
    
    //C#, A#과 같이 2글자는 그냥 다른 문자로 치환
    m = replaced(m);
    
    for (String info : musicinfos)
    {
      String[] each = info.split(",");
      
      start = each[0];
      end = each[1];
      name = each[2];
      
      String tmp = each[3];
      tmp = replaced(tmp);
      actual = tmp;

      // 재생된 시간 계산
      int len = cal(start, end);
    
      // 재생된 시간동안 문자열을 반복해 붙임
      for (int j = tmp.length(); j < len; j += tmp.length())
        actual += tmp;
      
      // 재생된 시간만큼 문자열 분리 (초과되어 붙여질 수 있으므로)
      actual = actual.substring(0, len);
      
      
      // 문제에서 조건에 일치하는 곡이 여러 개일 때 재생된 시간이 가장 길어야 하므로
      if (actual.contains(m)) {
        if (len > max) {
          max = len;
          answer = name;
        }
      }
    }
    
    return answer;
  }
  
  
  private int cal(String start, String end) {
    String[] s = start.split(":");
    String[] e = start.split(":");
    
    int hour = Integer.parseInt(e[0]) - Integer.parseInt(s[0]);
    int minute = Integer.parseInt(e[1]) - Integer.parseInt(s[1]);
    
    return (hour * 60 + minute);
  }
  
  
  private String replaced(String origin) {
    origin = origin.replace("C#", "1");
    origin = origin.replace("D#", "2");
    origin = origin.replace("F#", "3");
    origin = origin.replace("G#", "4");
    origin = origin.replace("A#", "5");
        
    return origin;
   }
}
      
