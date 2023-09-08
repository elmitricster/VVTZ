#include "PreCompile.h"
#include "ContentsCore.h"
#include "LogoLevel.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include <GameEngineCore/GameEngineSampler.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

ContentsCore::ContentsCore()
{
}

ContentsCore::~ContentsCore()
{
}

void ContentsCore::Start()
{
	//기본적으로 SpriteRenderer를 만들때 넣어줄 샘플러를 지정합니다.
	GameEngineSpriteRenderer::SetDefaultSampler("POINT");

	GameEngineCore::CreateLevel<LogoLevel>("LogoLevel");
	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::CreateLevel<EndingLevel>("EndingLevel");

	GameEngineCore::ChangeLevel("LogoLevel");

	// 자기 텍스처 로드해야 한다.

}

void ContentsCore::Update(float _Delta)
{
	
}

void ContentsCore::Release()
{

}