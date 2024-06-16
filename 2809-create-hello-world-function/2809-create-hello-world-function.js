function createHelloWorld() {
  const greeting = "Hello World";
  
  return function() {
    return greeting;
  };
}