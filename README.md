## Self-study project: Implement memset & memcpy using SIMD intrinsics

This was a learning project I did for computer organization course.

It compares naive implementation of `memset` and `memcpy` using naive for loop, and simplest SIMD implementation using 128 bit SSE / 256 bit AVX instructions.

The purpose of this was learning about SIMD intrinsics.

SelfStudy_SSE folder contains an implementation using SSE2. SelfStudy_AVX folder contains an updated version using AVX (256 bit).

AVX version has to be compiled with -mavx option.

`main` program runs the comparison and prints the time it took for each (naive byte-by-byte, naive word-by-word vs SIMD) approach. time is measured in units returned by the unix clock() function, which is generally in microseconds.

Some screenshots are in Screenshots/ folder.

