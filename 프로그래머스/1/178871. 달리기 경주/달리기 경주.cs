using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string[] players, string[] callings) {
      
      Dictionary<string, int> sunwi = new Dictionary<string, int>();

      for (int i =0; i < players.Length; i++)
      {
        sunwi.Add(players[i], i);
      }

      for(int i=0; i < callings.Length; i++)
      {
        int num = sunwi[callings[i]];
        string firstPerson = players[num - 1];
        players[num - 1] = players[num];
        players[num] = firstPerson;

        sunwi[callings[i]]--;
        sunwi[firstPerson]++;
      }
    return players;
    }
}