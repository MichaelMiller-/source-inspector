#include "ConsoleLogger.h"

#include <codecvt>
#include <iostream>
#include <locale>

ConsoleLogger::ConsoleLogger() : Logger("ConsoleLogger") {}

void ConsoleLogger::logInfo(const LogMessage& message) { logMessage("INFO", message); }

void ConsoleLogger::logWarning(const LogMessage& message) { logMessage("WARNING", message); }

void ConsoleLogger::logError(const LogMessage& message) { logMessage("ERROR", message); }

void ConsoleLogger::logMessage(const std::string& type, const LogMessage& message)
{
   using convert_t = std::codecvt_utf8<wchar_t>;
   static std::wstring_convert<convert_t, wchar_t> converter;

   std::cout << message.getTimeString("%H:%M:%S") << " | ";

   if (!message.filePath.empty()) {
      std::cout << message.getFileName() << ':' << message.line << ' ' << message.functionName << "() | ";
   }

   std::cout << type << ": " << converter.to_bytes(message.message) << std::endl;
}
