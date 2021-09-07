#include <x86intrin.h>
#include <stdint.h>

const int64_t all_ones = 0xFFFFFFFFFFFFFFFF;

void memcpy_128(void *dest, void *src, size_t n) {
	__m128i *d = dest, *s = src;
	size_t i;
	// For benchmark purposes, assume everything is aligned
	// We are passing memory allocated with posix_memalign
	n >>= 4;
	for (i = 0; i != n; i++) {
		_mm_store_si128(&d[i], _mm_load_si128(&s[i]));
	}
}

void memset_128(void *dest, __m128i c, size_t n) {
	__m128i *d = dest;
	size_t i;
	n >>= 4;
	for(i = 0; i != n; i++) {
		_mm_storeu_si128(&d[i], c);
	}
}

