#include "PCH.h"

#include "RE/E/EffectArchetypes.h"

namespace RE
{
	std::string_view EffectArchetypeToString(EffectArchetype a_archetype) noexcept
	{
		switch (a_archetype) {
		case EffectArchetype::kValueModifier:
			return "ValueMod";
		case EffectArchetype::kScript:
			return "Script";
		case EffectArchetype::kDispel:
			return "Dispel";
		case EffectArchetype::kCureDisease:
			return "CureDisease";
		case EffectArchetype::kAbsorb:
			return "Absorb";
		case EffectArchetype::kDualValueModifier:
			return "DualValueMod";
		case EffectArchetype::kCalm:
			return "Calm";
		case EffectArchetype::kDemoralize:
			return "Demoralize";
		case EffectArchetype::kFrenzy:
			return "Frenzy";
		case EffectArchetype::kDisarm:
			return "Disarm";
		case EffectArchetype::kCommandSummoned:
			return "CommandSummoned";
		case EffectArchetype::kInvisibility:
			return "Invisibility";
		case EffectArchetype::kLight:
			return "Light";
		case EffectArchetype::kDarkness:
			return "Darkness";
		case EffectArchetype::kNightEye:
			return "NightEye";
		case EffectArchetype::kLock:
			return "Lock";
		case EffectArchetype::kOpen:
			return "Open";
		case EffectArchetype::kBoundWeapon:
			return "BoundWeapon";
		case EffectArchetype::kSummonCreature:
			return "SummonCreature";
		case EffectArchetype::kDetectLife:
			return "DetectLife";
		case EffectArchetype::kTelekinesis:
			return "Telekinesis";
		case EffectArchetype::kParalysis:
			return "Paralysis";
		case EffectArchetype::kReanimate:
			return "Reanimate";
		case EffectArchetype::kSoulTrap:
			return "SoulTrap";
		case EffectArchetype::kTurnUndead:
			return "TurnUndead";
		case EffectArchetype::kGuide:
			return "Guide";
		case EffectArchetype::kWerewolfFeed:
			return "WerewolfFeed";
		case EffectArchetype::kCureParalysis:
			return "CureParalysis";
		case EffectArchetype::kCureAddiction:
			return "CureAddiction";
		case EffectArchetype::kCurePoison:
			return "CurePoison";
		case EffectArchetype::kConcussion:
			return "Concussion";
		case EffectArchetype::kValueAndParts:
			return "ValueAndParts";
		case EffectArchetype::kAccumulateMagnitude:
			return "AccumulateMagnitude";
		case EffectArchetype::kStagger:
			return "Stagger";
		case EffectArchetype::kPeakValueModifier:
			return "PeakValueMod";
		case EffectArchetype::kCloak:
			return "Cloak";
		case EffectArchetype::kWerewolf:
			return "Werewolf";
		case EffectArchetype::kSlowTime:
			return "SlowTime";
		case EffectArchetype::kRally:
			return "Rally";
		case EffectArchetype::kEnhanceWeapon:
			return "EnhanceWeapon";
		case EffectArchetype::kSpawnHazard:
			return "SpawnHazard";
		case EffectArchetype::kEtherealize:
			return "Etherealize";
		case EffectArchetype::kBanish:
			return "Banish";
		case EffectArchetype::kSpawnScriptedRef:
			return "SpawnScriptedRef";
		case EffectArchetype::kDisguise:
			return "Disguise";
		case EffectArchetype::kGrabActor:
			return "GrabActor";
		case EffectArchetype::kVampireLord:
			return "VampireLord";
		default:
			return "None";
		}
	}
}
