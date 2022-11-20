const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N;
let answer = '';
rl.on('line',(line)=>{
  N = parseInt(line);
}).on('close',()=>{
  for(let i = N; i >0; i--){
    answer += i+'\n';
  }
  console.log(answer);
  process.exit();
})