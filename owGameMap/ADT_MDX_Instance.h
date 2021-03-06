﻿#pragma once

struct ADT_MDXDef
{
	uint32 nameIndex;
	uint32 uniqueId;
	vec3 position;
	vec3 rotation;
	uint16 scale;
    struct
    {
        uint16 Flag_Biodome : 1;
        uint16 Flag_Shrubbery : 1;
        uint16 : 14;
    } flags;
};

class ADT_MDX_Instance : public CM2_Base_Instance
{
public:
	ADT_MDX_Instance(std::string _m2Name, const ADT_MDXDef& _placementInfo);
	virtual ~ADT_MDX_Instance();

	// SceneNode3D
	bool Accept(IVisitor& visitor) override;

public: 
	uint32				m_UniqueId;

public:	// Static
	static void reset();
private:
	static std::set<uint32> m_AlreadyDraw;
};
