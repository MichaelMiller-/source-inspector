#include "AppPath.h"

#include "utilityApp.h"

FilePath AppPath::s_sharedDataDirectoryPath(L"");
FilePath AppPath::s_cxxIndexerDirectoryPath(L"");

FilePath AppPath::getSharedDataDirectoryPath() { return s_sharedDataDirectoryPath; }

bool AppPath::setSharedDataDirectoryPath(const FilePath& path)
{
   if (!path.empty()) {
      s_sharedDataDirectoryPath = path;
      return true;
   }
   return false;
}

FilePath AppPath::getCxxIndexerFilePath()
{
   //! \todo hardcoded -> should be generated from cmake: $<TARGET_FILE:indexer>
   std::wstring cxxIndexerName(L"indexer");
   if (utility::getOsType() == OS_WINDOWS) {
      cxxIndexerName = L"indexer.exe";
   }

   if (!s_cxxIndexerDirectoryPath.empty()) {
      return s_cxxIndexerDirectoryPath.getConcatenated(cxxIndexerName);
   }
   return s_sharedDataDirectoryPath.getConcatenated(cxxIndexerName);
}

bool AppPath::setCxxIndexerDirectoryPath(const FilePath& path)
{
   if (!path.empty()) {
      s_cxxIndexerDirectoryPath = path;
      return true;
   }
   return false;
}
