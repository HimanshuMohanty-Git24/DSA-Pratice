//2715. Timeout Cancellation
/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    let timeout = setTimeout(fn, t, ...args);
    return function() {
        clearTimeout(timeout);
    };
};