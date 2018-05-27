#include "stdafx.h"

// Includes

// General
#include "WMOsManager.h"

// Additional
#include "Wmo.h"

WMOsManager::WMOsManager()
{
	ADDCONSOLECOMMAND_CLASS("wmo_info", WMOsManager, PrintAllInfo);

	CBaseManager::instance()->RegisterManager(Managers::MgrWMO, this);
}

WMOsManager::~WMOsManager()
{
	Log::Info("WMOsManager[]: All WMOs destroyed.");
}

WMO* WMOsManager::CreateAction(cstring name)
{
	WMO* _wmo = new WMO(name);
	if (!_wmo->Load())
	{
		Log::Error("WMOsManager[%s]: Failed init WMO.", name.c_str());
	}
	return _wmo;
}

bool WMOsManager::DeleteAction(cstring name)
{
	return true;
}