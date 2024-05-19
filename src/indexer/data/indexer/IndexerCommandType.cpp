#include "IndexerCommandType.h"

std::string indexerCommandTypeToString(IndexerCommandType type)
{
   switch (type) {
   case INDEXER_COMMAND_CXX:
      return "indexer_command_cxx";
#if BUILD_JAVA_LANGUAGE_PACKAGE
   case INDEXER_COMMAND_JAVA:
      return "indexer_command_java";
#endif // BUILD_JAVA_LANGUAGE_PACKAGE
#if BUILD_PYTHON_LANGUAGE_PACKAGE
   case INDEXER_COMMAND_PYTHON:
      return "indexer_command_python";
#endif // BUILD_PYTHON_LANGUAGE_PACKAGE
   case INDEXER_COMMAND_CUSTOM:
      return "indexer_command_custom";
   default:
      break;
   }
   return "indexer_command_unknown";
}
