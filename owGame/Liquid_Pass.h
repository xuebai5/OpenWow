#pragma once

// A pass that renders the opaque geometry in the scene.
class Liquid_Pass : public BasePass
{
public:
	typedef BasePass base;

	Liquid_Pass(std::shared_ptr<Scene3D> scene, std::shared_ptr<PipelineState> pipeline);
	virtual ~Liquid_Pass();

	virtual bool Visit(IMesh& mesh);

protected:

private:
};