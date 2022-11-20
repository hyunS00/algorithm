const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

let input;
let A;
let B;
rl.on('line', line => {
  input = line.split(' ');
  A = parseInt(input[0]);
  B = parseInt(input[1]);
  console.log(A+B);
}).on('close',()=>{
  process.exit();
});