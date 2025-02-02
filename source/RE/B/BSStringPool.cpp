#include "PCH.h"

#include "RE/B/BSStringPool.h"

namespace RE
{
	BucketTable* BucketTable::GetSingleton()
	{
		using func_t = decltype(&BucketTable::GetSingleton);
		static REL::Relocation<func_t> func{ Offset::BucketTable::GetSingleton };
		return func();
	}
}
