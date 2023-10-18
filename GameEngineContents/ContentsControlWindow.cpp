#include "PreCompile.h"
#include "ContentsControlWindow.h"

void TestTab::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	std::string FPS;
	FPS = std::to_string(static_cast<int>(1.0f / _DeltaTime));
	FPS = "FPS : " + FPS;
	ImGui::Text(FPS.c_str());
	ImGui::Text("\n");

	std::string MousePos = GameEngineCore::MainWindow.GetMousePos().ToString();

	ImGui::Text(MousePos.c_str());
	ImGui::Text("\n");

	if (ImGui::Button("Collision OnOff"))
	{
		GameEngineLevel::IsDebug = !GameEngineLevel::IsDebug;
	}

	//std::list<std::shared_ptr<GameEngineObject>> ObjectLists = _Level->GetObjectGroupInt(0);

	//std::vector<std::shared_ptr<GameEngineObject>> Objects;

	//for (std::shared_ptr<GameEngineObject> Ptr : ObjectLists)
	//{
	//	Objects.push_back(Ptr);
	//}

	//if (Objects.size())
	//{
	//	std::vector<std::string> Names;

	//	for (std::shared_ptr<GameEngineObject> Ptr : Objects)
	//	{
	//		Names.push_back(Ptr->GetName());
	//	}

	//	//Names.push_back("aaaa");
	//	//Names.push_back("bbbb");

	//	std::vector<const char*> CNames;

	//	for (size_t i = 0; i < Names.size(); i++)
	//	{
	//		CNames.push_back(Names[i].c_str());
	//	}

	//	if (ImGui::ListBox("ObjectList", &Select, &CNames[0], static_cast<int>(Names.size())))
	//	{
	//		SelectObject = Objects[Select];
	//	}

	//	if (nullptr != SelectObject)
	//	{
	//		if (ImGui::Button("Select Object Off"))
	//		{
	//			SelectObject->Off();
	//		}
	//	}
	//}
}


void ContentsControlWindow::Start()
{
	Tabs.push_back(std::make_shared<LevelChangeTab>("LevelChangeTab"));
	CurTab = Tabs[0];
	Tabs.push_back(std::make_shared<TestTab>("Test"));
	Tabs.push_back(std::make_shared<MapEditorTab>("MapEditor"));
}

void LevelChangeTab::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	std::map<std::string, std::shared_ptr<GameEngineLevel>>& AllLevels = GameEngineCore::GetAllLevel();

	for (std::pair<const std::string, std::shared_ptr<GameEngineLevel>> Pair : AllLevels)
	{
		if (ImGui::Button(Pair.first.c_str()))
		{
			GameEngineCore::ChangeLevel(Pair.first);
		}
	}
}

void ContentsControlWindow::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	for (size_t i = 0; i < Tabs.size(); i++)
	{
		ImGui::SameLine();
		if (ImGui::Button(Tabs[i]->Name.c_str()))
		{
			CurTab = Tabs[i];
		}
	}

	if (nullptr != CurTab)
	{
		CurTab->OnGUI(_Level, _DeltaTime);
	}
}
