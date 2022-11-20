const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

let input;
let answer = '';
let A;
let B;
rl.on('line', line=>{
  input = line.split(' ');
  A = parseInt(input[0]);
  B = parseInt(input[1]);
  if(A===0 && B===0){
    rl.close();
  }
  answer += `${A+B}\n`;
}).on('close', ()=>{
  console.log(answer);
  process.exit();
})