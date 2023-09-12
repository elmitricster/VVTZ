#include "PreCompile.h"
#include "PlayLevel.h"
#include "Player.h"
#include "PlayMap.h"
#include "Monster.h"
#include "TileMap.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
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

		GameEngineSprite::CreateCut("KOKOMI.png", 8, 4);
		GameEngineSprite::CreateSingle("KOKOMI2.png");
		GameEngineSprite::CreateSingle("BOCCHI.jpg");
		GameEngineSprite::CreateSingle("TestMap.png");
		GameEngineSprite::CreateSingle("TileEx.png");
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("FolderTexture");
		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			// ���������� �� �����ϰ� �ִ����� �ڽ��� ��Ȯ�ϰ� �����ϱ� ���ؼ�
			GameEngineDirectory& Dir = Directorys[i];

			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
	}

	{
		GameEngineRandom NewRanadom;
		for (size_t i = 0; i < 10; i++)
		{
			std::shared_ptr<Monster> Object = CreateActor<Monster>(ContentsObjectType::Monster);
			Object->Transform.SetLocalPosition(NewRanadom.RandomVectorBox2D(0, 1280, 0, -720));
		}
	}

	{
		std::shared_ptr<PlayMap> Object = CreateActor<PlayMap>(ContentsObjectType::BackGround);
		Map = Object;
	}

	/*{
		std::shared_ptr<TileMap> Object = CreateActor<TileMap>(ContentsObjectType::BackGround);

		size_t TileX = 100;
		size_t TileY = 100;

		Object->TileRenderer->CreateTileMap({ TileX, TileY, {80, 80}, "TileEx.png" });

		for (size_t y = 0; y < TileY; y++)
		{
			for (size_t x = 0; x < TileX; x++)
			{
				Object->TileRenderer->SetTile({ y, x,});
			}
		}
	}*/
}

void PlayLevel::Update(float _Delta)
{
	//static float Time = 0.0f;
	//Time += _Delta;

	//if (nullptr != Map && 3.0f <= Time)
	//{
	//	Map->Death();
	//	Map = nullptr;
	//	// Map = nullptr;
	//}


	if (GameEngineInput::IsDown('P'))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

	if (GameEngineInput::IsDown('N'))
	{
		GameEngineCore::ChangeLevel("EndingLevel");
	}
}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}