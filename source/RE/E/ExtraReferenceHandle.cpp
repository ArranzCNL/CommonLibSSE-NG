#include "PCH.h"

#include "RE/E/ExtraReferenceHandle.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	ExtraReferenceHandle::ExtraReferenceHandle() :
		ExtraReferenceHandle(ObjectRefHandle())
	{}

	ExtraReferenceHandle::ExtraReferenceHandle(ObjectRefHandle a_containerRef) :
		BSExtraData(),
		containerRef(a_containerRef),
		pad14(0)
	{
		stl::emplace_vtable(this);
	}

	ExtraDataType ExtraReferenceHandle::GetType() const
	{
		return ExtraDataType::kReferenceHandle;
	}

	bool ExtraReferenceHandle::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraReferenceHandle*>(a_rhs);
		return containerRef != rhs->containerRef;
	}

	NiPointer<TESObjectREFR> ExtraReferenceHandle::GetOriginalReference()
	{
		return containerRef.get();
	}
}
