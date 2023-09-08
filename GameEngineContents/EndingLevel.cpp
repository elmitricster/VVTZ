#include "PreCompile.h"
#include "EndingLevel.h"

EndingLevel::EndingLevel()
{
}

EndingLevel::~EndingLevel()
{
}

void EndingLevel::Start()
{

}

void EndingLevel::Update(float _Delta)
{
	if (GameEngineInput::IsDown('P'))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}
}

void EndingLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

void EndingLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}