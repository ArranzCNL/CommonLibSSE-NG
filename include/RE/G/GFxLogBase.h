#pragma once

#include "RE/G/GFxLogConstants.h"

namespace RE
{
	template <class Derived>
	class GFxLogBase : public GFxLogConstants
	{
	public:
		virtual ~GFxLogBase() {}  // 00

		// add
		[[nodiscard]] virtual bool IsVerboseActionErrors() const { return true; }  // 01
	};
#if !defined(__INTELLISENSE__)
	static_assert(sizeof(GFxLogBase<void*>) == 0x8);
#endif
}
