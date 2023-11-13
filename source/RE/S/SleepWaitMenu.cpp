#include "PCH.h"

#include "RE/S/SleepWaitMenu.h"

namespace RE
{
	void SleepWaitMenu::OpenSleepWaitMenu(bool isSleep)
	{
		using func_t = decltype(&OpenSleepWaitMenu);
		REL::Relocation<func_t> func{ RELOCATION_ID(51618, 52490) };
		return func(isSleep);
	}
}
