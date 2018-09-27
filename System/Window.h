#pragma once
class Window
{
public:
	Window(HINSTANCE instance);
	~Window();

	void Create();
	WPARAM Run();
protected:
	virtual void Initialize() = 0;
	virtual void Destroy() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	HINSTANCE instance;
	HWND winHandle;
};

