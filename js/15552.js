const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let A;
let B;
let answer='';
rl.on('line', line =>{
  let input = line.split(' ');
  if(input.length === 2){
    A = parseInt(input[0]);
    B = parseInt(input[1]);
    answer += A+B+'\n';
  }
}).on('close',()=>{
  console.log(answer);
  process.exit();
})