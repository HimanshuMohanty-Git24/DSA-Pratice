//2635. Apply Transform Over Each Element in Array

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
  let arrres = [];
  for (let i = 0; i < arr.length; i++) {
    arrres.push(fn(arr[i], i));
  }
  return arrres;
};
