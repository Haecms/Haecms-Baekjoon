function solution(k, score) {
    var answer = [];
    let honor = [];
    
    for (let i = 0; i < score.length; i++) {
      honor.push(score[i]);
      honor.sort((a, b) => b - a);
      if (honor.length > k) {
        honor.pop();
      }
      answer.push(honor[honor.length - 1]);
    }
    return answer;
}