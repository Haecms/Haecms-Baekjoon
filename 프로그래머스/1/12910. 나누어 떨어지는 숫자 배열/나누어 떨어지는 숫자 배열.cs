using System;
public class Solution {
    public int[] solution(int[] arr, int divisor) {
            int count = 1;
            int j = 0;
            for(int i=0; i<arr.Length; i++)
            {
                if (arr[i] % divisor == 0)
                {
                    count++;
                }
            }
            int[] answer = new int[count];
            if(count != 1)
            {
                for(int i=0; i<count-1; i++)
                {
                    while (j<arr.Length)
                    {
                        if (arr[j] % divisor == 0)
                        {
                            answer[i] = arr[j];
                            j++;
                            break;
                        }
                        j++;
                    }
                }
            }
            else
            {
                answer[0] = -1;
            }
            if(count != 1)
            {
                Array.Resize(ref answer, count - 1);
            }
        Array.Sort(answer);
        return answer;
    }
}