#include <catch.hpp>

#include "math/Vector2.h"

TEST_CASE("Vector2 class", "[source-inspector][math]")
{
   using namespace math;

   SECTION("default construction")
   {
     Vec2i value{};
     REQUIRE(value[0] == 0);
     REQUIRE(value[1] == 0);
   }
}
