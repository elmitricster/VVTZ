#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class LogoLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	LogoLevel();
	~LogoLevel();

	// delete Function
	LogoLevel(const LogoLevel& _Other) = delete;
	LogoLevel(LogoLevel&& _Other) noexcept = delete;
	LogoLevel& operator=(const LogoLevel& _Other) = delete;
	LogoLevel& operator=(LogoLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:

};

