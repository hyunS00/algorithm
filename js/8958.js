const { stdin, stdout } = require('process');
const readline = require('readline');
const rl = readline.createInterface({
  input : stdin,
  output : stdout,
});

let input = [];
let answer = '';
rl.on('line',line=>{
  input.push(line);
}).on('close',()=>{
  let count;
  const testCaseNumber = parseInt(input[0]);
  let testCase;
  let sum;
  for(let i=1; i<=testCaseNumber; i++){
    testCase = input[i];
    count=sum=0;
    for(let j=0; j<testCase.length;j++){
      if(testCase[j] ==='O'){
        count++
        sum +=count;
      }else{
        count = 0;
      }
    }
    answer += `${sum}\n`;
  }
  console.log(answer);
})