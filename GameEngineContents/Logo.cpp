#include "PreCompile.h"
#include "Logo.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineTexture.h>

Logo::Logo()
{

}

Logo::~Logo()
{
}

void Logo::Start()
{
	MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainSpriteRenderer->SetSprite("Logo.png");

	MainSpriteRenderer->AutoSpriteSizeOn();
	MainSpriteRenderer->SetAutoScaleRatio(0.6f);
	MainSpriteRenderer->Transform.SetLocalPosition({0.0f, 150.0f, 0.0f});
}

void Logo::Update(float _Delta)
{

}