const { stdin, stdout } = require('process');
const readline = require('readline');
const rl = readline.createInterface({
  input : stdin,
  output : stdout,
});
let input;
rl.on('line', line => {
  input = parseInt(line);
}).on('close', ()=>{
  let A = Math.floor(input/10);
  let B = input%10;
  let result = A+B;
  let cycle=1;
  while(B*10+result%10 != input){
    A = B;
    B = result%10;
    result = A + B;
    cycle++;
  }
  console.log(cycle);
})