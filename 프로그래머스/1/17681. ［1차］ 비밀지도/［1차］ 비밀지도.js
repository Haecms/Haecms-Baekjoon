function solution(n, arr1, arr2) {
    var answer = [];
    let copyArr1 = [];
    let copyArr2 = [];
    let realMap = [];

    for (let i = 0; i < n; i++) {
      copyArr1.push(process(arr1[i]));
      copyArr2.push(process(arr2[i]));
    }
    
    for (let i = 0; i < n; i++) {
      let primaryArray = [];
      for (let j = 0; j < n; j++) {
        if (copyArr1[i][j] == 0 && copyArr2[i][j] == 0) {
          primaryArray.push(0);
        } else {
          primaryArray.push(1);
        }
      }
      realMap.push(primaryArray);
    }
    
    for (let i = 0; i < n; i++) {
      let sAnswer = "";
      for (let j = 0; j < n; j++) {
        sAnswer += realMap[i][j] == 0 ? " " : "#";
      }
      answer.push(sAnswer);
    }
    
    function process(number) {
      let arr6 = [];
      for (let i = 0; i < n; i++) {
        if (number % 2 == 0) {
          arr6.push(0);
          number = number / 2;
        } else {
          arr6.push(1);
          number = (number - 1) / 2;
        }
      }
      return arr6.reverse();
    }
        return answer;
}