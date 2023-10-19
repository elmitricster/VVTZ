#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineState.h>

enum class PlayerState
{
	Idle,
	Dash,
	Airborne,
	Run,
	Slash,
	UpSlash,
	DownSlash,
	Land,
	HardLand,
	LookDown,
	LookUp,
	Death,
	Walk,
};

// Ό³Έν :
class Player : public GameEngineActor
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainSpriteRenderer;
	float4 GravityForce = { 0.0f, 0.0f, 0.0f, 1.0f };

	std::shared_ptr<GameEngineCollision> Col;

	GameEngineState PlayerState;
	float MoveSpeed = 200.0f;
};

