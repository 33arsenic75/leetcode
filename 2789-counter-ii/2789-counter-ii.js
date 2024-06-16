/**
 * @param {integer} init
 * @return {Object}
 */
var createCounter = function(init) {
  var cnt = init;

  var increment = function() {
    cnt++;
    return cnt;
  };

  var decrement = function() {
    cnt--;
    return cnt;
  };

  var reset = function() {
    cnt = init;
    return cnt;
  };

  return {
    increment: increment,
    decrement: decrement,
    reset: reset,
  };
};
