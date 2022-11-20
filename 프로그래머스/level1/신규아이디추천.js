function solution(new_id) {
  let trans_id1 = [];
  let trans_id2 = [];
  let trans_id3=[];
  let trans_id4=[];
  let trans_id5=[];
  let trans_id6=[];
  let trans_id7=[];
  let id,idNum;
  let i;
  for (i = 0; i < new_id.length; i++) {
    id = new_id[i];
    idNum = id.charCodeAt(0);
    //1단계 소문자변환
    if (idNum >= 65 && idNum <= 90) {
      id = String.fromCharCode([idNum + 32]);
      //소문자,숫자,빼기,밑줄,마침표를 제외한 문자 제거
    }
    trans_id1.push(id);
  }
  //2단계 특정문자 제거
  for (i = 0; i < trans_id1.length; i++) {
    id = trans_id1[i];
    idNum = id.charCodeAt(0);
    if (!((idNum >= 97 && idNum <= 122) ||(idNum >= 48 && idNum <= 57) ||idNum == 45 ||idNum == 95 ||idNum == 46)) {
      continue;
    }
    trans_id2.push(id);
  }
  //3단계 연속되는 . 치환
  let dotCount=0;
  for(i=0; i<trans_id2.length;i++){
    id = trans_id2[i];
    idNum = id.charCodeAt(0);
    if(idNum ==46){
      dotCount++;
    }else if(dotCount){
      trans_id3.push('.');
      trans_id3.push(id);
      dotCount=0;
    }else{
      trans_id3.push(id);
      dotCount=0;
    }
  }
  if(dotCount){
    trans_id3.push('.');
  }
  //4단계 처음과 끝 . 제거
  if(trans_id3[0]&&trans_id3[0].charCodeAt(0)==46){
    trans_id3.shift();
  }
  if(trans_id3[0]&&trans_id3[trans_id3.length-1].charCodeAt(0)==46){
    trans_id3.pop();
  }
  trans_id4=trans_id3;
  //5단계 빈문자 a대입
  if(trans_id4.length==0) {
    trans_id5=["a"];
  }else{
    trans_id5=trans_id4;
  }
  //6단계 16자이상 글자 자르기
  if(trans_id5.length>=16){
    trans_id6=trans_id5.slice(0,15);
    if(trans_id6[trans_id6.length-1].charCodeAt(0)==46) trans_id6.pop();
  }else{
    trans_id6=trans_id5;
  }
  //7단계
  let arrLength=trans_id6.length;
  if(arrLength<=3){
    trans_id7=trans_id6;
    for(;arrLength<3;){
      trans_id7.push(trans_id6[arrLength-1]);
      arrLength++;
    }
  }else{
    trans_id7=trans_id6;
  }

  var answer = trans_id7.join('');
  return answer;
}
let new_id = [
  "...!@BaT#*..y.abcdefghijklm",
  "z-+.^.",
  "=.=",
  "123_.def",
  "abcdefghijklmn.p",
];

for (let i = 0; i < new_id.length; i++) {
  console.log(solution(new_id[i]));
}
// console.log(solution('=.='));
