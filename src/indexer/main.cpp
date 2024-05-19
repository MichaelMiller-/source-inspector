#include "AppPath.h"
#include "ApplicationSettings.h"
#include "InterprocessIndexer.h"
#include "LanguagePackageCxx.h"
#include "LanguagePackageManager.h"
#include "UserPaths.h"
#include "logging/FileLogger.h"
#include "logging/LogManager.h"
#include "logging/logging.h"

#if BUILD_JAVA_LANGUAGE_PACKAGE
#include "LanguagePackageJava.h"
#endif // BUILD_JAVA_LANGUAGE_PACKAGE

void setupLogging(const std::filesystem::path& logFilePath)
{
   auto logManager = LogManager::getInstance().get();

   // std::shared_ptr<ConsoleLogger> consoleLogger = std::make_shared<ConsoleLogger>();
   // // consoleLogger->setLogLevel(Logger::LOG_WARNINGS | Logger::LOG_ERRORS);
   // consoleLogger->setLogLevel(Logger::LOG_ALL);
   // logManager->addLogger(consoleLogger);

   auto fileLogger = std::make_shared<FileLogger>();
   fileLogger->setLogFilePath(logFilePath);
   fileLogger->setLogLevel(Logger::LOG_ALL);
   logManager->addLogger(fileLogger);
}

void suppressCrashMessage()
{
#ifdef _WIN32
   SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
#endif // _WIN32
}

//! \todo: why is Qt here when this is a console application
int main(int argc, char* argv[])
{
   int processId = -1;
   std::string instanceUuid;
   std::string appPath;
   std::string userDataPath;
   std::string logFilePath;

   //! \todo: replace with docopt
   if (argc >= 2) {
      processId = std::stoi(argv[1]);
   }
   if (argc >= 3) {
      instanceUuid = argv[2];
   }
   if (argc >= 4) {
      appPath = argv[3];
   }
   if (argc >= 5) {
      userDataPath = argv[4];
   }
   if (argc >= 6) { // optional
      logFilePath = argv[5];
   }

   LOG_INFO("Indexer arguments: ");
   for (int i = 0; i < argc; ++i) {
      LOG_INFO(argv[i]);
   }

   AppPath::setSharedDataDirectoryPath(FilePath(appPath));
   UserPaths::setUserDataDirectoryPath(FilePath(userDataPath));

   if (!logFilePath.empty()) {
      setupLogging(logFilePath);
   }

   suppressCrashMessage();

   auto appSettings = ApplicationSettings::getInstance().get();
   appSettings->load(FilePath(UserPaths::getAppSettingsFilePath()));
   LogManager::getInstance()->setLoggingEnabled(appSettings->getLoggingEnabled());

   LOG_INFO(L"sharedDataPath: " + AppPath::getSharedDataDirectoryPath().wstr());
   LOG_INFO(L"userDataPath: " + UserPaths::getUserDataDirectoryPath().wstr());

   LanguagePackageManager::getInstance()->addPackage(std::make_shared<LanguagePackageCxx>());

#if BUILD_JAVA_LANGUAGE_PACKAGE
   LanguagePackageManager::getInstance()->addPackage(std::make_shared<LanguagePackageJava>());
#endif // BUILD_JAVA_LANGUAGE_PACKAGE

   InterprocessIndexer indexer(instanceUuid, processId);
   indexer.work();

   return 0;
}
