#include "PCH.h"

#include "RE/M/Main.h"

#include "RE/N/NiCamera.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	Main* Main::GetSingleton()
	{
		static REL::Relocation<Main**> singleton{ Offset::Main::Singleton };
		return *singleton;
	}

	float Main::QFrameAnimTime()
	{
		static REL::Relocation<float*> data{ RELOCATION_ID(516940, 403447) };
		return *data;
	}

	NiCamera* Main::WorldRootCamera()
	{
		using func_t = decltype(&Main::WorldRootCamera);
		static REL::Relocation<func_t> func{ RELOCATION_ID(35601, 36609) };
		return func();
	}

	Scenegraph* Main::WorldRootNode()
	{
		static REL::Relocation<NiPointer<Scenegraph>*> nodePtr{ RELOCATION_ID(517006, 403513) };
		return nodePtr->get();
	}

	void Main::SetActive(bool a_active)
	{
		using func_t = decltype(&Main::SetActive);
		static REL::Relocation<func_t> func{ RELOCATION_ID(35598, 36606) };
		return func(this, a_active);
	}
}
