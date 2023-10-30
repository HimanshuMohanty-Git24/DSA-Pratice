//2625. Flatten Deeply Nested Array
/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const res = []

    function dfs(arr, level) {
        for (const val of arr) {
            if (typeof val === 'object' && level < n) {
                dfs(val, level + 1)
            } 
            else {
                res.push(val)
            }
        }
        return res;
    }

    return dfs(arr, 0)
};