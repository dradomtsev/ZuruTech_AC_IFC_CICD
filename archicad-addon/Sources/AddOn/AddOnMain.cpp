#include "APIEnvir.h"
#include "ACAPinc.h"

#include "ResourceIds.hpp"
#include "DGModule.hpp"

#include "UI.hpp"
#include "UI_Handler.hpp"
#include "FileExportIFC.hpp"
#include "FileProcessCommands.hpp"

API_AddonType __ACDLL_CALL CheckEnvironment (API_EnvirParams* envir)
{
	RSGetIndString (&envir->addOnInfo.name, AddOnInfoID, AddOnNameID, ACAPI_GetOwnResModule ());
	RSGetIndString (&envir->addOnInfo.description, AddOnInfoID, AddOnDescriptionID, ACAPI_GetOwnResModule ());

	return APIAddon_Preload;
}

GSErrCode __ACDLL_CALL RegisterInterface (void)
{
	return ACAPI_Register_Menu (AddOnMenuID, 0, MenuCode_UserDef, MenuFlag_Default);
}

GSErrCode __ACENV_CALL Initialize (void)
{
    GSErrCode lastError = NoError;
    lastError  |= ACAPI_Install_MenuHandler         (AddOnMenuID, Zuru_Tech_AC::UIHandler::MenuCommandHandler);
    lastError  |= ACAPI_Install_AddOnCommandHandler (GS::NewOwned<IFCExportCommandV01>());
    return lastError;
}

GSErrCode __ACENV_CALL FreeData (void)
{
	return NoError;
}
