//2623. Memoize
/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    return function (...args) {
        let cache = fn.cache || {};
        let key = JSON.stringify(args);
        if (cache[key]) {
            console.log("cached");
            return cache[key];
        } else {
            console.log("not cached");
            let result = fn(...args);
            cache[key] = result;
            fn.cache = cache;
            return result;
        }
    };
}

function sum(a, b) {
    return a + b;
}

let memoizedSum = memoize(sum);

console.log(memoizedSum(0, 0)); // not cached, returns 0
console.log(memoizedSum(0, 0)); // cached, returns 0
console.log(memoizedSum.getCallCount()); // returns 2
