/**
 * Solution: Multiply two matrices
 */
#include <cmath>
#include <thread>

/* sequential implementation of matrix multiply */
void sequential_matrix_multiply(long **A, size_t num_rows_a, size_t num_cols_a,
                                long **B, size_t num_rows_b, size_t num_cols_b,
                                long **C) {
  for (size_t i = 0; i < num_rows_a; i++) {
    for (size_t j = 0; j < num_cols_b; j++) {
      C[i][j] = 0; // initialize result cell to zero
      for (size_t k = 0; k < num_cols_a; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

/* prototype of helper function for parallel_matrix_multiply */
void parallel_worker(long **, size_t, size_t, long **, size_t, size_t, long **,
                     size_t, size_t);

/* parallel implementation of matrix multiply */
void parallel_matrix_multiply(long **A, size_t num_rows_a, size_t num_cols_a,
                              long **B, size_t num_rows_b, size_t num_cols_b,
                              long **C) {
  size_t num_workers = std::thread::hardware_concurrency();
  size_t chunk_size = ceil((float)num_rows_a / num_workers);

  std::thread workers[num_workers];
  for (size_t i = 0; i < num_workers; i++) {
    size_t start_row_c = std::min(i * chunk_size, num_rows_a);
    size_t end_row_c = std::min((i + 1) * chunk_size, num_rows_a);
    workers[i] = std::thread(parallel_worker, A, num_rows_a, num_cols_a, B,
                             num_rows_b, num_cols_b, C, start_row_c, end_row_c);
  }
  for (auto &w : workers) {
    w.join();
  }
}

/* helper function for parallel_matrix_multiply */
void parallel_worker(long **A, size_t num_rows_a, size_t num_cols_a, long **B,
                     size_t num_rows_b, size_t num_cols_b, long **C,
                     size_t start_row_c, size_t end_row_c) {
  for (size_t i = start_row_c; i < end_row_c; i++) { // subset of rows in A
    for (size_t j = 0; j < num_cols_b; j++) {
      C[i][j] = 0; // initialize result cell to zero
      for (size_t k = 0; k < num_cols_a; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main() {
  const int NUM_EVAL_RUNS = 3;
  const size_t NUM_ROWS_A = 5000;
  const size_t NUM_COLS_A = 5000;
  const size_t NUM_ROWS_B = NUM_COLS_A;
  const size_t NUM_COLS_B = 5000;

  // intialize A and B with values in range 1 to 100
  long **A = (long **)malloc(NUM_ROWS_A * sizeof(long *));
  long **B = (long **)malloc(NUM_ROWS_B * sizeof(long *));
  if ((A == NULL) || (A == NULL)) {
    exit(2);
  }
  for (size_t i = 0; i < NUM_ROWS_A; i++) {
    A[i] = (long *)malloc(NUM_COLS_A * sizeof(long));
    B[i] = (long *)malloc(NUM_COLS_B * sizeof(long));
    if ((A[i] == NULL) || (A[i] == NULL)) {
      exit(2);
    }
    for (size_t j = 0; j < NUM_COLS_A; j++) {
      A[i][j] = rand() % 100 + 1;
      B[i][j] = rand() % 100 + 1;
    }
  }

  // allocate arrays for sequential and parallel results
  long **sequential_result = (long **)malloc(NUM_ROWS_A * sizeof(long *));
  long **parallel_result = (long **)malloc(NUM_ROWS_A * sizeof(long *));
  if ((sequential_result == NULL) || (parallel_result == NULL)) {
    exit(2);
  }
  for (size_t i = 0; i < NUM_ROWS_A; i++) {
    sequential_result[i] = (long *)malloc(NUM_COLS_B * sizeof(long));
    parallel_result[i] = (long *)malloc(NUM_COLS_B * sizeof(long));
    if ((sequential_result[i] == NULL) || (parallel_result[i] == NULL)) {
      exit(2);
    }
  }

  printf("Evaluating Sequential Implementation...\n");
  std::chrono::duration<double> sequential_time(0);
  sequential_matrix_multiply(A, NUM_COLS_A, NUM_ROWS_A, B, NUM_COLS_B,
                             NUM_ROWS_B, sequential_result); // "warm up"
  for (int i = 0; i < NUM_EVAL_RUNS; i++) {
    printf(" sequential counter: %d \n", i);
    auto startTime = std::chrono::high_resolution_clock::now();
    sequential_matrix_multiply(A, NUM_COLS_A, NUM_ROWS_A, B, NUM_COLS_B,
                               NUM_ROWS_B, sequential_result);
    sequential_time += std::chrono::high_resolution_clock::now() - startTime;
  }
  sequential_time /= NUM_EVAL_RUNS;

  printf("Evaluating Parallel Implementation...\n");
  std::chrono::duration<double> parallel_time(0);
  parallel_matrix_multiply(A, NUM_COLS_A, NUM_ROWS_A, B, NUM_COLS_B, NUM_ROWS_B,
                           parallel_result); // "warm up"
  for (int i = 0; i < NUM_EVAL_RUNS; i++) {
    printf(" parallel counter: %d \n", i);
    auto startTime = std::chrono::high_resolution_clock::now();
    parallel_matrix_multiply(A, NUM_COLS_A, NUM_ROWS_A, B, NUM_COLS_B,
                             NUM_ROWS_B, parallel_result);
    parallel_time += std::chrono::high_resolution_clock::now() - startTime;
  }
  parallel_time /= NUM_EVAL_RUNS;

  // verify sequential and parallel results
  for (size_t i = 0; i < NUM_ROWS_A; i++) {
    for (size_t j = 0; j < NUM_COLS_B; j++) {
      if (sequential_result[i][j] != parallel_result[i][j]) {
        printf("ERROR: Result mismatch at row %ld, col %ld!\n", i, j);
      }
    }
  }
  printf("Average Sequential Time: %.2f ms\n", sequential_time.count() * 1000);
  printf("  Average Parallel Time: %.2f ms\n", parallel_time.count() * 1000);
  printf("Speedup: %.2f\n", sequential_time / parallel_time);
  printf("Efficiency %.2f%%\n", 100 * (sequential_time / parallel_time) /
                                    std::thread::hardware_concurrency());
}