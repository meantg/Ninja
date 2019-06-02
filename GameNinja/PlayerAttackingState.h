#pragma once
#include "Player.h"
#include "PlayerState.h"
#include "PlayerRunningState.h"

class PlayerAttackingState : public PlayerState
{				// Biến tạm dùng xét State sẽ chuyển đổi sau khi thoát State
public:
	PlayerAttackingState();
	void Update(float dt);
	void HandleKeyboard();
};
