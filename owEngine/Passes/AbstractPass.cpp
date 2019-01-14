#include <stdafx.h>

// General
#include "AbstractPass.h"

AbstractPass::AbstractPass()
	: m_Enabled(true)
{}

AbstractPass::~AbstractPass()
{}

// Enable or disable the pass. If a pass is disabled, the technique will skip it.
void AbstractPass::SetEnabled(bool enabled)
{
	m_Enabled = enabled;
}

bool AbstractPass::IsEnabled() const
{
	return m_Enabled;
}

// Render the pass. This should only be called by the RenderTechnique.
void AbstractPass::PreRender(RenderEventArgs& e)
{}

void AbstractPass::Render(RenderEventArgs& e)
{}

void AbstractPass::PostRender(RenderEventArgs& e)
{}


// Inherited from Visitor

bool AbstractPass::Visit(SceneNode& node)
{
	return false;
}

bool AbstractPass::Visit(UINode& node)
{
	return false;
}

bool AbstractPass::Visit(IMesh& mesh)
{
	return false;
}
