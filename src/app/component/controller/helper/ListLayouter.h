#ifndef LIST_LAYOUTER_H
#define LIST_LAYOUTER_H

#include <memory>
#include <vector>

#include "math/Vector2.h"
#include "math/Vector4.h"

struct DummyNode;

class ListLayouter
{
public:
   static void layoutRow(std::vector<std::shared_ptr<DummyNode>>* nodes, int gap);
   static void layoutColumn(std::vector<std::shared_ptr<DummyNode>>* nodes, int gap);

   static void layoutMultiColumn(math::Vec2i viewSize, std::vector<std::shared_ptr<DummyNode>>* nodes);
   static void layoutSquare(std::vector<std::shared_ptr<DummyNode>>* nodes, int maxWidth);
   static void layoutSkewed(std::vector<std::shared_ptr<DummyNode>>* nodes, int gapX, int gapY, int maxWidth);

   static math::Vec4i boundingRect(const std::vector<std::shared_ptr<DummyNode>>& nodes);
   static math::Vec2i offsetNodes(std::vector<std::shared_ptr<DummyNode>> nodes, int top, int left);

private:
   static void layoutSimple(std::vector<std::shared_ptr<DummyNode>>* nodes, int gapX, int gapY, bool horizontal);
   static bool layoutSquareInternal(std::vector<std::shared_ptr<DummyNode>>& visibleNodes, const math::Vec2i& maxSize,
                                    const math::Vec2i& gap);
};

#endif // LIST_LAYOUTER_H
