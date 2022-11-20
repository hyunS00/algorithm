function solution(id_list, report, k) {
  let answer = [];
  let reportCount = {};
  let reportUser = [];
  id_list.forEach((e) => {
    reportCount.e = 0;
  });
  report.forEach((e) => {
    reportUser += e.split(" ");
  });
  reportUser.forEach((e) => {
    reportCount.e++;
  });
  id_list.forEach((e) => {});
  return answer;
}

const data = [
  {
    id_list: ["muzi", "frodo", "apeach", "neo"],
    report: [
      "muzi frodo",
      "apeach frodo",
      "frodo neo",
      "muzi neo",
      "apeach muzi",
    ],
    k: 2,
  },
  {
    id_list: ["con", "ryan"],
    report: ["ryan con", "ryan con", "ryan con", "ryan con"],
    k: 3,
  },
];

data.forEach((e) => {
  solution(e.id_list, e.report, e.k);
});
