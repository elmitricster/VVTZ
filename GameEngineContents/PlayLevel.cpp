#include "PreCompile.h"
#include "PlayLevel.h"
#include "Player.h"
#include "PlayMap.h"
#include "Monster.h"
#include "TileMap.h"
#include "MainUIActor.h"

void TestGUIWindow::Start()
{

}

void TestGUIWindow::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	std::string MousePos = GameEngineCore::MainWindow.GetMousePos().ToString();

	if (ImGui::Button(MousePos.c_str()))
	{

	}

	if (ImGui::Button("Collision OnOff"))
	{
		GameEngineLevel::IsDebug = !GameEngineLevel::IsDebug;
	}

	std::list<std::shared_ptr<GameEngineObject>> ObjectLists = _Level->GetObjectGroupInt(0);

	std::vector<std::shared_ptr<GameEngineObject>> Objects;

	for (std::shared_ptr<GameEngineObject> Ptr : ObjectLists)
	{
		Objects.push_back(Ptr);
	}


	if (Objects.size())
	{
		std::vector<std::string> Names;

		for (std::shared_ptr<GameEngineObject> Ptr : Objects)
		{
			Names.push_back(Ptr->GetName());
		}

		//Names.push_back("aaaa");
		//Names.push_back("bbbb");

		std::vector<const char*> CNames;

		for (size_t i = 0; i < Names.size(); i++)
		{
			CNames.push_back(Names[i].c_str());
		}

		if (ImGui::ListBox("ObjectList", &Select, &CNames[0], Names.size()))
		{
			SelectObject = Objects[Select];
		}

		if (nullptr != SelectObject)
		{
			if (ImGui::Button("Select Object Off"))
			{
				SelectObject->Off();
			}
		}
	}
}

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{
	GameEngineGUI::CreateGUIWindow<TestGUIWindow>("Test");

	GameEngineCore::GetBackBufferRenderTarget()->SetClearColor({ 0, 0, 0, 1 });

	{
		// 엔진용 쉐이더를 전부다 전부다 로드하는 코드를 친다.
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("Texture");
		std::vector<GameEngineFile> Files = Dir.GetAllFile();

		for (size_t i = 0; i < Files.size(); i++)
		{
			// 구조적으로 잘 이해하고 있는지를 자신이 명확하게 인지하기 위해서
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
			// 구조적으로 잘 이해하고 있는지를 자신이 명확하게 인지하기 위해서
			GameEngineDirectory& Dir = Directorys[i];

			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, 0.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
		PlayerObject = Object;
	}

	{
		std::shared_ptr<PlayMap> Object = CreateActor<PlayMap>(ContentsObjectType::BackGround);
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
	/*std::string FPS;
	FPS = std::to_string(static_cast<int>(1.0f / _Delta));
	FPS += "\n";
	OutputDebugStringA(FPS.c_str());*/

	if (GameEngineInput::IsDown('P', this))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

	if (GameEngineInput::IsDown('N', this))
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