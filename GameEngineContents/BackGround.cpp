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
	MainSpriteRenderer->SetSprite("Title_BG.png");
	MainSpriteRenderer->AutoSpriteSizeOn();
	MainSpriteRenderer->SetAutoScaleRatio(0.625f);
}

void BackGround::Update(float _Delta)
{
	
}