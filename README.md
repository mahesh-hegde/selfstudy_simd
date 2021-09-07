## Self-study project: Implement memset & memcpy using SIMD intrinsics

This was a learning project I did for computer organization course.

It compares naive implementation of `memset` and `memcpy` using naive for loop, and simplest SIMD implementation using 128 bit SSE / 256 bit AVX instructions.

The purpose of this was learning about SIMD intrinsics.

SelfStudy_SSE folder contains an implementation using SSE2. SelfStudy_AVX folder contains an updated version using AVX (256 bit).

AVX version has to be compiled with -mavx option.

`main` program runs the comparison and prints the time it took for each (naive byte-by-byte, naive word-by-word vs SIMD) approach. time is measured in units returned by the unix clock() function, which is generally in microseconds.

main program takes 2 arguments. Buffer size is calculated as 2^argv[2], and both functions are run argv[1] times. argv[2] should be in range 4..31

eg:
	./main 10 28
	runs the test 10 times on a buffer with size 2 ^ 28 bytes.

With very larger sizes there will be overhead of virtual memory and it may add to noice. With very small sizes there will be other overheads which are proportionally larger than time taken for copy operation. argv[2] around 20 .. 28 is ideal.

It shows that AVX or SSE is faster than word-wise or byte-wise copying. Obviously we can't expect full 4 times speedup because AVX only speeds up part of the loop. But a speedup arounda factor of 2 is commonly observed with 256-bit AVX.

Some screenshots are in Screenshots/ folder.

