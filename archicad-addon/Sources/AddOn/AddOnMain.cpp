#include "APIEnvir.h"
#include "ACAPinc.h"

#include "ResourceIds.hpp"
#include "DGModule.hpp"

#include "UI.hpp"
#include "UI_Handler.hpp"
#include "FileExportIFC.hpp"

API_AddonType __ACDLL_CALL CheckEnvironment (API_EnvirParams* envir)
{
	RSGetIndString (&envir->addOnInfo.name, AddOnInfoID, AddOnNameID, ACAPI_GetOwnResModule ());
	RSGetIndString (&envir->addOnInfo.description, AddOnInfoID, AddOnDescriptionID, ACAPI_GetOwnResModule ());

	return APIAddon_Normal;
}

GSErrCode __ACDLL_CALL RegisterInterface (void)
{
	return ACAPI_Register_Menu (AddOnMenuID, 0, MenuCode_UserDef, MenuFlag_Default);
}

GSErrCode __ACENV_CALL Initialize (void)
{
	return ACAPI_Install_MenuHandler (AddOnMenuID, Zuru_Tech_AC::UIHandler::MenuCommandHandler);
}

GSErrCode __ACENV_CALL FreeData (void)
{
	return NoError;
}
