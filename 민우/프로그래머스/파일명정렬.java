import java.util.*;

class Solution {
  public String[] solution(String[] files) {
    // Arrays 클래스에 대한 sort 재정의
    // Comparator 부분을 오버라이드하면 정렬 기준을 설정할 수 있다
    Arrays.sort(files, new Comparator<String>() {
      @override
      public int compare(String s1, String s2) {
        String[] file1 = detach(s1);
        String[] file2 = detach(s2);
        
        //헤더 부분이 같은지 판별
        int headv = file1[0].compareTo(file2[0]);
        
        if (headv == 0) {
          //같으면 그 다음 문자열 (NUMBER part) 검사 
          int num1 = Integer.parseInt(file1[1]);
          int num2 = Integer.parseInt(file2[1]);
          
          //문자열을 수로 바꾸고 그 차이 리턴 (이 차이로 순서 판별)
          return num1 - num2;
        }
        
        // 헤더가 다르면 헤더 차이 리턴
        // 앞이 크면 1, 같으면 0, 뒤가 크면 -1
        else {
          return headv;
        }
      }
      
      
      //주어진 문자열을 헤더, NUMBER, 테일로 나누는 메서드
      private String[] detach(String str) {
        String head = "";
        String number = "";
        String tail = "";
        
        int idx = 0;
        
        for ( ; idx < str.length(); idx++) {
          char ch = str.chatAt(idx);
          
          //숫자가 튀어나오면 헤더 다 만들어진 것
          if (ch >= '0' && ch <= '9')
            break;
          
          head += ch;
        }
        
        
        for ( ; idx < str.length(); idx++) {
          char ch = str.charAt(idx);
          
          //숫자가 아닌 게 튀어나오면 NUMBER 다 만들어진 것
          if (!(ch >= '0' && ch <= '9'))
            break;
          
          number += ch;
        }
        
        
        //테일은 나머지
        tail = str.substring(idx, str.length());
        String[] each = {head.toLowerCase(), number, tail};
        
        return each;
      }
    });
    
    return files;
  }
}
