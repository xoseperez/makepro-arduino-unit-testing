/*
 * Fibonacci Number generator for Arduino
 * Self-written testing method
 */


// The 32 bits integer in the Atmel AVR overflows after F[47], 
// so we will calculate up to this number
#define MAX_NUMBER 47

// Cache array
unsigned long f[MAX_NUMBER+1] = { 0 };

/*
 * Calculates and returns the n-th Fibonacci Number
 */
unsigned long fibonacci(unsigned long n) {
    if (0 == n) return 0;
    if (1 == n) return 1;
    if (0 == f[n]) {
        f[n] = fibonacci(n-2) + fibonacci(n-1);
    }
    return f[n];
}

/*
 * Checks the output of the fibanicci method agains an expected value
 * Outputs via serial monitor the result
 */
bool testFibonacci(unsigned long input, unsigned long output) {
    Serial.print("Testing F["); 
    Serial.print(input);
    Serial.print("]: ");
    bool ret = (fibonacci(input) == output);
    Serial.println(ret ? "OK" : "ERROR");
    return ret;
}

/*
 * Arduino entry point method
 */
void setup() {

    Serial.begin(115200);
    while (!Serial);
    Serial.println();
    Serial.println("Fibonacci number generator - test 01");
    Serial.println();

    // Expected values taken from https://www.tools4noobs.com/online_tools/fibonacci/
    testFibonacci(0, 0);
    testFibonacci(1, 1);
    testFibonacci(2, 1);
    testFibonacci(3, 2);
    testFibonacci(5, 5);
    testFibonacci(10, 55);
    testFibonacci(20, 6765);
    testFibonacci(30, 832040);

}

/*
 * Arduino loop (not used here)
 */
void loop() {}