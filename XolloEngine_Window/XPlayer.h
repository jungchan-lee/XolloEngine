#pragma once
#include "..//XolloEngine_Source//XGameObject.h"


namespace xollo
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}


