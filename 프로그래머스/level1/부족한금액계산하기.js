function solution(price, money, count) {
  let sumPrice = 0;
  var answer;
  for (let i = 1; i <= count; i++) {
    sumPrice += price * i;
  }
  if (sumPrice > money) {
    answer = sumPrice - money;
  } else {
    answer = 0;
  }
  return answer;
}

const data = { price: 3, money: 20, count: 4 };

console.log(solution(data.price, data.money, data.count));
