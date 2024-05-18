#pragma once

#include <clang/Tooling/Tooling.h>

class SingleFrontendActionFactory : public clang::tooling::FrontendActionFactory
{
  clang::FrontendAction *m_action{nullptr};
public:
  explicit SingleFrontendActionFactory(clang::FrontendAction *action);

  std::unique_ptr<clang::FrontendAction> create() override;
};
