#pragma once


#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpShape.h"
#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	struct hkpShapeRayCastCollectorOutput
	{
	public:
		[[nodiscard]] constexpr bool hasHit() const noexcept { return hitFraction < 1.0F; }

		constexpr void reset() noexcept
		{
			hitFraction = 1.0F;
			shapeKey = HK_INVALID_SHAPE_KEY;
			extraInfo = -1;
		}


		// members
		hkVector4	 normal;							// 00
		float		 hitFraction{ 1.0F };				// 10
		std::int32_t extraInfo{ -1 };					// 14
		hkpShapeKey	 shapeKey{ HK_INVALID_SHAPE_KEY };	// 18
		std::int32_t pad{ 0 };							// 1C
	};
	static_assert(sizeof(hkpShapeRayCastCollectorOutput) == 0x20);
}
