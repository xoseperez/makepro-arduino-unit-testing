/*
 * Fibonacci Number generator for Arduino
 * Initial code
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
 * Arduino entry point method
 */
void setup() {

    Serial.begin(115200);
    while (!Serial);
    Serial.println();
    Serial.println("Fibonacci number generator");
    Serial.println();

    unsigned long start = millis();

    char buffer[40];
    for (unsigned int i=0; i<=MAX_NUMBER; i++) {
        snprintf(buffer, sizeof(buffer), "F[%2d] = %lu\n", i, fibonacci(i));
        Serial.print(buffer);
    }

    Serial.println();
    unsigned long total = millis() - start;
    Serial.print("Total time (ms): ");
    Serial.println(total);

}

/*
 * Arduino loop (not used here)
 */
void loop() {}