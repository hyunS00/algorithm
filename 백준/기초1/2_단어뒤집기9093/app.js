const readline = require('readline');
const rl = readline.createInterface({
  input : process.stdin,
  output : process.stdout,
});

class Node{
  constructor(data){
    this.data = data;
    this.next = null;
  }
}

class Stack{
  constructor(){
    this.head = null;
    this.size = 0;
  }
  push(data){
    let node = new Node(data);
    node.next = this.head;
    this.head = node;
    this.size++;
  }
  pop(){
    let node = this.head;
    this.next = node.next;
    this.head = this.next;
    this.size--;
    return node.data;
  }
}
let input = [];
let s = new Stack();
let answer='';
rl.on("line",line=>{
  input.push(line);
}).on('close',()=>{
  let t = +input[0];
  let testCase;
  let testArr;
  let stringArr;
  for(let i=1;i<=t;i++){
    testCase = input[i].split(' ');
    for(let j=0;j<testCase.length;j++){
      testArr = testCase[j].split(' ');
      for(let k=0;k < testArr.length; k++){
        stringArr = testArr[k];
        for(let l =0;l<stringArr.length;l++){
          s.push(stringArr[l]);
        }
        for(let l =0;l<stringArr.length;l++){
          answer+=s.pop();
        }
        answer+=' ';
      }
    }
    answer+='\n';
  }
  console.log(answer);
});