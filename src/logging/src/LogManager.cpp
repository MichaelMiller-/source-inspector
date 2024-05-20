#include "LogManager.h"

#include <algorithm>
#include <codecvt>
#include <locale>

#include "logging.h"

using convert_t = std::codecvt_utf8<wchar_t>;
static std::wstring_convert<convert_t, wchar_t> converter;

std::shared_ptr<LogManager> LogManager::getInstance()
{
   if (s_instance.use_count() == 0) {
      s_instance = std::shared_ptr<LogManager>(new LogManager());
   }
   return s_instance;
}

void LogManager::destroyInstance() { s_instance.reset(); }

void LogManager::setLoggingEnabled(bool enabled)
{
   if (m_loggingEnabled != enabled) {
      m_loggingEnabled = enabled;

      //! \todo: enable or delete
#if 0
		if (enabled)
		{
			LOG_INFO(
				std::string("Enabled logging for Sourcetrail ") +
				(utility::getApplicationArchitectureType() == APPLICATION_ARCHITECTURE_X86_32
					 ? "32"
					 : "64") +
				" bit, " + "version " + Version::getApplicationVersion().toDisplayString());
			MessageStatus(L"Enabled console and file logging.").dispatch();
		}
		else
		{
			LOG_INFO("Disabled logging");
			MessageStatus(L"Disabled console and file logging.").dispatch();
		}
#endif
   }
}

bool LogManager::getLoggingEnabled() const { return m_loggingEnabled; }

void LogManager::addLogger(std::shared_ptr<Logger> logger) { m_logManagerImplementation.addLogger(logger); }

Logger* LogManager::getLoggerByType(const std::string& type)
{
   return m_logManagerImplementation.getLoggerByType(type);
}

void LogManager::logInfo(const std::string& message, const std::string& file, const std::string& function,
                         const unsigned int line)
{
   if (m_loggingEnabled) {
      m_logManagerImplementation.logInfo(converter.from_bytes(message), file, function, line);
   }
}
void LogManager::logInfo(const std::wstring& message, const std::string& file, const std::string& function,
                         const unsigned int line)
{
   if (m_loggingEnabled) {
      m_logManagerImplementation.logInfo(message, file, function, line);
   }
}

void LogManager::logWarning(const std::string& message, const std::string& file, const std::string& function,
                            const unsigned int line)
{
   if (m_loggingEnabled) {
      m_logManagerImplementation.logWarning(converter.from_bytes(message), file, function, line);
   }
}
void LogManager::logWarning(const std::wstring& message, const std::string& file, const std::string& function,
                            const unsigned int line)
{
   if (m_loggingEnabled) {
      m_logManagerImplementation.logWarning(message, file, function, line);
   }
}

void LogManager::logError(const std::string& message, const std::string& file, const std::string& function,
                          const unsigned int line)
{
   if (m_loggingEnabled) {
      m_logManagerImplementation.logError(converter.from_bytes(message), file, function, line);
   }
}
void LogManager::logError(const std::wstring& message, const std::string& file, const std::string& function,
                          const unsigned int line)
{
   if (m_loggingEnabled) {
      m_logManagerImplementation.logError(message, file, function, line);
   }
}

std::shared_ptr<LogManager> LogManager::s_instance;
