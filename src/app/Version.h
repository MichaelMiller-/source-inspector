#ifndef VERSION_H
#define VERSION_H

#include <string>

class Version
{
public:
   static void setApplicationVersion(const Version& version);
   static const Version& getApplicationVersion();

   explicit Version(int year = 0, int minor = 0, int commit = 0, std::string hash = {});

   [[nodiscard]] bool isEmpty() const;
   [[nodiscard]] bool isValid() const;

   [[nodiscard]] std::string toString() const;
   [[nodiscard]] std::string toDisplayString() const;
   [[nodiscard]] std::wstring toDisplayWString() const;

   bool operator<(const Version& other) const;
   bool operator>(const Version& other) const;
   bool operator==(const Version& other) const;

   Version& operator+=(const int& number);

private:
   static Version s_version;

   int m_year;
   int m_minorNumber;
   int m_commitNumber;

   std::string m_commitHash;
};

#endif // VERSION_H
