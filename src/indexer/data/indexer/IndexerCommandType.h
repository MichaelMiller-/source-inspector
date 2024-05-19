#ifndef INDEXER_COMMAND_TYPE_H
#define INDEXER_COMMAND_TYPE_H

#include <string>

enum IndexerCommandType {
   INDEXER_COMMAND_UNKNOWN,
   INDEXER_COMMAND_CXX,
#if BUILD_JAVA_LANGUAGE_PACKAGE
   INDEXER_COMMAND_JAVA,
#endif // BUILD_JAVA_LANGUAGE_PACKAGE
#if BUILD_PYTHON_LANGUAGE_PACKAGE
   INDEXER_COMMAND_PYTHON,
#endif // BUILD_PYTHON_LANGUAGE_PACKAGE
   INDEXER_COMMAND_CUSTOM
};

std::string indexerCommandTypeToString(IndexerCommandType type);

#endif // INDEXER_COMMAND_TYPE_H
