function solution(picks, minerals) {
    var answer = 0;
    // 곡괭이 갯수만큼 배열 자르기
    let sliceMinerals = minerals.slice(0, (picks[0] + picks[1] + picks[2]) * 5);
    
    // 한 곡괭이로 한번에 캘 수 있는 만큼 배열에 담기
    let component = [];
    for (let i = 0; i < sliceMinerals.length; i += 5) {
      component.push([
        sliceMinerals[i] || "",
        sliceMinerals[i + 1] || "",
        sliceMinerals[i + 2] || "",
        sliceMinerals[i + 3] || "",
        sliceMinerals[i + 4] || "",
      ]);
    }
    
    // 한번에 캘 때 최대 피로도 담기(25, 5, 1로 세팅하면 겹치는 부분 발생해서 안겹치게 아예 높임)
    let weight = [];
    for (let i = 0; i < component.length; i++) {
      let totalWeight = 0;
      component[i].forEach((mineral) => {
        if (mineral == "diamond") totalWeight += 100;
        if (mineral == "iron") totalWeight += 10;
        if (mineral == "stone") totalWeight += 1;
      });
      weight.push(totalWeight);
    }
    
    // 피로도 내림차순 && 광물도 피로도와 같이 내림차순
    for (let i = 0; i < weight.length - 1; i++) {
      for (let j = i + 1; j < weight.length; j++) {
        if (weight[i] < weight[j]) {
          [weight[i], weight[j]] = [weight[j], weight[i]];
          [component[i], component[j]] = [component[j], component[i]];
        }
      }
    }
    
    // 다이아몬드 -> 철 -> 돌 곡괭이 순으로 광물 캐기 시작
    let componentLength = 0;
    for (let i = 0; i < picks.length; i++) {
      for (let j = 0; j < picks[i]; j++) {
        if (componentLength >= component.length) break;
        if (i == 0) {
          for (let k = 0; k < component[componentLength].length; k++) {
            if (component[componentLength][k]) answer += 1;
          }
        } else if (i == 1) {
          for (let k = 0; k < component[componentLength].length; k++) {
            if (component[componentLength][k] == "diamond") answer += 5;
            else if (component[componentLength][k]) answer += 1;
          }
        } else if (i == 2) {
          for (let k = 0; k < component[componentLength].length; k++) {
            if (component[componentLength][k] == "diamond") answer += 25;
            else if (component[componentLength][k] == "iron") answer += 5;
            else if (component[componentLength][k]) answer += 1;
          }
        }
        componentLength += 1;
      }
    }
    return answer;
}