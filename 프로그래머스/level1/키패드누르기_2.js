const getDistance = (numPosition, handposition) => {
  return (
    Math.abs(numPosition / 10 - handposition / 10) +
    Math.abs((numPosition % 4) - (handposition % 4))
  );
};

function solution(numbers, hand) {
  let result = [];
  let leftHand = 41;
  let rightHand = 43;
  let num;
  for (let i = 0; i < numbers.length; i++) {
    num = numbers[i];
    if (num % 3 === 1) {
      leftHand = Math.floor((num / 3) * 10 + 1);
      result.push("L");
    } else if (num !== 0 && num % 3 === 0) {
      rightHand = Math.floor((num / 3) * 10 + 3);
      result.push("R");
    } else if (num === 0) {
      num = 42;
      if (getDistance(num, leftHand) > getDistance(num, rightHand)) {
        rightHand = Math.floor((num / 3) * 10 + 3);
        result.push("R");
      } else if (getDistance(num, leftHand) < getDistance(num, rightHand)) {
        leftHand = Math.floor((num / 3) * 10 + 1);
        result.push("R");
      } else if (hand === "right") {
        rightHand = Math.floor((num / 3) * 10 + 3);
        result.push("R");
      } else {
        leftHand = Math.floor((num / 3) * 10 + 1);
        result.push("L");
      }
    } else if (getDistance(num, leftHand) > getDistance(num, rightHand)) {
      rightHand = Math.floor((num / 3) * 10 + 3);
      result.push("R");
    } else if (getDistance(num, leftHand) < getDistance(num, rightHand)) {
      leftHand = Math.floor((num / 3) * 10 + 1);
      result.push("R");
    } else if (hand === "right") {
      rightHand = Math.floor((num / 3) * 10 + 3);
      result.push("R");
    } else {
      leftHand = Math.floor((num / 3) * 10 + 1);
      result.push("L");
    }
    console.log(leftHand, rightHand, num);
  }
  var answer = result.join("");
  return answer;
}

data = [
  { numbers: [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], hand: "right" },
  // { numbers: [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], hand: "left" },
  // { numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 0], hand: "right" },
];

for (let i = 0; i < data.length; i++) {
  console.log(solution(data[i].numbers, data[i].hand));
}
