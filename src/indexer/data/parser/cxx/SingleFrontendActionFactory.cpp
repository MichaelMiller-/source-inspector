#include "SingleFrontendActionFactory.h"

SingleFrontendActionFactory::SingleFrontendActionFactory(clang::FrontendAction* action)
	: m_action(action)
{
              assert(m_action);
}

std::unique_ptr<clang::FrontendAction> SingleFrontendActionFactory::create()
{
	return std::unique_ptr<clang::FrontendAction>(m_action);
}
