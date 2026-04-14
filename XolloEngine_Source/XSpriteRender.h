#pragma once
#include "XEntity.h"
#include "XComponent.h"

namespace xollo
{
	class SpriteRender : public Component
	{
	public:
		SpriteRender();
		~SpriteRender();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;


	private:


	};
}


