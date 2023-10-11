#include "PreCompile.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}


void Monster::Start()
{
	GameEngineRandom NewRandom;
	NewRandom.SetSeed(reinterpret_cast<long long>(this));
	float4 Scale = NewRandom.RandomVectorBox2D(10, 100, 10, 100);

	{
		Renderer = CreateComponent<GameEngineSpriteRenderer>(30);
		Renderer->SetSprite("KOKOMI2.png");
		Renderer->SetImageScale(Scale);
	}

	{
		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster);
		Col->Transform.SetLocalScale(Scale);
	}
}
