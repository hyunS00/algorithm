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
  isEmpty(){
    return this.size<=0?1:0;
  }
  getSize(){
    return this.size;
  }
  top(){
    return (this.isEmpty()) ? -1:this.head.data;
    
  }
  push(data){
    let node = new Node(data);
    node.next = this.head;
    this.head = node;
    this.size++;
  }
  pop(){
    if(this.isEmpty()) return -1;
    let node = this.head;
    this.head = node.next;
    this.size--;
    return node.data;
  }
}

const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\r\n');
let s = new Stack;
let N = parseInt(input[0]);
let answer = '';
for(let i=1;i<=N;i++){
  let command = input[i]
  switch(command){
    case 'empty': 
      answer += s.isEmpty()+'\n';
      break;
    case 'size':
      answer += s.getSize()+'\n';
      break;
    case 'top':
      answer +=s.top()+'\n';
      break;
    case 'pop': 
      answer +=s.pop()+'\n';
      break;
    default: 
      s.push(+command.substring(5));
  }
}
console.log(answer);