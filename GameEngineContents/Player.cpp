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
		// MainSpriteRenderer->SetMaterial("2DTextureOver");
		MainSpriteRenderer->SetSprite("BOCCHI.jpg");
		MainSpriteRenderer->SetImageScale({250.0f, 300.0f, 1.0f});

		/*MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(30);
		MainSpriteRenderer->CreateAnimation("Dance", "Lu", 0.1f, -1, -1, true);
		MainSpriteRenderer->ChangeAnimation("Dance");
		MainSpriteRenderer->Transform.SetLocalPosition({ 0.0f, 0.0f, 0.0f});
		MainSpriteRenderer->AutoSpriteSizeOn();

		MainSpriteRenderer->SetEndEvent("Dance", std::bind(&Player::TestEvent, this, std::placeholders::_1));*/
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
		Col->SetCollisionType(ColType::SPHERE2D);
		Col->Transform.SetLocalPosition({ 0.0f, -50.0f, 0.0f });
		Col->Transform.SetLocalScale({ 100.0f, 100.0f, 1.0f });
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, 100.0f });

	GameEngineInput::AddInputObject(this);

	GetLevel()->GetMainCamera()->CameraTargetSetting(Transform, float4::BACKWARD * 500.0f);
}

void Player::TestEvent(GameEngineRenderer* _Renderer)
{
}

void Player::Update(float _Delta)
{
	float Speed = 100.0f;

	EventParameter Para;

	Para.Enter = [](class GameEngineCollision* _This, class GameEngineCollision* _Other)
		{
			_Other->GetActor()->Death();
			int a = 0;
		};

	Para.Stay = [](class GameEngineCollision* _This, class GameEngineCollision* _Other)
		{
			_Other->Off();
			int a = 0;
		};

	Para.Exit = [](class GameEngineCollision* _This, class GameEngineCollision* _Other)
		{
			int a = 0;
		};

	Col->CollisionEvent(ContentsCollisionType::Monster, Para);

	if (GameEngineInput::IsPress('A', this))
	{
		MainSpriteRenderer->LeftFlip();
		Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D', this))
	{
		MainSpriteRenderer->RightFlip();
		Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('W', this))
	{
		Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('S', this))
	{
		Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('Q', this))
	{
		GetLevel()->GetMainCamera()->AddZoomValue(-_Delta);
		Transform.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });
	}

	if (GameEngineInput::IsPress('E', this))
	{
		GetLevel()->GetMainCamera()->AddZoomValue(+_Delta);
		Transform.AddLocalRotation({ 0.0f, 0.0f, -360.0f * _Delta });
	}
	
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
	// 땅에 딱붙게하고 싶다면 while돌려서 올려주세요.


	// float4 Color = GetColor(Transform.GetWorldPosition());
}