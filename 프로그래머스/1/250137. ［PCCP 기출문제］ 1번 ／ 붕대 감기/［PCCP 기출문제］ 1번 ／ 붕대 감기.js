function solution(bandage, health, attacks) {
  let attaks_count = 0;
  let lucky_count = 0;
  let health_copy = health;

  for(let i=1; i<=attacks[attacks.length-1][0]; i++){
    //공격을 맞았을 때
    if(i == attacks[attaks_count][0]){
      health_copy -= attacks[attaks_count][1];

      // hp가 0 이하일 때
      if(health_copy <= 0){
        return -1;
      }
      attaks_count++;
      lucky_count = 0;
    }
    //공격을 안 맞았을 때
    else{
      lucky_count++;
      health_copy += bandage[1];
      // 횟수가 되었을 때
      if(lucky_count == bandage[0]){
        health_copy += bandage[2];
        lucky_count = 0;
      }
      // 체력 보다 많은 회복을 받으면 다시 고정
      if(health_copy > health){
        health_copy = health;
      }
    }
  }
  
  return health_copy;
}