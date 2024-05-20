#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <codecvt>
#include <functional>
#include <locale>
#include <memory>
#include <source_location>
#include <format>

#include "LogManagerImplementation.h"
#include "Logger.h"

namespace detail
{
   template <typename T>
   struct to_wstring_impl;

   template <>
   struct to_wstring_impl<char>
   {
      static auto operator()(auto const& input)
      {
         using convert_t = std::codecvt_utf8<wchar_t>;
         static std::wstring_convert<convert_t, wchar_t> converter;
         return converter.from_bytes(input);
      }
   };

   template <>
   struct to_wstring_impl<wchar_t>
   {
      static auto operator()(auto const& input) noexcept { return input; }
   };

   template <typename CharT>
   auto to_wstring(std::basic_string<CharT> const& input) noexcept(
      noexcept(std::is_nothrow_invocable_v<to_wstring_impl<CharT>, std::basic_string<CharT>>))
   {
      return std::invoke(to_wstring_impl<CharT>{}, input);
   }
} // namespace detail

class LogManager
{
   static std::shared_ptr<LogManager> s_instance;

   LogManagerImplementation m_logManagerImplementation;
   bool m_loggingEnabled{false};

public:
   LogManager(const LogManager&) = delete;
   void operator=(const LogManager&) = delete;

   static std::shared_ptr<LogManager> getInstance();
   static void destroyInstance();

   void setLoggingEnabled(bool enabled);
   bool getLoggingEnabled() const;

   void addLogger(std::shared_ptr<Logger> logger);

   Logger* getLoggerByType(const std::string& type);

#if 0
   template <typename CharT>
   void logInfo(std::basic_string<CharT> const& message, std::source_location const& location)
   {
      if (m_loggingEnabled) {
         //! \todo impl could also make use of std::source_location
         m_logManagerImplementation.logInfo(detail::to_wstring(message), location.file_name(), location.function_name(),
                                            location.line());
      }
   }

   template <typename... Args>
   void logInfo(std::format_string<Args...> fmt, Args&&... args, std::source_location const& location)
   {
      logInfo(std::format(fmt, std::forward<Args>(args)...), location);
   }
#endif

   void logInfo(const std::string& message, const std::string& file, const std::string& function,
                               unsigned int line);

   //! \todo make use of std::source_location
   void logInfo(const std::wstring& message, const std::string& file, const std::string& function,
                               unsigned int line);
   void logWarning(const std::string& message, const std::string& file, const std::string& function, unsigned int line);
   void logWarning(const std::wstring& message, const std::string& file, const std::string& function,
                   unsigned int line);
   void logError(const std::wstring& message, const std::string& file, const std::string& function, unsigned int line);
   void logError(const std::string& message, const std::string& file, const std::string& function, unsigned int line);

private:
   LogManager() = default;
};

#endif // LOG_MANAGER_H
