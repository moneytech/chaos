#include "extension.h"
#include "../Chaos.h"

struct Kaos kaos = {
    .defineFunction = defineFunction,
    .getVariableBool = getVariableBool,
    .getVariableInt = getVariableInt,
    .getVariableFloat = getVariableFloat,
    .getVariableString = getVariableString,
    .getListLength = getListLength,
    .getListElementBool = getListElementBool,
    .getListElementInt = getListElementInt,
    .getListElementFloat = getListElementFloat,
    .getListElementString = getListElementString,
    .copyListElement = copyListElement,
    .getListElementType = getListElementType,
    .getDictLength = getDictLength,
    .getDictKeyByIndex = getDictKeyByIndex,
    .getDictElementBool = getDictElementBool,
    .getDictElementInt = getDictElementInt,
    .getDictElementFloat = getDictElementFloat,
    .getDictElementString = getDictElementString,
    .copyDictElement = copyDictElement,
    .getDictElementType = getDictElementType,
    .returnVariableBool = returnVariableBool,
    .returnVariableInt = returnVariableInt,
    .returnVariableFloat = returnVariableFloat,
    .returnVariableString = returnVariableString,
    .createVariableBool = createVariableBool,
    .createVariableInt = createVariableInt,
    .createVariableFloat = createVariableFloat,
    .createVariableString = createVariableString,
    .startBuildingList = startBuildingList,
    .returnList = returnList,
    .startBuildingDict = startBuildingDict,
    .returnDict = returnDict,
    .returnComplex = returnComplex
};

void callRegisterInDynamicLibrary(char* dynamic_library_path) {
    dynamic_library dylib = getFunctionFromDynamicLibrary(dynamic_library_path, __KAOS_EXTENSION_REGISTER_FUNCTION__);
    dylib.func(kaos);
    if (is_interactive) {
        phase = PROGRAM;
    }
}

void callFunctionFromDynamicLibrary(_Function* function) {
    char* function_name = "";
    function_name = strcat_ext(function_name, __KAOS_EXTENSION_FUNCTION_PREFIX__);
    function_name = strcat_ext(function_name, function->name);
    dynamic_library dylib = getFunctionFromDynamicLibrary(function->module_context, function_name);
    dylib.func();
    free(function_name);
}

dynamic_library getFunctionFromDynamicLibrary(char* dynamic_library_path, char* function_name) {
    dynamic_library dylib;

    dylib.handle = OPENLIB(dynamic_library_path);

    if (dylib.handle == NULL) {
        #if !defined(_WIN32) && !defined(_WIN64) && !defined(__CYGWIN__)
        fprintf(stderr, "Unable to open lib: %s\n", dlerror());
        #endif
    }
    dylib.func = LIBFUNC(dylib.handle, function_name);

    if (dylib.func == NULL) {
        fprintf(stderr, "Unable to get symbol\n");
    }

    return dylib;
}

void returnVariable(Symbol* symbol) {
    scope_override = executed_function->parent_scope;
    executed_function->symbol = createCloneFromSymbol(
        NULL,
        symbol->type,
        symbol,
        symbol->secondary_type
    );
    decision_symbol_chain = createCloneFromSymbol(
        NULL,
        symbol->type,
        symbol,
        symbol->secondary_type
    );
    scope_override = NULL;
    removeSymbol(symbol);
}
