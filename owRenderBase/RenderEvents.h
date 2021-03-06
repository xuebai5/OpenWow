#pragma once

class Camera;
class PipelineState;
struct Viewport;

class UpdateEventArgs : public EventArgs
{
	typedef EventArgs base;
public:
	UpdateEventArgs(const Object& caller, float fDeltaTime, float fTotalTime)
		: base(caller)
		, ElapsedTime(fDeltaTime)
		, TotalTime(fTotalTime)
	{}

	float ElapsedTime;
	float TotalTime;
};
typedef Delegate<UpdateEventArgs> UpdateEvent;



class RenderEventArgs : public EventArgs
{
	typedef EventArgs base;
public:
	RenderEventArgs(const Object& caller, float fDeltaTime, float fTotalTime, uint64_t frameCounter)
		: base(caller)
		, ElapsedTime(fDeltaTime)
		, TotalTime(fTotalTime)
		, FrameCounter(frameCounter)
	{}

	float ElapsedTime;
	float TotalTime;
	int64_t FrameCounter;
};
typedef Delegate<RenderEventArgs> RenderEvent;


// 3D render args
class Render3DEventArgs : public RenderEventArgs
{
	typedef RenderEventArgs base;
public:
	Render3DEventArgs(const Object& caller, float fDeltaTime, float fTotalTime, uint64_t frameCounter, const Camera* camera = nullptr, const PipelineState* pipelineState = nullptr, const Object* node = nullptr)
		: base(caller, fDeltaTime, fTotalTime, frameCounter)
		, Camera(camera)
		, PipelineState(pipelineState)
		, Node(node)
	{}

	const Camera* Camera;
	const PipelineState* PipelineState;
	const Object* Node;
};
typedef Delegate<Render3DEventArgs> Render3DEvent;


// UI Event args
class RenderUIEventArgs : public RenderEventArgs
{
	typedef RenderEventArgs base;
public:
	RenderUIEventArgs(const Object& caller, float fDeltaTime, float fTotalTime, uint64_t frameCounter, const Viewport* viewport = nullptr)
		: base(caller, fDeltaTime, fTotalTime, frameCounter)
		, Viewport(viewport)
	{}

	const Viewport* Viewport;
};
typedef Delegate<RenderUIEventArgs> RenderUIEvent;



class UserEventArgs : public EventArgs
{
	typedef EventArgs base;
public:
	UserEventArgs(const Object& caller, int code, void* data1, void* data2)
		: base(caller)
		, Code(code)
		, Data1(data1)
		, Data2(data2)
	{}

	int     Code;
	void*   Data1;
	void*   Data2;
};
typedef Delegate<UserEventArgs> UserEvent;