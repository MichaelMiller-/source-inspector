#include "LanguageType.h"

std::string languageTypeToString(LanguageType t)
{
   switch (t) {
   case LANGUAGE_C:
      return "C";
   case LANGUAGE_CPP:
      return "C++";
#if BUILD_JAVA_LANGUAGE_PACKAGE
   case LANGUAGE_JAVA:
      return "Java";
#endif // BUILD_JAVA_LANGUAGE_PACKAGE
#if BUILD_PYTHON_LANGUAGE_PACKAGE
   case LANGUAGE_PYTHON:
      return "Python";
#endif // BUILD_PYTHON_LANGUAGE_PACKAGE
   case LANGUAGE_CUSTOM:
      return "Custom";
   case LANGUAGE_UNKNOWN:
      break;
   }
   return "unknown";
}

LanguageType getLanguageTypeForSourceGroupType(SourceGroupType t)
{
   switch (t) {
   case SOURCE_GROUP_C_EMPTY:
      return LANGUAGE_C;
   case SOURCE_GROUP_CPP_EMPTY:
      return LANGUAGE_CPP;
   case SOURCE_GROUP_CXX_CDB:
      return LANGUAGE_CPP;
   case SOURCE_GROUP_CXX_CODEBLOCKS:
      return LANGUAGE_CPP;
   case SOURCE_GROUP_CXX_VS:
      return LANGUAGE_CPP;
#if BUILD_JAVA_LANGUAGE_PACKAGE
   case SOURCE_GROUP_JAVA_EMPTY:
      return LANGUAGE_JAVA;
   case SOURCE_GROUP_JAVA_MAVEN:
      return LANGUAGE_JAVA;
   case SOURCE_GROUP_JAVA_GRADLE:
      return LANGUAGE_JAVA;
#endif // BUILD_JAVA_LANGUAGE_PACKAGE
#if BUILD_PYTHON_LANGUAGE_PACKAGE
   case SOURCE_GROUP_PYTHON_EMPTY:
      return LANGUAGE_PYTHON;
#endif // BUILD_PYTHON_LANGUAGE_PACKAGE
   case SOURCE_GROUP_CUSTOM_COMMAND:
      return LANGUAGE_CUSTOM;
   default:
      break;
   }

   return LANGUAGE_UNKNOWN;
}
