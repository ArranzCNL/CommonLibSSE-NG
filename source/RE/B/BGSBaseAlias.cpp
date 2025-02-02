#include "PCH.h"

#include "RE/B/BGSBaseAlias.h"

#include "RE/B/BGSLocAlias.h"
#include "RE/B/BGSRefAlias.h"

namespace RE
{
	const BSFixedString& BGSBaseAlias::GetTypeString() const
	{
		return QType();
	}

	VMTypeID BGSBaseAlias::GetVMTypeID() const
	{
		const auto& TYPE = GetTypeString();
		if (TYPE == "Loc"sv) {
			return BGSLocAlias::VMTYPEID;
		} else if (TYPE == "Ref"sv) {
			return BGSRefAlias::VMTYPEID;
		} else {
			return BGSBaseAlias::VMTYPEID;
		}
	}

	bool BGSBaseAlias::IsEssential() const
	{
		return flags.all(FLAGS::kEssential);
	}

	bool BGSBaseAlias::IsProtected() const
	{
		return flags.all(FLAGS::kProtected);
	}

	bool BGSBaseAlias::IsQuestObject() const
	{
		return flags.all(FLAGS::kQuestObject);
	}

	void BGSBaseAlias::SetEssential(bool a_set)
	{
		if (a_set) {
			flags.set(FLAGS::kEssential);
		} else {
			flags.reset(FLAGS::kEssential);
		}
	}

	void BGSBaseAlias::SetProtected(bool a_set)
	{
		if (a_set) {
			flags.set(FLAGS::kProtected);
		} else {
			flags.reset(FLAGS::kProtected);
		}
	}
}
