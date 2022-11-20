function solution(n, lost, reserve) {
  //lost에 필터를 걸어 reserv와 중복된 값을 제거
  let lostFilter = lost.filter((e) => {
    return reserve.indexOf(e) === -1;
  });
  //reserve에 필터를 걸어 lost와  중복된값 제거
  let reserveFilter = reserve.filter((e) => {
    return lost.indexOf(e) === -1;
  });
  //체육복 가지고잇는 학생 오름차순 정렬
  reserveFilter.sort((a, b) => a - b);
  let i = 0;
  var answer = n - lostFilter.length;
  //체육복 자기고있는 학생 주위에 체육복 지급
  while (i < reserveFilter.length) {
    if (lostFilter.indexOf(reserveFilter[i] - 1) !== -1) {
      lost.splice(lostFilter.indexOf(reserveFilter[i] - 1), 1);
      answer += 1;
      i++;
    } else if (lostFilter.indexOf(reserveFilter[i] + 1) !== -1) {
      lostFilter.splice(lostFilter.indexOf(reserveFilter[i] + 1), 1);
      answer += 1;
      i++;
    } else {
      i++;
    }
  }

  return answer;
}

const data = [
  { n: 5, lost: [2, 4], reserve: [1, 3, 5] },
  { n: 5, lost: [2, 4], reserve: [3] },
  { n: 3, lost: [3], reserve: [1] },
];
for (let i = 0; i < data.length; i++) {
  console.log(solution(data[i].n, data[i].lost, data[i].reserve));
}
