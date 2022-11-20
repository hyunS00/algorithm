const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

let input;
let includeArr=[];
rl.on('line', line=>{
  input = parseInt(line);
  if(!includeArr.includes(input%42)){
    includeArr.push(input%42);
  }
}).on('close',()=>{

  console.log(includeArr);
  process.exit();
})