//2627. Debounce
/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    return function(...args) {
        let context = this;
        let later = function() {
            fn.apply(context, args);
        }
        clearTimeout(fn.timer);
        fn.timer = setTimeout(later, t);
    }
};


const log = debounce(console.log, 100);
log('Hello'); // cancelled
log('Hello'); // cancelled
log('Hello'); // Logged at t=100ms
