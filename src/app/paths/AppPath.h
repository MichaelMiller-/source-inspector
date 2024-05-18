#ifndef APP_PATH_H
#define APP_PATH_H

#include "FilePath.h"

class AppPath
{
  //! \todo replace with std::filesystem::path
  static FilePath s_sharedDataDirectoryPath;
  static FilePath s_cxxIndexerDirectoryPath;

public:
  static FilePath getSharedDataDirectoryPath();
  static bool setSharedDataDirectoryPath(const FilePath& path);

  static FilePath getCxxIndexerFilePath();
  static bool setCxxIndexerDirectoryPath(const FilePath& path);
};

#endif // APP_PATH_H
