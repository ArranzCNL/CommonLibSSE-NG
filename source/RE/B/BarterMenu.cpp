#include "PCH.h"

#include "RE/B/BarterMenu.h"

namespace RE
{
	RefHandle BarterMenu::GetTargetRefHandle()
	{
		static REL::Relocation<RefHandle*> handle{ RELOCATION_ID(519283, 403520) };
		return *handle;
	}

	bool BarterMenu::IsViewingVendorItems() noexcept
	{
		RE::GFxValue result;
		return (this->root.Invoke("isViewingVendorItems", &result) && result.GetBool());
	}
}
