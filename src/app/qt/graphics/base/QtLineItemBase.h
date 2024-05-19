#ifndef QT_LINE_ITEM_BASE_H
#define QT_LINE_ITEM_BASE_H

#include <QGraphicsItem>

#include "math/Vector4.h"

#include "GraphViewStyle.h"

class QtLineItemBase : public QGraphicsLineItem
{
public:
   enum Route { ROUTE_ANY, ROUTE_HORIZONTAL, ROUTE_VERTICAL };

   QtLineItemBase(QGraphicsItem* parent);
   virtual ~QtLineItemBase();

   void updateLine(const math::Vec4i& ownerRect, const math::Vec4i& targetRect, const math::Vec4i& ownerParentRect,
                   const math::Vec4i& targetParentRect, const GraphViewStyle::EdgeStyle& style, size_t weight,
                   bool showArrow);

   void setRoute(Route route);

   void setOnFront(bool front);
   void setOnBack(bool back);
   void setEarlyBend(bool earlyBend);

protected:
   QPolygon getPath() const;
   int getDirection(QPointF a, QPointF b) const;

   QRectF getArrowBoundingRect(const QPolygon& poly) const;
   void drawArrow(const QPolygon& poly, QPainterPath* path, QPainterPath* arrowPath = nullptr) const;

   void getPivotPoints(math::Vec2f* p, const math::Vec4i& in, const math::Vec4i& out, int offset, bool target) const;

   GraphViewStyle::EdgeStyle m_style;
   bool m_showArrow;

   bool m_onFront;
   bool m_onBack;
   bool m_earlyBend;

   Route m_route;

private:
   math::Vec4i m_ownerRect;
   math::Vec4i m_targetRect;

   math::Vec4i m_ownerParentRect;
   math::Vec4i m_targetParentRect;

   mutable QPolygon m_polygon;
};

#endif // QT_LINE_ITEM_BASE_H
