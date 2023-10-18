#include "PreCompile.h"
#include "PlayLevel.h"
#include "Player.h"
#include "PlayMap.h"
#include "Monster.h"
#include "TileMap.h"
#include "MainUIActor.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{
	GameEngineCore::GetBackBufferRenderTarget()->SetClearColor({ 0, 0, 0, 1 });

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

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, 0.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		std::shared_ptr<Player> Object = CreateActor<Player>(0, "Player");
		PlayerObject = Object;
	}

	{
		std::shared_ptr<PlayMap> Object = CreateActor<PlayMap>(0, "Map");
		Map = Object;
	}

	//{
	//	std::shared_ptr<MainUIActor> Object = CreateActor<MainUIActor>(ContentsObjectType::UI);
	//}

	//{
	//	GameEngineRandom NewRanadom;
	//	for (size_t i = 0; i < 10; i++)
	//	{
	//		std::shared_ptr<Monster> Object = CreateActor<Monster>(ContentsObjectType::Monster);
	//		Object->Transform.SetLocalPosition(NewRanadom.RandomVectorBox2D(0, 1280, 0, -720));
	//	}
	//}

	//{
	//	std::shared_ptr<TileMap> Object = CreateActor<TileMap>(ContentsObjectType::BackGround);

	//	size_t TileX = 100;
	//	size_t TileY = 100;

	//	Object->TileRenderer->CreateTileMap({ TileX, TileY, {64, 64}, "kokomi2.png" });

	//	for (size_t y = 0; y < TileY; y++)
	//	{
	//		for (size_t x = 0; x < TileX; x++)
	//		{
	//			Object->TileRenderer->SetTileIndex({ y, x });
	//		}
	//	}

	//	TileMapObject = Object;
	//}
}

void PlayLevel::Update(float _Delta)
{

}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}