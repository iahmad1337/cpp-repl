#pragma once

#include <sstream>

#define RESULT_SIZE 256
#define MAX_ARGS 32


struct call_info {
  char* func_name;
  int argnum;
  char* args[MAX_ARGS];
  char result[RESULT_SIZE];
  bool is_error;
};

#define SUCCESS 0
#define BAD_FUNC -1
#define BAD_ARG -2
#define BAD_FUNC_EVAL -3
#define CRITICAL_ERROR -4


// Why `extern "C"`? Check page 88 of AC
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// return SUCCESS on successful call
// return BAD_FUNC on non-existent function
// return BAD_ARG on argument mismatch
// return BAD_FUNC_EVAL on exceptions during function evaluation
// return CRITICAL_ERROR on exceptions in the library code
int make_call(call_info*);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
