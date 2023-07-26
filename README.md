# simd-programming-project

The Number of Runs: 30 and the basis for error checking is the C version.

# C Program
- 2^20 Execution Time: 7,633.333333 microseconds (ms)
- 2^24 Execution Time: 133,733.333333 microseconds (ms)
- 2^30 Execution Time: 6,778,433.333333 microseconds (ms)

# x86-64 non SIMD Program
- 2^20 Execution Time: 4,800.000000 microseconds (ms)
- 2^24 Execution Time: 67,533.333333 microseconds (ms)
- 2^30 Execution Time: 4,255,833.333333 microseconds (ms)

# x86-64 SIMD Program
- 2^20 Execution Time: 566.666667 microseconds (ms)
- 2^24 Execution Time: 9,366.666667 microseconds (ms)
- 2^30 Execution Time: 763,200.000000 microseconds (ms)

# CUDA Program
- 2^20 Execution Time: 0.071024 microseconds (ms)
- Data Transfer Host to Device: 0.361693 microseconds (ms)
- Data Transfer Device to Host: 0.322045 microseconds (ms)
- Total Execution Time with Page Overhead: 0.754762 microseconds (ms)
- 2^24 Execution Time:  microseconds (ms)
- Data Transfer Host to Device:  microseconds (ms)
- Data Transfer Device to Host:  microseconds (ms)
- Total Execution Time with Page Overhead:  microseconds (ms)
- 2^30 Execution Time:  microseconds (ms)
- Data Transfer Host to Device:  microseconds (ms)
- Data Transfer Device to Host:  microseconds (ms)
- Total Execution Time with Page Overhead:  microseconds (ms)

# Analysis of Results

Out of all the 4 Versions, 

# Screenshots:

## C, x86-64 non SIMD and SIMD Result of Array Size 2 raise to 20
<picture>
  <img alt="Result of Array Size 2 raise to 20" src="size20.png">
</picture>

## C, x86-64 non SIMD and SIMD Result of Array Size 2 raise to 24
<picture>
  <img alt="Result of Array Size 2 raise to 24" src="size24.png">
</picture>

## C, x86-64 non SIMD and SIMD Result of Array Size 2 raise to 30
<picture>
  <img alt="Result of Array Size 2 raise to 30" src="size30.png">
</picture>

## CUDA Result of Array Size 2 raise to 20
<picture>
  <img alt="Result of Array Size 2 raise to 20" src="CUDASize20.png">
</picture>

## CUDA Result of Array Size 2 raise to 24
<picture>
  <img alt="Result of Array Size 2 raise to 24" src="CUDASize24.png">
</picture>

## CUDA Result of Array Size 2 raise to 30
<picture>
  <img alt="Result of Array Size 2 raise to 30" src="CUDASize30.png">
</picture>
