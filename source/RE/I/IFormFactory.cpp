#include "PCH.h"

#include "RE/I/IFormFactory.h"

namespace RE
{
	std::pair<IFormFactory**, bool> IFormFactory::GetFormFactories()
	{
		struct Factories
		{
			IFormFactory* data[stl::to_underlying(FormType::Max)];
		};

		static REL::Relocation<Factories*> formFactories{ RELOCATION_ID(514355, 400508) };
		static REL::Relocation<bool*>      formFactoriesInitialized{ RELOCATION_ID(514349, 400503) };
		return std::make_pair(formFactories->data, *formFactoriesInitialized);
	}

	IFormFactory* IFormFactory::GetFormFactoryByType(FormType a_formType)
	{
		auto formFactories = GetFormFactories();
		return formFactories.second ? formFactories.first[static_cast<std::uint32_t>(a_formType)] : nullptr;
	}

	TESForm* IFormFactory::Create()
	{
		return CreateImpl();
	}
}
