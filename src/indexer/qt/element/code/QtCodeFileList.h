#ifndef QT_CODE_FILE_LIST
#define QT_CODE_FILE_LIST

#include <vector>

#include <QFrame>
#include <QScrollArea>

#include "CodeSnippetParams.h"
#include "QtCodeNavigable.h"
#include "QtScrollSpeedChangeListener.h"

class QtCodeFile;
class QtCodeFileTitleBar;
class QtCodeNavigator;
class QtCodeSnippet;

class QtCodeFileListScrollArea : public QScrollArea
{
protected:
   void keyPressEvent(QKeyEvent* event) override;
};

class QtCodeFileList : public QFrame, public QtCodeNavigable
{
   Q_OBJECT

public:
   explicit QtCodeFileList(QtCodeNavigator* navigator);
   ~QtCodeFileList() override = default;

   void clear();
   void clearSnippetTitleAndScrollBar();

   QtCodeFile* getFile(const FilePath& filePath);

   void addFile(const CodeFileParams& params);

   // QtCodeNavigable implementation
   QScrollArea* getScrollArea() override;

   void updateSourceLocations(const CodeSnippetParams& params) override;
   void updateFiles() override;

   void scrollTo(const FilePath& filePath, size_t lineNumber, Id locationId, Id scopeLocationId, bool animated,
                 CodeScrollParams::Target target, bool focusTarget) override;

   void onWindowFocus() override;

   void findScreenMatches(const std::wstring& query, std::vector<std::pair<QtCodeArea*, Id>>* screenMatches) override;

   void setFocus(Id locationId) override;
   void setFocusOnTop() override;
   void moveFocus(const CodeFocusHandler::Focus& focus, CodeFocusHandler::Direction direction) override;

   void copySelection() override;

   void maximizeFirstFile();

   [[nodiscard]] std::pair<QtCodeFile*, Id> getFirstFileWithActiveLocationId() const;
   [[nodiscard]] std::pair<QtCodeSnippet*, Id> getFirstSnippetAndActiveLocationId() const;

protected:
   void resizeEvent(QResizeEvent* event) override;

private slots:
   void updateSnippetTitleAndScrollBarSlot();
   void updateSnippetTitleAndScrollBar();

   void scrollLastSnippet(int value);
   void scrollLastSnippetScrollBar(int value);

private:
   void updateFirstSnippetTitleBar(QtCodeFile* file, int fileTitleBarOffset = 0);
   void updateLastSnippetScrollBar(QScrollBar* mirroredScrollBar);

   QtCodeNavigator* m_navigator;
   QtCodeFileListScrollArea* m_scrollArea;
   QFrame* m_filesArea;

   std::vector<QtCodeFile*> m_files;

   QtCodeFileTitleBar* m_firstSnippetTitleBar;
   const QtCodeFile* m_firstSnippetFile = nullptr;
   const QtCodeFileTitleBar* m_mirroredTitleBar;

   QScrollBar* m_lastSnippetScrollBar;
   QScrollBar* m_mirroredSnippetScrollBar;

   QtScrollSpeedChangeListener m_scrollSpeedChangeListener;
   int m_styleSize = 0;
};

#endif // QT_CODE_FILE_LIST
