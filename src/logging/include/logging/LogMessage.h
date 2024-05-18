#ifndef LOG_MESSAGE_H
#define LOG_MESSAGE_H

#include <ctime>
#include <string>
#include <thread>

struct LogMessage
{
public:
   LogMessage(const std::wstring& message, const std::string& filePath, const std::string& functionName,
              const unsigned int line, const std::tm& time, const std::thread::id& threadId)
       : message(message), filePath(filePath), functionName(functionName), line(line), time(time), threadId(threadId)
   {
   }

   std::string getTimeString(const std::string& format) const
   {
      char timeString[50];
      strftime(timeString, 50, format.c_str(), &time);
      return std::string(timeString);
   }

   std::string getFileName() const { return filePath.substr(filePath.find_last_of("/\\") + 1); }

   //! \todo https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c12-dont-make-data-members-const-or-references-in-a-copyable-or-movable-type
   const std::wstring message;
   const std::string filePath;
   const std::string functionName;
   const unsigned int line;
   const std::tm time;
   const std::thread::id threadId;
};

#endif // LOG_MESSAGE_H
