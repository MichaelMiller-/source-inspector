#ifndef MESSAGE_GRAPH_NODE_MOVE_H
#define MESSAGE_GRAPH_NODE_MOVE_H

#include "Message.h"
#include "TabId.h"
#include "math/Vector2.h"
#include "types.h"

class MessageGraphNodeMove : public Message<MessageGraphNodeMove>
{
public:
   MessageGraphNodeMove(Id tokenId, const math::Vec2i& delta) : tokenId(tokenId), delta(delta)
   {
      setSchedulerId(TabId::currentTab());
   }

   static std::string getStaticType() { return "MessageGraphNodeMove"; }

   void print(std::wostream& os) const override { os << tokenId << L" " << delta.toWString(); }

   //! \todo
   //! https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c12-dont-make-data-members-const-or-references-in-a-copyable-or-movable-type
   const Id tokenId;
   //! \todo
   //! https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c12-dont-make-data-members-const-or-references-in-a-copyable-or-movable-type
   const math::Vec2i delta;
};

#endif // MESSAGE_GRAPH_NODE_MOVE_H
