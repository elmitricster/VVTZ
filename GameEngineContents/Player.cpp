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
		MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(0);
		// MainSpriteRenderer->SetMaterial("2DTextureOver");

		// MainSpriteRenderer->SetMaskTexture("Mask.png", MaskMode::DynamicMask);
		// MainSpriteRenderer->RenderBaseInfoValue.MaskPivot = { 0, -30 };

		MainSpriteRenderer->CreateAnimation("Idle", "001.Idle", 0.1f, -1, -1, true);
		MainSpriteRenderer->CreateAnimation("Dash", "002.Dash", 0.1f, -1, -1, true);
		MainSpriteRenderer->CreateAnimation("Airborne", "003.Airborne", 0.1f, -1, -1, false);
		MainSpriteRenderer->CreateAnimation("Run", "005.Run", 0.1f, -1, -1, true);
		MainSpriteRenderer->CreateAnimation("Slash", "006.Slash", 0.1f, -1, -1, false);
		MainSpriteRenderer->CreateAnimation("UpSlash", "009.UpSlash", 0.1f, -1, -1, false);
		MainSpriteRenderer->CreateAnimation("DownSlash", "010.DownSlash", 0.1f, -1, -1, false);
		MainSpriteRenderer->CreateAnimation("Land", "011.Land", 0.1f, -1, -1, false);
		MainSpriteRenderer->CreateAnimation("HardLand", "012.HardLand", 0.1f, -1, -1, false);
		MainSpriteRenderer->CreateAnimation("LookDown", "013.LookDown", 0.1f, -1, -1, false);
		MainSpriteRenderer->CreateAnimation("LookUp", "014.LookUp", 0.1f, -1, -1, false);
		MainSpriteRenderer->CreateAnimation("Death", "017.Death", 0.1f, -1, -1, false);
		MainSpriteRenderer->CreateAnimation("Walk", "056.Walk", 0.1f, -1, -1, true);

		MainSpriteRenderer->AutoSpriteSizeOn();
	}

	{
		std::shared_ptr<GameEngineSpriteRenderer> FontRender = CreateComponent<GameEngineSpriteRenderer>(30);
		FontRender->SetText("돋움", "할로우 나이트", 50.0f, float4::BLUE, FW1_CENTER);
	}

	//{
	//	Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Player);
	//	Col->SetCollisionType(ColType::AABBBOX2D);
	//	Col->Transform.SetLocalPosition({ 0.0f, 0.0f, 0.0f });
	//	Col->Transform.SetLocalScale({60.0f, 130.0f, 0.0f}); // 여기
	//}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, 100.0f });

	GameEngineInput::AddInputObject(this);

	// GetLevel()->GetMainCamera()->CameraTargetSetting(Transform, float4::BACKWARD * 500.0f);

	{
		CreateStateParameter NewPara;

		// 한번만 실행되는 겁니다.
		NewPara.Init = [=](class GameEngineState* _Parent)
			{
				// MainSpriteRenderer->ChangeAnimation("Idle");
			};

		NewPara.Start = [=](class GameEngineState* _Parent)
			{
				MainSpriteRenderer->ChangeAnimation("Idle");
			};

		NewPara.Stay = [=](float _DeltaTime, class GameEngineState* _Parent)
			{
				if (GameEngineInput::IsPress('A', this))
				{
					MainSpriteRenderer->LeftFlip();
					_Parent->ChangeState(PlayerState::Walk);
				}

				if (GameEngineInput::IsPress('D', this))
				{
					MainSpriteRenderer->RightFlip();
					_Parent->ChangeState(PlayerState::Walk);
				}

				if (GameEngineInput::IsDown('C', this))
				{
					_Parent->ChangeState(PlayerState::Airborne);
				}

				if (GameEngineInput::IsDown('X', this))
				{
					_Parent->ChangeState(PlayerState::Slash);
				}
			};

		PlayerState.CreateState(PlayerState::Idle, NewPara);
	}

	{
		CreateStateParameter NewPara;

		NewPara.Start = [=](class GameEngineState* _Parent)
			{
				MainSpriteRenderer->ChangeAnimation("Walk");
			};

		NewPara.Stay = [=](float _DeltaTime, class GameEngineState* _Parent)
			{
				if (GameEngineInput::IsFree('A', this) && GameEngineInput::IsFree('D', this))
				{
					_Parent->ChangeState(PlayerState::Idle);
					return;
				}

				if (GameEngineInput::IsPress('A', this))
				{
					MainSpriteRenderer->LeftFlip();
					Transform.AddLocalPosition(float4::LEFT * _DeltaTime * MoveSpeed);
				}

				if (GameEngineInput::IsPress('D', this))
				{
					MainSpriteRenderer->RightFlip();
					Transform.AddLocalPosition(float4::RIGHT * _DeltaTime* MoveSpeed);
				}
			};

		PlayerState.CreateState(PlayerState::Walk, NewPara);
	}

	{
		CreateStateParameter NewPara;

		NewPara.Start = [=](class GameEngineState* _Parent)
			{
				MainSpriteRenderer->ChangeAnimation("Slash");
			};

		NewPara.Stay = [=](float _DeltaTime, class GameEngineState* _Parent)
			{
				if (true == MainSpriteRenderer->IsCurAnimationEnd())
				{
					_Parent->ChangeState(PlayerState::Idle);
					return;
				}

				if (GameEngineInput::IsPress('A', this))
				{
					MainSpriteRenderer->LeftFlip();
					_Parent->ChangeState(PlayerState::Walk);
				}

				if (GameEngineInput::IsPress('D', this))
				{
					MainSpriteRenderer->RightFlip();
					_Parent->ChangeState(PlayerState::Walk);
				}
			};

		PlayerState.CreateState(PlayerState::Slash, NewPara);
	}

	{
		CreateStateParameter NewPara;

		NewPara.Start = [=](class GameEngineState* _Parent)
			{
				MainSpriteRenderer->ChangeAnimation("Airborne");
			};

		NewPara.Stay = [=](float _DeltaTime, class GameEngineState* _Parent)
			{
				if (true == MainSpriteRenderer->IsCurAnimationEnd())
				{
					_Parent->ChangeState(PlayerState::Idle);
					return;
				}

				if (GameEngineInput::IsPress('A', this))
				{
					MainSpriteRenderer->LeftFlip();
					Transform.AddLocalPosition(float4::LEFT * _DeltaTime* MoveSpeed);
				}

				if (GameEngineInput::IsPress('D', this))
				{
					MainSpriteRenderer->RightFlip();
					Transform.AddLocalPosition(float4::RIGHT * _DeltaTime* MoveSpeed);
				}

				if (GameEngineInput::IsPress('C', this))
				{
					Transform.AddLocalPosition(float4::UP * _DeltaTime * 1000);
				}

				if (GameEngineInput::IsFree('C', this))
				{
					
				}
			};

		PlayerState.CreateState(PlayerState::Airborne, NewPara);
	}

	PlayerState.ChangeState(PlayerState::Idle);
}

void Player::Update(float _Delta)
{
	float4 ScreenPos = MainSpriteRenderer->GetScreenPosition();

	OutputDebugStringA(ScreenPos.ToString().c_str());

	PlayerState.Update(_Delta);

	//float Speed = 100.0f;

	//EventParameter Para;

	//Para.Enter = [](class GameEngineCollision* _This, class GameEngineCollision* _Other)
	//	{
	//		int a = 0;
	//	};

	//Para.Stay = [](class GameEngineCollision* _This, class GameEngineCollision* _Other)
	//	{
	//		int a = 0;
	//	};

	//Para.Exit = [](class GameEngineCollision* _This, class GameEngineCollision* _Other)
	//	{
	//		int a = 0;
	//	};

	//Col->CollisionEvent(ContentsCollisionType::Monster, Para);

	//if (GameEngineInput::IsPress('A', this))
	//{
	//	MainSpriteRenderer->LeftFlip();
	//	Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	//}

	//if (GameEngineInput::IsPress('D', this))
	//{
	//	MainSpriteRenderer->RightFlip();
	//	Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	//}

	//if (GameEngineInput::IsPress('W', this))
	//{
	//	Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	//}

	//if (GameEngineInput::IsPress('S', this))
	//{
	//	Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	//}

	//if (GameEngineInput::IsPress('Q', this))
	//{
	//	GetLevel()->GetMainCamera()->AddZoomValue(-_Delta);
	//	Transform.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });
	//}

	//if (GameEngineInput::IsPress('E', this))
	//{
	//	GetLevel()->GetMainCamera()->AddZoomValue(+_Delta);
	//	Transform.AddLocalRotation({ 0.0f, 0.0f, -360.0f * _Delta });
	//}

	GameEngineColor Color = PlayMap::MainMap->GetColor(Transform.GetWorldPosition(), GameEngineColor::RED);

	if (GameEngineColor::RED != Color)
	{
		GravityForce.Y -= _Delta * 500.0f;
		Transform.AddLocalPosition(GravityForce * _Delta);
	}
	else
	{
		GravityForce = 0.0f;
	}

	// 땅에 딱붙게하고 싶다면 while돌려서 올려주세요.
	// float4 Color = GetColor(Transform.GetWorldPosition());
}