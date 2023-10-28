//2724. Sort By
/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    // your code here
    return arr.sort((a, b) => fn(a) - fn(b));
};