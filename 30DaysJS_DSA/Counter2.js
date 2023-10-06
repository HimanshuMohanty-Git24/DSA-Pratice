/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let res= init;
    return{
        increment: function(){
            init++;
            return init;
        },
        decrement: function(){
            init--;
            return init;
        },
        reset: function(){
            init = res;
            return init;
        }
    }
};


const counter = createCounter(5)
console.log(counter.increment()); // 6
console.log(counter.reset()); // 5
console.log(counter.decrement()); // 4
