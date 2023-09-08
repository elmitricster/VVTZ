#include "PreCompile.h"
#include "LogoLevel.h"
#include "BackGround.h"

LogoLevel::LogoLevel()
{
}

LogoLevel::~LogoLevel()
{
}

void LogoLevel::Start()
{
	{
		// ������ ���̴��� ���δ� ���δ� �ε��ϴ� �ڵ带 ģ��.
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("Texture");
		std::vector<GameEngineFile> Files = Dir.GetAllFile();

		for (size_t i = 0; i < Files.size(); i++)
		{
			// ���������� �� �����ϰ� �ִ����� �ڽ��� ��Ȯ�ϰ� �����ϱ� ���ؼ�
			GameEngineFile& File = Files[i];
			GameEngineTexture::Load(File.GetStringPath());
		}

		GameEngineSprite::CreateSingle("Title02.png");
		GameEngineSprite::CreateSingle("Moon.png");
	}

	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	std::shared_ptr<BackGround> Bg = CreateActor<BackGround>(ContentsObjectType::BackGround);
}

void LogoLevel::Update(float _Delta)
{
	if (GameEngineInput::IsDown('N'))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}
}


void LogoLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

void LogoLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}