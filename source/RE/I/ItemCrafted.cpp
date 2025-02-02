#include "PCH.h"

#include "RE/I/ItemCrafted.h"

namespace RE
{
	BSTEventSource<ItemCrafted::Event>* ItemCrafted::GetEventSource()
	{
		using func_t = decltype(&ItemCrafted::GetEventSource);
		static REL::Relocation<func_t> func{ Offset::ItemCrafted::GetEventSource };
		return func();
	}
}
