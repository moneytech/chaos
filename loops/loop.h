#ifndef LOOP_H
#define LOOP_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <setjmp.h>

enum LoopType { TIMESDO, FOREACH, FOREACH_DICT };

typedef struct {
    char *name;
    char *key;
    char *value;
} LoopElement;

typedef struct {
    enum LoopType type;
    unsigned long long iter;
    bool is_infinite;
    unsigned nested_counter;
    char *list;
    LoopElement element;
    char *body;
} Loop;

extern Loop* loop_mode;
extern bool loop_execution_mode;

extern jmp_buf InteractiveShellLoopErrorAbsorber;
extern bool interactive_shell_loop_error_absorbed;

void endLoop();

#include "times_do.h"
#include "foreach.h"

#endif
