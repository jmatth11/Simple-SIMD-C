#ifndef __SSE2__
#error "platform does not support SIMD instructions."
#endif

#include <stdio.h>
#include <stdint.h>

// include simd header
#include <immintrin.h>

int main() {
    // define some values.
    int a1 = 1, a2 = 2, a3 = 4, a4 = 8;
    int b1 = 3, b2 = 5, b3 = 7, b4 = 15;

    // load our numbers into the registers
    // we define them in reverse order because they are loaded in reverse order.
    __m128i data1 = _mm_set_epi32(a4, a3, a2, a1);
    __m128i data2 = _mm_set_epi32(b4, b3, b2, b1);

    // Perform bitwise XOR
    __m128i result = _mm_xor_si128(data1, data2);

    // create an out buffer. it's stored as 4 32bit ints.
    // alignment is important here.
    u_int32_t out[4];
    // extract results by storingit into our out buffer with the same alignment.
    _mm_storeu_si128((__m128i*)out, result);

    // Print the results
    printf("Original values: (%d, %d, %d, %d)\n", a1, a2, a3, a4);
    printf("OR'ed with: (%d, %d, %d, %d)\n", b1, b2, b3, b4);
    printf("manual OR'ed: (%d, %d, %d, %d)\n", a1 ^ b1, a2 ^ b2, a3 ^ b3, a4 ^ b4);
    printf("SIMD Result: (%d, %d, %d, %d)\n", out[0], out[1], out[2], out[3]);

    return 0;
}
