#include "PCH.h"

#include "RE/B/BGSSkillPerkTreeNode.h"

namespace RE
{
	BGSSkillPerkTreeNode::BGSSkillPerkTreeNode(std::int32_t a_index, ActorValueInfo* a_avInfo)
	{
		using func_t = BGSSkillPerkTreeNode* (*)(BGSSkillPerkTreeNode*, std::int32_t, ActorValueInfo*);
		static REL::Relocation<func_t> func{ Offset::BGSSkillPerkTreeNode::Ctor };
		func(this, a_index, a_avInfo);
	}
}
