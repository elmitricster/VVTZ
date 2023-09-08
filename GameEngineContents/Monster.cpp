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
	{
		Renderer = CreateComponent<GameEngineSpriteRenderer>(30);

		GameEngineRandom NewRandom;

		NewRandom.SetSeed(reinterpret_cast<long long>(this));

		Renderer->SetSprite("KOKOMI2.png");
		//Renderer->Transform.SetLocalScale(NewRandom.RandomVectorBox2D(10, 100, 10, 100));
	}

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster);
		Col->Transform.SetLocalScale(Renderer->Transform.GetLocalScale());
	}
}
