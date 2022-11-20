const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

let input=[];
rl.on('line',line=>{
  input.push(line);
}).on('close',()=>{
  const N = parseInt(input[0]);
  const stringData = input[1].split(' ');
  let data =[];
  for(let i=0; i < N; i++){
    data.push(parseInt(stringData[i]))
  }
  let max = Math.max.apply(null,data);
  let min = Math.min.apply(null,data);
  console.log(min,max);
  process.exit();
});