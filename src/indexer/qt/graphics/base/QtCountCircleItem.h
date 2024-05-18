#ifndef QT_COUNT_CIRCLE_ITEM_H
#define QT_COUNT_CIRCLE_ITEM_H

#include "math/Vector2.h"

#include "QtRoundedRectItem.h"

class QtCountCircleItem : public QtRoundedRectItem
{
public:
   QtCountCircleItem(QGraphicsItem* parent);

   void setPosition(const math::Vec2f& pos);
   void setNumber(size_t number);
   void setStyle(QColor color, QColor fontColor, QColor borderColor, size_t borderWidth);

private:
   QGraphicsSimpleTextItem* m_number;
};

#endif // QT_COUNT_CIRCLE_ITEM_H
