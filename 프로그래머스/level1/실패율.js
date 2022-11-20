function solution(N, stages) {
  let count; //그 스테이지 몇명인지 카운트
  let playerTry = stages.length; // 총몇명인지
  let failureRate = []; //실패율을 스테이지별로 담을 배열
  let i, j;
  for (i = 0; i < N; i++) {
    failureRate.push(0);
  }

  //실패율 계산
  for (i = 0; i < N; i++) {
    count = 0;
    for (j = 0; j < stages.length; j++) {
      if (stages[j] === i + 1) count++; //그 스테이지 몇명인지 계산
    }
    //실패율 계산해서 해당인덱스 담기
    failureRate[i] = count / playerTry;
    playerTry -= count;
    if (playerTry === 0) break;
  }
  //실패율 큰순서로 뽑기
  let max;
  var answer = [];
  for (i = 0; i < N; i++) {
    max = -1;
    //최대값 구하기
    for (j = 0; j < failureRate.length; j++) {
      if (failureRate[j] > max) max = failureRate[j];
    }
    //최대값이 포함된 인덱스를 anser푸시하고 -1로 초기화
    answer.push(failureRate.indexOf(max) + 1);
    failureRate[failureRate.indexOf(max)] = -1;
  }

  return answer;
}

//전체스테이지 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지 번호가 담긴 배열 stages
const data = [
  { N: 5, stages: [2, 1, 2, 6, 2, 4, 3, 3] },
  { N: 4, stages: [4, 4, 4, 4, 4] },
  { N: 5, stages: [4, 4, 4, 4, 4] },
];

data.forEach((element) => {
  //solution(element.N, element.stages);
  console.log(solution(element.N, element.stages));
});
