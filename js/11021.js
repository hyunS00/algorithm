const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

let count=1;
let input;
let answer='';
rl.on('line', line =>{
  input = line.split(' ');
  let A;
  let B;
  if(input.length === 2){
    A = parseInt(input[0]);
    B = parseInt(input[1]);
    answer += `Case #${count}: ${A+B}\n`;
    count++;
  }
}).on('close',()=>{
  console.log(answer);
})