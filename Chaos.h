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

typedef struct KaosValue {
    bool b;
    long long i;
    char *s;
    long double f;
} KaosValue;

int defineFunction(
    char *name,
    enum Type type,
    enum Type secondary_type,
    char *params_name[],
    unsigned params_type[],
    unsigned params_secondary_type[],
    unsigned short params_length,
    KaosValue optional_params[],
    unsigned short optional_params_length
);
bool getVariableBool(char *name);
long long getVariableInt(char *name);
long double getVariableFloat(char *name);
char* getVariableString(char *name);
bool getVariableBoolByTypeCasting(char *name);
long long getVariableIntByTypeCasting(char *name);
long double getVariableFloatByTypeCasting(char *name);
char* getVariableStringByTypeCasting(char *name);
unsigned long getListLength(char *name);
bool getListElementBool(char *name, long long i);
long long getListElementInt(char *name, long long i);
long double getListElementFloat(char *name, long long i);
char* getListElementString(char *name, long long i);
bool getListElementBoolByTypeCasting(char *name, long long i);
long long getListElementIntByTypeCasting(char *name, long long i);
long double getListElementFloatByTypeCasting(char *name, long long i);
char* getListElementStringByTypeCasting(char *name, long long i);
void copyListElement(char *name, long long i);
enum Type getListElementType(char *name, long long i);
enum ValueType getListElementValueType(char *name, long long i);
unsigned long getDictLength(char *name);
char* getDictKeyByIndex(char *name, long long i);
bool getDictElementBool(char *name, char *key);
long long getDictElementInt(char *name, char *key);
long double getDictElementFloat(char *name, char *key);
char* getDictElementString(char *name, char *key);
bool getDictElementBoolByTypeCasting(char *name, char *key);
long long getDictElementIntByTypeCasting(char *name, char *key);
long double getDictElementFloatByTypeCasting(char *name, char *key);
char* getDictElementStringByTypeCasting(char *name, char *key);
void copyDictElement(char *name, char *key);
enum Type getDictElementType(char *name, char *key);
enum ValueType getDictElementValueType(char *name, char *key);
char* dumpVariableToString(char *name, bool pretty, bool escaped, bool double_quotes);
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
void finishList(enum Type type);
void finishDict(enum Type type);
void finishComplex(enum Type type);
enum Type getListType(char *name);
enum Type getDictType(char *name);
enum ValueType getValueType(char *name);
enum Role getRole(char *name);
void raiseError(char *msg);
void parseJson(char *json);

struct Kaos {
    int (*defineFunction)(
        char *name,
        enum Type type,
        enum Type secondary_type,
        char *params_name[],
        unsigned params_type[],
        unsigned params_secondary_type[],
        unsigned short params_length,
        KaosValue optional_params[],
        unsigned short optional_params_length
    );
    bool (*getVariableBool)(char *name);
    long long (*getVariableInt)(char *name);
    long double (*getVariableFloat)(char *name);
    char* (*getVariableString)(char *name);
    bool (*getVariableBoolByTypeCasting)(char *name);
    long long (*getVariableIntByTypeCasting)(char *name);
    long double (*getVariableFloatByTypeCasting)(char *name);
    char* (*getVariableStringByTypeCasting)(char *name);
    unsigned long (*getListLength)(char *name);
    bool (*getListElementBool)(char *name, long long i);
    long long (*getListElementInt)(char *name, long long i);
    long double (*getListElementFloat)(char *name, long long i);
    char* (*getListElementString)(char *name, long long i);
    bool (*getListElementBoolByTypeCasting)(char *name, long long i);
    long long (*getListElementIntByTypeCasting)(char *name, long long i);
    long double (*getListElementFloatByTypeCasting)(char *name, long long i);
    char* (*getListElementStringByTypeCasting)(char *name, long long i);
    void (*copyListElement)(char *name, long long i);
    enum Type (*getListElementType)(char *name, long long i);
    enum ValueType (*getListElementValueType)(char *name, long long i);
    unsigned long (*getDictLength)(char *name);
    char* (*getDictKeyByIndex)(char *name, long long i);
    bool (*getDictElementBool)(char *name, char *key);
    long long (*getDictElementInt)(char *name, char *key);
    long double (*getDictElementFloat)(char *name, char *key);
    char* (*getDictElementString)(char *name, char *key);
    bool (*getDictElementBoolByTypeCasting)(char *name, char *key);
    long long (*getDictElementIntByTypeCasting)(char *name, char *key);
    long double (*getDictElementFloatByTypeCasting)(char *name, char *key);
    char* (*getDictElementStringByTypeCasting)(char *name, char *key);
    void (*copyDictElement)(char *name, char *key);
    enum Type (*getDictElementType)(char *name, char *key);
    enum ValueType (*getDictElementValueType)(char *name, char *key);
    char* (*dumpVariableToString)(char *name, bool pretty, bool escaped, bool double_quotes);
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
    void (*finishList)(enum Type type);
    void (*finishDict)(enum Type type);
    void (*finishComplex)(enum Type type);
    enum Type (*getListType)(char *name);
    enum Type (*getDictType)(char *name);
    enum ValueType (*getValueType)(char *name);
    enum Role (*getRole)(char *name);
    void (*raiseError)(char *msg);
    void (*parseJson)(char *json);
};

struct Kaos kaos;

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#define KAOS_EXPORT __declspec(dllexport)
#else
#define KAOS_EXPORT
#endif

#endif
