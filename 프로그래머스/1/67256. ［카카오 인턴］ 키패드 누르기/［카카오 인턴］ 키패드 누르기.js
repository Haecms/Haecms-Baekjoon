function solution(numbers, hand) {
    var answer = '';
    let leftPlace = "*";
    let rightPlace = "#";
    
    let handPhone = [
      ["1", "2", "3"],
      ["4", "5", "6"],
      ["7", "8", "9"],
      ["*", "0", "#"],
    ];
    for (let number of numbers) {
      if (number % 3 == 1) {
        answer += "L";
        leftPlace = number;
      } else if (number % 3 == 0 && number != 0) {
        answer += "R";
        rightPlace = number;
      } else {
        const [leftDistance, rightDistance] = getDistance(number, leftPlace, rightPlace);
        if (leftDistance == rightDistance) {
          answer += hand == "right" ? "R" : "L";
          rightPlace = hand == "right" ? number : rightPlace;
          leftPlace = hand == "right" ? leftPlace : number;
        } else {
          answer += leftDistance > rightDistance ? "R" : "L";
          rightPlace = leftDistance > rightDistance ? number : rightPlace;
          leftPlace = leftDistance > rightDistance ? leftPlace : number;
        }
      }
    }
    
    function getDistance(number, leftPlace, rightPlace) {
      let left = 0;
      let right = 0;
      let numberPosition = 0;
      for (let i = 0; i < 4; i++) {
        for (let j = 0; j < 3; j++) {
          left = leftPlace == handPhone[i][j] ? [i, j] : left;
          right = rightPlace == handPhone[i][j] ? [i, j] : right;
          numberPosition = number == handPhone[i][j] ? [i, j] : numberPosition;
        }
      }
      let leftDistance = 0;
      let rightDistance = 0;
      for (let i = 0; i < 2; i++) {
        leftDistance += Math.abs(numberPosition[i] - left[i]);
        rightDistance += Math.abs(numberPosition[i] - right[i]);
      }
      return [leftDistance, rightDistance];
    }
    
    return answer;
}