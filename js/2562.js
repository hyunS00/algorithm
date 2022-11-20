const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

let max = 0;
let location;
let input = [];
rl.on('line',line=>{
  input.push(parseInt(line));
}).on('close',()=>{
  for(let i=0;i<10;i++){
    if(input[i]>max){
      max = input[i];
      location = i+1;
    }
  }
  console.log(`${max}\n${location}`);
  process.exit();
})