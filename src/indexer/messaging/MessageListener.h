#ifndef MESSAGE_LISTENER_H
#define MESSAGE_LISTENER_H

#include <string>

#include "MessageBase.h"
#include "MessageListenerBase.h"
#include "MessageQueue.h"

template <typename MessageType>
class MessageListener : public MessageListenerBase
{
private:
   virtual std::string doGetType() const { return MessageType::getStaticType(); }

   virtual void doHandleMessageBase(MessageBase* message) { handleMessage(dynamic_cast<MessageType*>(message)); }

   virtual void handleMessage(MessageType* message) = 0;
};

#endif // MESSAGE_LISTENER_H
