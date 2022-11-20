let total = new Array(10000).fill().map((v,i)=>i+1)
let selfNum = total;
let noneSelf = [];
let stringNum;
let sum;
let answer = '';
for ( let i=0;i<total.length;i++){
  stringNum = String(total[i]);
  sum = total[i];
  for(let j=0;j<stringNum.length;j++){
    sum += Number(stringNum[j]);
  }
  if(sum<=10000 && !noneSelf.includes(sum))  noneSelf.push(sum);
}
for(let i=0; i<noneSelf.length; i++){
  selfNum.splice(total.indexOf(noneSelf[i]),1);
}
for(let i=0; i<selfNum.length;i++){
  answer +=`${selfNum[i]}\n`;
}
console.log(answer);