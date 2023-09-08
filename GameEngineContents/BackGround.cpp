#include "PreCompile.h"
#include "BackGround.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineTexture.h>

BackGround::BackGround()
{
	
}

BackGround::~BackGround()
{
}

void BackGround::Start()
{
	MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainSpriteRenderer->SetSprite("Title02.png");

	MainSpriteRenderer2 = CreateComponent<GameEngineSpriteRenderer>();
	MainSpriteRenderer2->SetSprite("Moon.png");
}

void BackGround::Update(float _Delta)
{
	
}