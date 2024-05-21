#ifndef LANGUAGE_TYPE_H
#define LANGUAGE_TYPE_H

#include <string>

#include "SourceGroupType.h"

enum LanguageType {
   LANGUAGE_CPP,
   LANGUAGE_C,
#if BUILD_JAVA_LANGUAGE_PACKAGE
   LANGUAGE_JAVA,
#endif // BUILD_JAVA_LANGUAGE_PACKAGE
#if BUILD_PYTHON_LANGUAGE_PACKAGE
   LANGUAGE_PYTHON,
#endif // BUILD_PYTHON_LANGUAGE_PACKAGE
   LANGUAGE_CUSTOM,
   LANGUAGE_UNKNOWN
};

std::string languageTypeToString(LanguageType t);

LanguageType getLanguageTypeForSourceGroupType(SourceGroupType t);

#endif // LANGUAGE_TYPE_H
