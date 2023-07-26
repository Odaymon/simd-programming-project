# simd-programming-project

The Number of Runs: 30 and the basis for error checking is the C version.

# C Program
- 2^20 Execution Time: 7,633.33 microseconds (ms)
- 2^24 Execution Time: 133,733.33 microseconds (ms)
- 2^30 Execution Time: 6,778,433.33 microseconds (ms)

# x86-64 non SIMD Program
- 2^20 Execution Time: 4,800.00 microseconds (ms)
- 2^24 Execution Time: 67,533.33 microseconds (ms)
- 2^30 Execution Time: 4,255,833.33 microseconds (ms)

# x86-64 SIMD Program
- 2^20 Execution Time: 566.66 microseconds (ms)
- 2^24 Execution Time: 9,366.66 microseconds (ms)
- 2^30 Execution Time: 763,200.00 microseconds (ms)

# CUDA Program
- 2^20 Execution Time: 0.071024 microseconds (ms)
- Data Transfer Host to Device: 0.361693 microseconds (ms)
- Data Transfer Device to Host: 0.322045 microseconds (ms)
- Total Execution Time with Page Overhead: 0.754762 microseconds (ms)
- =====NEXT=====
- 2^24 Execution Time: 1.0628 microseconds (ms)
- Data Transfer Host to Device: 5.564853 microseconds (ms)
- Data Transfer Device to Host: 5.153755 microseconds (ms)
- Total Execution Time with Page Overhead: 11.781408 microseconds (ms)
- =====NEXT=====
- 2^30 Execution Time: 41.282 microseconds (ms)
- Data Transfer Host to Device: 357.2177 microseconds (ms)
- Data Transfer Device to Host: 322.7327 microseconds (ms)
- Total Execution Time with Page Overhead: 721.2324 microseconds (ms)

# Analysis of Results

For the analysis of the performance of each version, I've used the formula below to compare each programs performance.
<picture>
  <img alt="Formula: Percentage Increase " src="Formula.png">
</picture>

At the initial look of the execution time, the CUDA version performed the best in majority of the input size except for the input size is 2^24, where the SIMD version performed better than the CUDA version. Although both SIMD and CUDA is faster than C and non SIMD x86-64 because SIMD and CUDA both utilize parallel processing. Where CUDA can process up to 1024 at a time while SIMD can process 32 bits at a time or 8 floating points.

Now for the analysis of the results using the formula given above. Below are the results and analysis.
### 2^20
## C vs non SIMD x86-64

## C vs SIMD x86-64
## C vs CUDA

### 2^24

### 2^30

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
