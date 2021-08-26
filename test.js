function getIndex(x, y, maxX) {
  return x + y * maxX;
}

function isValid(x, y, maxX, maxY) {
  return x >= 0 && x < maxX && y >= 0 && y < maxY;
}

function createMap(maxX, maxY, roleMap) {
  let map = new Array(maxX * maxY).fill(maxX * maxY);
  let centerX = Math.floor(maxX / 2);
  let centerY = Math.floor(maxY / 2);
  let stack = [];
  map[getIndex(centerX, centerY, maxX)] = 1;
  stack.push([centerX, centerY]);
  while (stack.length) {
    let [x, y] = stack.shift();
    let temp = map[getIndex(x, y, maxX)] + 1;
    if (
      isValid(x + 1, y, maxX, maxY) &&
      map[getIndex(x + 1, y, maxX)] > temp &&
      roleMap[getIndex(x + 1, y, maxX)] !== 1
    ) {
      map[getIndex(x + 1, y, maxX)] = temp;
      stack.push([x + 1, y]);
    }
    if (
      isValid(x - 1, y, maxX, maxY) &&
      map[getIndex(x - 1, y, maxX)] > temp &&
      roleMap[getIndex(x - 1, y, maxX)] !== 1
    ) {
      map[getIndex(x - 1, y, maxX)] = temp;
      stack.push([x - 1, y]);
    }
    if (
      isValid(x, y + 1, maxX, maxY) &&
      map[getIndex(x, y + 1, maxX)] > temp &&
      roleMap[getIndex(x, y + 1, maxX)] !== 1
    ) {
      map[getIndex(x, y + 1, maxX)] = temp;
      stack.push([x, y + 1]);
    }
    if (
      isValid(x, y - 1, maxX, maxY) &&
      map[getIndex(x, y - 1, maxX)] > temp &&
      roleMap[getIndex(x, y - 1, maxX)] !== 1
    ) {
      map[getIndex(x, y - 1, maxX)] = temp;
      stack.push([x, y - 1]);
    }
  }
  return map;
}
let roleMap = [
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
];
function printMap(map) {
  let str = "";
  for (let i = 0; i < 19 * 19; i++) {
    if (i % 19 == 0) {
      console.log(str);
      str = "";
    }
    str += ("" + map[i]).padStart(4, " ");
  }
  console.log(str);
}
printMap(roleMap);
printMap(createMap(19, 19, roleMap));
