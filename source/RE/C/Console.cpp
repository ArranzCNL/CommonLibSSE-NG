#include "PCH.h"

#include "RE/C/Console.h"

#include "RE/T/TESObjectREFR.h"
#include "SKSE/Version.h"

namespace RE
{
	NiPointer<TESObjectREFR> Console::GetSelectedRef()
	{
		auto handle = GetSelectedRefHandle();
		return handle.get();
	}

	ObjectRefHandle Console::GetSelectedRefHandle()
	{
		REL::Relocation<ObjectRefHandle*> selectedRef{ RELOCATION_ID(519394, CHECK_RUNTIME(SKSE::RUNTIME_SSE_1_6_1130, 504099, 405935)) };
		return *selectedRef;
	}

	void Console::SetSelectedRef(NiPointer<TESObjectREFR> a_refPtr)
	{
		ObjectRefHandle handle(a_refPtr.get());
		SetSelectedRef_Impl(handle);
	}

	void Console::SetSelectedRef(TESObjectREFR* a_ref)
	{
		ObjectRefHandle handle(a_ref);
		SetSelectedRef_Impl(handle);
	}

	void Console::SetSelectedRef(ObjectRefHandle a_handle)
	{
		SetSelectedRef_Impl(a_handle);
	}

	void Console::SetSelectedRef_Impl(ObjectRefHandle& a_handle)
	{
		using func_t = decltype(&Console::SetSelectedRef_Impl);
		REL::Relocation<func_t> func{ Offset::Console::SetSelectedRef };
		return func(this, a_handle);
	}
}
