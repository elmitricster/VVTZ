#include "PreCompile.h"
#include "ContentsCore.h"
#include "LogoLevel.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include "EndingLevel.h"

ContentsCore::ContentsCore()
{
}

ContentsCore::~ContentsCore()
{
}

void ContentsCore::Start()
{
	GameEngineCore::CreateLevel<LogoLevel>("LogoLevel");
	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::CreateLevel<EndingLevel>("EndingLevel");

	GameEngineCore::ChangeLevel("LogoLevel");

	// �ڱ� �ؽ�ó �ε��ؾ� �Ѵ�.

}

void ContentsCore::Update(float _Delta)
{
	
}

void ContentsCore::Release()
{

}