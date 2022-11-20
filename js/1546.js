const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

const input = [];
rl.on('line', line=>{
  input.push(line);
}).on('close',()=>{
  const N = parseInt(input[0]);
  const stringGrades = input[1].split(' ');
  const floatGrades = [];
  let M=0; 
  let sum = 0;
  for(let i=0;i<N;i++){
    floatGrades.push(parseFloat(stringGrades[i]));
    if(floatGrades[i]>M) M = floatGrades[i];
  }

  for(let i=0;i<N;i++){
    sum += floatGrades[i]/M*100;
  }
  console.log(sum/N);
})