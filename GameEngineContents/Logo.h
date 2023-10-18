#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo();
	~Logo();

	// delete Function
	Logo(const Logo& _Other) = delete;
	Logo(Logo&& _Other) noexcept = delete;
	Logo& operator=(const Logo& _Other) = delete;
	Logo& operator=(Logo&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta);

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainSpriteRenderer;
};