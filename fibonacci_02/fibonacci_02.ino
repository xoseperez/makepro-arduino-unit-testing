/*
 * Fibonacci Number generator for Arduino
 * Testing with AUnit
 */

#include <AUnit.h>

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
 * Testing method using AUnit
 */
test(fibonacci) {

    // Expected values taken from https://www.tools4noobs.com/online_tools/fibonacci/
    assertEqual(fibonacci(0 ), (unsigned long) 0);
    assertEqual(fibonacci(1 ), (unsigned long) 1);
    assertEqual(fibonacci(2 ), (unsigned long) 1);
    assertEqual(fibonacci(3 ), (unsigned long) 2);
    assertEqual(fibonacci(5 ), (unsigned long) 5);
    assertEqual(fibonacci(10), (unsigned long) 55);
    assertEqual(fibonacci(20), (unsigned long) 6765);
    assertEqual(fibonacci(30), (unsigned long) 832040);

}

/*
 * Arduino entry point method
 */
void setup() {

    Serial.begin(115200);
    while (!Serial);
    Serial.println();
    Serial.println("Fibonacci number generator - test 02");
    Serial.println();

}

/*
 * Arduino loop
 */
void loop() {
    aunit::TestRunner::run();
}