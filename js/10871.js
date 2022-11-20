const { read } = require('fs');
const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

const input = [];
let answer = '';
rl.on('line', line =>{
  input.push(line);
}).on('close', ()=>{
  let NX =input[0].split(' ');
  const N = parseInt(NX[0]);
  const X = parseInt(NX[1]);
  const stringA = input[1].split(' ');
  for(let i=0; i<N;i++){
    if(X >parseInt(stringA[i])){
      answer +=`${parseInt(stringA[i])} `;
    }
  }
  console.log(answer);
  process.exit();
});