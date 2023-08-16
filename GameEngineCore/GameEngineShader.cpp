#include "PreCompile.h"
#include "GameEngineShader.h"

GameEngineShader::GameEngineShader()
{
}

GameEngineShader::~GameEngineShader()
{
}

void GameEngineShader::CreateVersion(ShaderType _Type, UINT _VersionHigh, UINT _VersionLow)
{
	ShaderTypeValue = _Type;

	switch (_Type)
	{
	case ShaderType::None:
	{
		MsgBoxAssert("���̴� Ÿ���� �߸����Խ��ϴ�.");
		break;
	}
	case ShaderType::Vertex:
		Version = "vs";
		break;
	case ShaderType::Pixel:
		Version = "ps";
		break;
	case ShaderType::Max:
	{
		MsgBoxAssert("���̴� Ÿ���� �߸����Խ��ϴ�.");
		break;
	}
	default:
		break;
	}

	Version += "_";
	Version += std::to_string(_VersionHigh); // 5
	Version += "_";
	Version += std::to_string(_VersionLow); // 5

	// "vs_5_0"
}