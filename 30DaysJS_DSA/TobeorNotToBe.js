/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
  const number = {
    value: val,
    error: "",
    toBe: function (input) {
      if (input === val) {
        this.value = true;
        return this.value;
      } else {
        error = "Not Equal";
        return error;
      }
    },
    notToBe: function (input2) {
      if (input2 !== val) {
        this.value = true;
        return this.value;
      } else {
        error = "Equal";
        return error;
      }
    },
  };
  return number;
};

expect(5).toBe(5); // true
expect(5).notToBe(5); // throws "Equal"
