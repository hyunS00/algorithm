const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

let input=[];
let answer='';
rl.on('line', line=>{
  input.push(line);
}).on('close',()=>{
  let countArr = new Array(10).fill(0);
  let A = parseInt(input[0]);
  let B = parseInt(input[1]);
  let C = parseInt(input[2]);
  let result = (A*B*C).toString();
  for(let i = 0; i<result.length; i++){
    countArr[parseInt(result[i])]++
  }
  for(let i=0; i<10; i++){
    answer += `${countArr[i]}\n`;
  }
  console.log(answer);
  process.exit();
})