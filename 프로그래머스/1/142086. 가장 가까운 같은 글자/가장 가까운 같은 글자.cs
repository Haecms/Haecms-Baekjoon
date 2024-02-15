using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string s) {
        int[] answer = new int[s.Length];
        List<int> list = new List<int>();
        List<char> s_3 = new List<char>();
        int int_check = 0;
        int value = 0;

        for(int i=0; i<s.Length; i++)
        {
            char check = 'y';
            s_3.Add('5');
            for(int j=0; j<i; j++)
            {
                if (s[j] == s[i])
                {
                check = 'n';
                value = i - j;
                }
            }

            if (check == 'y') // 중복되는거 없이 나왔을 때
            {
                s_3.RemoveAt(int_check);
                s_3.Add(s[i]);
                int_check++;
                list.Add(-1);
            } // 중복 되는것이 있을 때
             else
            {
              s_3.RemoveAt(int_check);
              list.Add(value);
            }
            answer[i] = list[i];
        }
        return answer;
    }
}