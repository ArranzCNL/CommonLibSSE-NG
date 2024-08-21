#include "PCH.h"

#include "RE/A/AnimationFileManagerSingleton.h"

namespace RE
{
	bool AnimationFileManagerSingleton::Load(const hkbContext& a_context, hkbClipGenerator* a_clipGenerator, BSSynchronizedClipGenerator* a_synchronizedClipGenerator)
	{
		using func_t = decltype(&AnimationFileManagerSingleton::Load);
		static REL::Relocation<func_t> func{ RELOCATION_ID(63070, 63982) };
		return func(this, a_context, a_clipGenerator, a_synchronizedClipGenerator);
	}
}
