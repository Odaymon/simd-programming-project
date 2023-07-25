// Steven John A. Pascaran / CSC 755M
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void x86_kernel(size_t ARRAY_SIZE, float* h_out, float* h_in);
extern void SIMDprocess(size_t ARRAY_SIZE, float* h_out, float* h_in);

// C function
void process(size_t n, float* h_out, float* h_in) {
    for (int i = 4; i + 3 < n; i++) {
        h_out[i] = h_in[i - 3] + h_in[i - 2] + h_in[i - 1] + h_in[i] + h_in[i + 1] + h_in[i + 2] + h_in[i + 3];
    }
}

int main() {
    //const size_t ARRAY_SIZE = 1 << 20;
    const size_t ARRAY_SIZE = 1 << 24;
    //const size_t ARRAY_SIZE = 1 << 30;
    const size_t ARRAY_BYTES = ARRAY_SIZE * sizeof(float);
    const int NO_OF_RUNS = 30; 

    // declare array
    float* in, * out;
    in = (float*)malloc(ARRAY_BYTES);
    out = (float*)malloc(ARRAY_BYTES);

    // timer variables
    clock_t start, end;

    // init array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        in[i] = (float)i;
    }

    // Flush out cache
    process(ARRAY_SIZE, out, in);

    // time here
    start = clock();
    for (int j = 0; j < NO_OF_RUNS; j++) {
        process(ARRAY_SIZE, out, in);
    }
    end = clock();
    double time_taken = (((double)(end - start)) / NO_OF_RUNS) * 1e6 / CLOCKS_PER_SEC;
    printf("C function will take %f microseconds for array size %zu\n", time_taken, ARRAY_SIZE);

    // error checking
    size_t error_count = 0;
    for (int i = 4; i + 3 < ARRAY_SIZE; i++) {
        float ans = in[i - 3] + in[i - 2] + in[i - 1] + in[i] + in[i + 1] + in[i + 2] + in[i + 3];
        if (i < 9) {
            printf("Execution #%i Result = %f\n", (i - 3), out[i]);
        }
        if (ans != out[i]) {
            error_count++;
        }
    }
    printf("Error count (C program) = %zu\n", error_count);

    //x86-64 version
    // initialize back out[i] to 0
    for (int i = 0; i < ARRAY_SIZE; i++) {
        out[i] = 0.0f;
    }

    // Flush out cache
    x86_kernel(ARRAY_SIZE, out, in);

    // time here
    start = clock();
    for (int j = 0; j < NO_OF_RUNS; j++) {
        x86_kernel(ARRAY_SIZE, out, in);
    }
    end = clock();
    time_taken = (((double)(end - start)) / NO_OF_RUNS) * 1e6 / CLOCKS_PER_SEC;
    printf("x86_64 function will take %f microseconds for array size %zu\n", time_taken, ARRAY_SIZE);

    // error checking
    error_count = 0;
    for (int i = 4; i + 3 < ARRAY_SIZE; i++) {
        float ans = in[i - 3] + in[i - 2] + in[i - 1] + in[i] + in[i + 1] + in[i + 2] + in[i + 3];
        if (i < 9) {
            printf("Execution #%i Result = %f\n", (i - 3), out[i]);
        }
        if (ans != out[i]) {
            error_count++;
        }
    }
    printf("Error count (x86_64 program) = %zu\n", error_count);

   //----- x86-64 SIMD YMM register -----
   // initialize back out[i] to 0
    for (int i = 0; i < ARRAY_SIZE; i++) {
        out[i] = 0.0f;
    }

    // Flush out cache
    SIMDprocess(ARRAY_SIZE, out, in);

    // time here
    start = clock();
    for (int j = 0; j < NO_OF_RUNS; j++) {
        SIMDprocess(ARRAY_SIZE, out, in);
    }
    end = clock();
    time_taken = (((double)(end - start)) / NO_OF_RUNS) * 1e6 / CLOCKS_PER_SEC;
    printf("x86 SIMD ISA function will take %f microseconds for array size %zu\n", time_taken, ARRAY_SIZE);

    // error checking
    error_count = 0;
    for (int i = 4; i + 3 < ARRAY_SIZE; i++) {
        float ans = in[i - 3] + in[i - 2] + in[i - 1] + in[i] + in[i + 1] + in[i + 2] + in[i + 3];
        if (i < 9) {
            printf("Execution #%i Result = %f\n", (i - 3), out[i]);
        }
        if (ans != out[i]) {
            error_count++;
        }
    }
    printf("Error count (SIMD program) = %zu\n", error_count);

    // free memory
    free(in);
    free(out);
    return 0;
}