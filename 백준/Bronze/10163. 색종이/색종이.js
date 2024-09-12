const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().replace(/\r/g, "");
input = input.trim().split("\n");

const arr = [];
for(let i=0; i<input.length; i++){
    arr.push(input[i].split(" ").map(Number));
}
const N = arr.shift();

function solution(N, arr){
    let field = new Array(1002);
    for (let i = 0; i < 1002; i++) {
        field[i] = new Array(1002).fill(-1); 
    }

    for (let i=0; i<N; i++){
        for(let j=arr[i][0]; j<arr[i][0] + arr[i][2]; j++){
            for(let k=arr[i][1]; k< arr[i][1] + arr[i][3]; k++){
                field[j][k] = i;
            }
        }
    }

    for (let i = 0; i < N; i++) {
        let count = 0;
        for (let x = 0; x < 1002; x++) {
            for (let y = 0; y < 1002; y++) {
                if (field[x][y] === i) {
                    count++;
                }
            }
        }
        console.log(count);
    }
}

solution(N, arr)