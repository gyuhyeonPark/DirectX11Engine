#include "Engine.h"
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "DirectXTK.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrecInstance,
	_In_ LPWSTR		lpCmdLine,
	_In_ int		nCmdShow)
{
#pragma region 에러 추적 예시
	//HRESULT hr = E_INVALIDARG;
	//HRESULT hr = S_OK;
	//if (SUCCEEDED(hr))
	//{
	//	MessageBoxA(NULL, "SUCCESS", "SUCCESS", NULL);
	//}
	//if (FAILED(hr))
	//{
	//	ErrorLogger::Log(hr, "FAILURE");
	//}
#pragma endregion

	Engine engine;
	engine.Initialize(hInstance, "Title", "MyWindowClass", 800, 600);

	while (engine.ProcessMessages() == true)
	{
		engine.Update();
	}

	return 0;
}