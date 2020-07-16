#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <string.h>
#include <setjmp.h>

typedef struct _Function _Function;

#include "../symbol.h"
#include "../errors.h"
#if !defined(_WIN32) && !defined(_WIN64) && !defined(__CYGWIN__)
#include "../utilities/shell.h"
#endif
#include "../utilities/language.h"
#include "../utilities/helpers.h"
#include "../modules/module.h"

extern enum Phase phase;
enum BlockType { B_EXPRESSION, B_FUNCTION };

typedef struct _Function {
    char *name;
    int line_no;
    struct Symbol** parameters;
    unsigned short parameter_count;
    enum Type type;
    struct Symbol* symbol;
    struct _Function* previous;
    struct _Function* next;
    struct _Function* parent_scope;
    string_array decision_expressions;
    string_array decision_functions;
    char *decision_default;
    char *context;
    char *module_context;
    char *module;
    char *body;
} _Function;

extern _Function* function_cursor;
extern _Function* start_function;
extern _Function* end_function;
extern _Function* function_mode;
extern _Function* function_parameters_mode;
extern _Function* executed_function;
extern _Function* main_function;
extern _Function* scopeless;
extern _Function* scope_override;
extern _Function* decision_mode;
extern _Function* decision_expression_mode;
extern _Function* decision_function_mode;

extern bool decision_execution_mode;
extern Symbol* decision_symbol_chain;
extern char *decision_buffer;

extern string_array function_names_buffer;

extern unsigned short recursion_depth;
extern int reset_line_no_to;

extern jmp_buf InteractiveShellFunctionErrorAbsorber;
extern bool interactive_shell_function_error_absorbed;

void startFunction(char *name, enum Type type);
void endFunction();
void freeFunctionMode();
_Function* getFunction(char *name, char *module);
void printFunctionTable();
void callFunction(char *name, char *module);
void startFunctionParameters();
void addFunctionParameter(char *secondary_name, enum Type type);
void addSymbolToFunctionParameters(Symbol* symbol);
void addFunctionCallParameterBool(bool b);
void addFunctionCallParameterInt(long long i);
void addFunctionCallParameterFloat(long double f);
void addFunctionCallParameterString(char *s);
void addFunctionCallParameterSymbol(char *name);
void returnSymbol(char *name);
void printFunctionReturn(char *name, char *module, char *end, bool pretty, bool escaped);
void createCloneFromFunctionReturn(char *clone_name, enum Type type, char *name, char *module, enum Type extra_type);
void updateSymbolByClonningFunctionReturn(char *clone_name, char *name, char*module);
void updateComplexSymbolByClonningFunctionReturn(char *name, char*module);
void initMainFunction();
void initScopeless();
void freeFunction(_Function* function);
void freeAllFunctions();
bool block(enum BlockType type);
void addBooleanDecision();
void addDefaultDecision();
void executeDecision(_Function* function);
void addFunctionNameToFunctionNamesBuffer(char *name);
void freeFunctionNamesBuffer();
bool isInFunctionNamesBuffer(char *name);
bool isFunctionType(char *name, char *module, enum Type type);

#endif
