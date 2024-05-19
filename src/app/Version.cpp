#include "Version.h"

#include <format>
#include <utility>

Version Version::s_version;

void Version::setApplicationVersion(const Version& version) { s_version = version; }

const Version& Version::getApplicationVersion() { return s_version; }

Version::Version(int year, int minor, int commit, std::string hash)
    : m_year(year), m_minorNumber(minor), m_commitNumber(commit), m_commitHash(std::move(hash))
{
}

bool Version::isEmpty() const { return m_year == 0 && m_minorNumber == 0 && m_commitNumber == 0; }

//! \todo what kind of funny check is this?
bool Version::isValid() const { return (0 < m_minorNumber && m_minorNumber < 5 && m_year > 2016); }

std::string Version::toString() const
{
   return std::format("{}.{}-{}-{}", m_year, m_minorNumber, m_commitNumber, m_commitHash);
}

std::string Version::toDisplayString() const { return std::format("{}.{}.{}", m_year, m_minorNumber, m_commitNumber); }

//! \todo why support multiple string types?
std::wstring Version::toDisplayWString() const
{
   return std::format(L"{}.{}.{}", m_year, m_minorNumber, m_commitNumber);
}

bool Version::operator<(const Version& other) const
{
   if (m_year != other.m_year) {
      return m_year < other.m_year;
   } else if (m_minorNumber != other.m_minorNumber) {
      return m_minorNumber < other.m_minorNumber;
   }
   return m_commitNumber < other.m_commitNumber;
}

bool Version::operator>(const Version& other) const
{
   if (m_year != other.m_year) {
      return m_year > other.m_year;
   } else if (m_minorNumber != other.m_minorNumber) {
      return m_minorNumber > other.m_minorNumber;
   }
   return m_commitNumber > other.m_commitNumber;
}

bool Version::operator==(const Version& other) const
{
   return m_year == other.m_year && m_minorNumber == other.m_minorNumber && m_commitNumber == other.m_commitNumber;
}

Version& Version::operator+=(const int& number)
{
   int minor = this->m_minorNumber - 1 + number;
   this->m_year += minor / 4;
   this->m_minorNumber = (minor % 4) + 1;
   return *this;
}
