#include "PCH.h"

#include "RE/B/BGSStoryTeller.h"

namespace RE
{
	BGSStoryTeller* BGSStoryTeller::GetSingleton()
	{
		static REL::Relocation<BGSStoryTeller**> singleton{ Offset::BGSStoryTeller::Singleton };
		return *singleton;
	}

	void BGSStoryTeller::BeginShutDownQuest(TESQuest* a_quest)
	{
		using func_t = decltype(&BGSStoryTeller::BeginShutDownQuest);
		static REL::Relocation<func_t> func{ Offset::BGSStoryTeller::BeginShutDownQuest };
		return func(this, a_quest);
	}

	void BGSStoryTeller::BeginStartUpQuest(TESQuest* a_quest)
	{
		using func_t = decltype(&BGSStoryTeller::BeginStartUpQuest);
		static REL::Relocation<func_t> func{ Offset::BGSStoryTeller::BeginStartUpQuest };
		return func(this, a_quest);
	}
}
