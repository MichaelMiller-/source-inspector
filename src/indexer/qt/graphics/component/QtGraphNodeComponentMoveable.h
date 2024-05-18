#ifndef QT_GRAPH_NODE_COMPONENT_MOVEABLE
#define QT_GRAPH_NODE_COMPONENT_MOVEABLE

#include "QtGraphNodeComponent.h"

#include "math/Vector2.h"

class QtGraphNodeComponentMoveable : public QtGraphNodeComponent
{
public:
   QtGraphNodeComponentMoveable(QtGraphNode* graphNode);

   virtual void nodeMousePressEvent(QGraphicsSceneMouseEvent* event);
   virtual void nodeMouseMoveEvent(QGraphicsSceneMouseEvent* event);
   virtual void nodeMouseReleaseEvent(QGraphicsSceneMouseEvent* event);

private:
   math::Vec2i m_mouseOffset;
   math::Vec2i m_oldPos;
};

#endif // QT_GRAPH_NODE_COMPONENT_MOVEABLE
