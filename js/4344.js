const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

const input= [];
let answer = '';
rl.on('line',line=>{
  input.push(line);
}).on('close',()=>{
  const C = parseInt(input[0]);
  let sum;
  let average;
  let count;
  let studentNum;
  for(let i=1; i<=C; i++){
    let testCase = input[i].split(' ');
    studentNum = testCase[0];
    let intTestCase = [];
    sum = 0;
    for(let j=0; j < studentNum; j++){
      intTestCase.push(parseInt(testCase[j+1]));
      sum += intTestCase[j];
    }
    average = sum/studentNum;
    count = 0;
    for(let j=0;j <studentNum; j++){
      if(intTestCase[j]>average) count++;
    }
    answer += `${(count/studentNum*100).toFixed(3)}%\n`;
  }
  console.log(answer);
});