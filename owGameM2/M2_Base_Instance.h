#pragma once

#include "M2.h"

class CM2_Base_Instance : public SceneNodeModel3D
{
public:
	CM2_Base_Instance(std::string _m2Name);
	virtual ~CM2_Base_Instance();

	void CreateInstances();

	// CM2_Base_Instance
	void setM2(std::shared_ptr<M2> _model);
	std::shared_ptr<M2> getM2() const { return m_M2; }

	void Attach(std::shared_ptr<const CM2_Part_Attachment> _attachment);
	void Detach();

	// Color & Alpha
	void setColor(vec4 _color) { m_Color = _color; }
	cvec4 getColor() const { return m_Color; }
	void setAlpha(float _alpha) { m_Alpha = _alpha; }
	float getAlpha() const { return m_Alpha; }

	// Mesh & textures provider
	virtual bool                          isMeshEnabled(uint32 _index) const;
	void                                  setSpecialTexture(SM2_Texture::Type _type, cstring _textureName);
	void                                  setSpecialTexture(SM2_Texture::Type _type, std::shared_ptr<Texture> _texture);
	std::shared_ptr<Texture>              getSpecialTexture(SM2_Texture::Type _type) const;

	// Animations
	std::shared_ptr<CM2_Animator> getAnimator() const { return m_Animator; }

	// ILoadable
	bool Load() override;
	bool Delete() override;
	uint32 getPriority() const override { return 3; };

	// SceneNode3D
	virtual bool Accept(IVisitor& visitor) override;

protected:
	void InitAnimator();

	// SceneNode3D
	virtual void UpdateLocalTransform() override;
	virtual void UpdateBounds() override;

private:
	// Color & Alpha
	vec4                            m_Color;
	float                           m_Alpha;

	// Mesh & Replaces textures
	std::shared_ptr<Texture>		m_SpecialTextures[SM2_Texture::Type::COUNT];

	// Animtion
	std::shared_ptr<CM2_Animator>   m_Animator;
	bool                            m_NeedRecalcAnimation;

private:
	std::shared_ptr<M2>                             m_M2;
	std::string                                     m_M2Name;
	std::shared_ptr<const CM2_Part_Attachment>      m_Attached;
	const CGroupQuality&							m_QualitySettings;
};