#include "XPlayer.h"
#include "XInput.h"
#include "XTransform.h"
#include "XTime.h"

namespace xollo
{
	Player::Player()
	{
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKeyDown(EKeyCode::Right))
		{
			Transform* Tform = GetComponent<Transform>();
			Vector2 Pos = Tform->GetPosition();
			Pos.x += 100.0f * Time::GetDeltaTime();
			Tform->SetPosition(Pos);
		}
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
