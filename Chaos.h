#ifndef CHAOS_H
#define CHAOS_H

#include <stdbool.h>

#if defined(CHAOS_INTERPRETER)
#include "enums.h"
#include "utilities/language.h"
#else
#include "chaos/enums.h"
#include "chaos/language.h"
#endif

int defineFunction(char *name, enum Type type, char *params_name[], unsigned params_type[], unsigned short params_length);
bool getVariableBool(char *name);
long long getVariableInt(char *name);
long double getVariableFloat(char *name);
char* getVariableString(char *name);
unsigned long getListLength(char *name);
bool getListElementBool(char *name, long long i);
long long getListElementInt(char *name, long long i);
long double getListElementFloat(char *name, long long i);
char* getListElementString(char *name, long long i);
void copyListElement(char *name, long long i);
enum Type getListElementType(char *name, long long i);
unsigned long getDictLength(char *name);
char* getDictKeyByIndex(char *name, long long i);
bool getDictElementBool(char *name, char *key);
long long getDictElementInt(char *name, char *key);
long double getDictElementFloat(char *name, char *key);
char* getDictElementString(char *name, char *key);
void copyDictElement(char *name, char *key);
enum Type getDictElementType(char *name, char *key);
void returnVariableBool(bool b);
void returnVariableInt(long long i);
void returnVariableFloat(long double f);
void returnVariableString(char *s);
void createVariableBool(char *name, bool b);
void createVariableInt(char *name, long long i);
void createVariableFloat(char *name, long double f);
void createVariableString(char *name, char *s);
void startBuildingList();
void returnList(enum Type type);
void startBuildingDict();
void returnDict(enum Type type);
void returnComplex(enum Type type);

struct Kaos {
    int (*defineFunction)(char *name, enum Type type, char *params_name[], unsigned params_type[], unsigned short params_length);
    bool (*getVariableBool)(char *name);
    long long (*getVariableInt)(char *name);
    long double (*getVariableFloat)(char *name);
    char* (*getVariableString)(char *name);
    unsigned long (*getListLength)(char *name);
    bool (*getListElementBool)(char *name, long long i);
    long long (*getListElementInt)(char *name, long long i);
    long double (*getListElementFloat)(char *name, long long i);
    char* (*getListElementString)(char *name, long long i);
    void (*copyListElement)(char *name, long long i);
    enum Type (*getListElementType)(char *name, long long i);
    unsigned long (*getDictLength)(char *name);
    char* (*getDictKeyByIndex)(char *name, long long i);
    bool (*getDictElementBool)(char *name, char *key);
    long long (*getDictElementInt)(char *name, char *key);
    long double (*getDictElementFloat)(char *name, char *key);
    char* (*getDictElementString)(char *name, char *key);
    void (*copyDictElement)(char *name, char *key);
    enum Type (*getDictElementType)(char *name, char *key);
    void (*returnVariableBool)(bool b);
    void (*returnVariableInt)(long long i);
    void (*returnVariableFloat)(long double f);
    void (*returnVariableString)(char *s);
    void (*createVariableBool)(char *name, bool b);
    void (*createVariableInt)(char *name, long long i);
    void (*createVariableFloat)(char *name, long double f);
    void (*createVariableString)(char *name, char *s);
    void (*startBuildingList)();
    void (*returnList)(enum Type type);
    void (*startBuildingDict)();
    void (*returnDict)(enum Type type);
    void (*returnComplex)(enum Type type);
};

extern struct Kaos kaos;

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#define KAOS_EXPORT __declspec(dllexport)
#else
#define KAOS_EXPORT
#endif

#endif
