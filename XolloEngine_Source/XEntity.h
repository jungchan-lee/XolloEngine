#pragma once
#include "CommonInclude.h"

namespace xollo
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { Name = name; }
		std::wstring& GetName() { return Name; }


	private:
		std::wstring Name;
	};

}

