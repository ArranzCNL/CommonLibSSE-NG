#include "PCH.h"

#include "RE/R/RaceSexMenu.h"

namespace RE
{
	void RaceSexMenu::ChangeName(const char* a_name)
	{
		using func_t = decltype(&RaceSexMenu::ChangeName);
		static REL::Relocation<func_t> func{ Offset::RaceSexMenu::ChangeName };
		return func(this, a_name);
	}
}
