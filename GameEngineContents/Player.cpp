#include "PreCompile.h"
#include "Player.h"
#include "PlayMap.h"
#include "Monster.h"
#include "ContentsEnum.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	{
		MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(30);
		MainSpriteRenderer->SetSprite("BOCCHI.jpg");
		MainSpriteRenderer->SetImageScale({250.0f, 300.0f, 1.0f});

		/*MainSpriteRenderer->CreateAnimation("Dance", "Lu", 0.1f, -1, -1, true);
		MainSpriteRenderer->ChangeAnimation("Dance");

		MainSpriteRenderer->SetEndEvent("Dance", std::bind(&Player::TestEvent, this, std::placeholders::_1));

		MainSpriteRenderer->AutoSpriteSizeOn();
		MainSpriteRenderer->Transform.SetLocalPosition({ 0.0f, 100.0f, 0.0f, 0.0f });
		MainSpriteRenderer->SetAutoScaleRatio(0.5f);
		MainSpriteRenderer->Transform.SetLocalScale({ 200.0f, 200.0f, 1.0f });*/
	}

	/*{
		MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(30);
		MainSpriteRenderer->SetSprite("HoHoYee_AttackABC2");
		MainSpriteRenderer->Transform.SetLocalPosition({ -100, 150, 1.0f });
		MainSpriteRenderer->SetImageScale({ 200.0f, 20.0f });
		MainSpriteRenderer->SetPivotType(PivotType::Left);
	}*/

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Player);
		Col->Transform.SetLocalScale({ 250.0f, 300.0f, 1.0f });
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
}

void Player::TestEvent(GameEngineRenderer* _Renderer)
{
	int a = 0;
}

void Player::Update(float _Delta)
{
	MainSpriteRenderer->AddImageScale(float4{ -10.0f, 0.0f, 0.0f } *_Delta);

	// ���Ͱ� ���Ͷ� �浹�ϰ� ������?
	// �� �̷��� ��ġ

	EventParameter Event;

	Event.Enter = [](GameEngineCollision* _this, GameEngineCollision* Col)
		{
			Col->GetActor()->Death();
			int a = 0;
		};

	Event.Stay = [](GameEngineCollision* _this, GameEngineCollision* Col)
		{
			int a = 0;
		};

	Event.Exit = [](GameEngineCollision* _this, GameEngineCollision* Col)
		{
			int a = 0;
		};

	Col->CollisionEvent(ContentsCollisionType::Monster, Event);

	//if (xxxx ��Ȳ�� �Ǹ�)
	//{
	//	MainSpriteRenderer->Death();
	//	MainSpriteRenderer = nullptr;
	//}

	// �浹�߳� ���߳ĸ� ����

	//std::list<std::shared_ptr<Monster>> MonsterList =
	//	GetLevel()->GetObjectGroupConvert<Monster>(ContentsObjectType::Monster);

	//for (std::shared_ptr<Monster> MonsterPtr : MonsterList)
	//{
	//	// �������� �ϴ� ���� => ���ͷε� �Ҽ��ִµ�
	//	// ���� ���ʹ� ��ġ�� ������ ����ִ� �뵵�� ���˴ϴ�.
	//	// MainSpriteRenderer->Transform.Collision(MonsterPtr->Renderer->Transform);

	//	GameEngineTransform& Left = MainSpriteRenderer->Transform;
	//	GameEngineTransform& Right = MonsterPtr->Renderer->Transform;

	//	if (GameEngineTransform::Collision({ Left , Right, ColType::OBBBOX2D }))
	//	{
	//		MonsterPtr->Death();
	//		// �浹�ߴ�.
	//	}
	//}

	float Speed = 100.0f;

	if (GameEngineInput::IsDown('M'))
	{
		MainSpriteRenderer->AnimationPauseSwitch();
	}

	if (GameEngineInput::IsPress('A'))
	{
		MainSpriteRenderer->LeftFlip();
		Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D'))
	{
		MainSpriteRenderer->RightFlip();
		Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('W'))
	{
		Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('S'))
	{
		Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('Q'))
	{
		Transform.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });
	}

	if (GameEngineInput::IsPress('E'))
	{
		Transform.AddLocalRotation({ 0.0f, 0.0f, -360.0f * _Delta });
	}

	GetLevel()->GetMainCamera()->Transform.SetLocalPosition(Transform.GetWorldPosition());
	
	// float4 WorldMousePos = GetLevel()->GetMainCamera()->GetWorldMousePos2D();
	// OutputDebugStringA(WorldMousePos.ToString("\n").c_str());

	// OutputDebugStringA(GameEngineCore::MainWindow.GetMousePos().ToString("\n").c_str());

	/*GameEngineColor Color = PlayMap::MainMap->GetColor(Transform.GetWorldPosition(), GameEngineColor::RED);

	if (GameEngineColor::RED != Color)
	{
		GravityForce.Y -= _Delta * 100.0f;
		Transform.AddLocalPosition(GravityForce * _Delta);
	}
	else
	{
		GravityForce = 0.0f;
	}*/
	// ���� ���ٰ��ϰ� �ʹٸ� while������ �÷��ּ���.


	// float4 Color = GetColor(Transform.GetWorldPosition());
}