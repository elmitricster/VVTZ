#include "PreCompile.h"
#include "TitleLevel.h"
#include "BackGround.h"
#include "Logo.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Start()
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

			GameEngineSprite::CreateSingle("Title_BG.png");
			GameEngineSprite::CreateSingle("Logo.png");
		}
	}

	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	std::shared_ptr<Logo> Lg = CreateActor<Logo>(ContentsObjectType::BackGround);
	std::shared_ptr<BackGround> Bg = CreateActor<BackGround>(ContentsObjectType::BackGround);
}

void TitleLevel::Update(float _Delta)
{
	
}

void TitleLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

void TitleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}