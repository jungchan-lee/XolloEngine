#pragma once
#include "XEntity.h"
#include "XComponent.h"

namespace xollo
{
	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPosition(Vector2 Pos) { mPosition.x = Pos.x; mPosition.y = Pos.y; }
		Vector2 GetPosition() { return mPosition; }


	private:
		Vector2 mPosition;
	};
}


