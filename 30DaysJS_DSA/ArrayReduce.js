//2626. Array Reduce Transformation
/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    if(nums.length===0){
        return init;
    }
    for (let i = 0; i < nums.length; i++) {
        init = fn(init, nums[i]);
    }
    return init;
};
//TestCase I
/*
Input:
nums = [1,2,3,4]
fn = function sum(accum, curr) { return accum + curr; }
init = 0
*/
//Output: 10
//Implementation
const nums = [];
const fn = function sum(accum, curr) { return 0; };
const init = 25;

console.log(reduce(nums, fn, init));

