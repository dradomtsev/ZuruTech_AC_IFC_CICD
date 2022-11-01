#include "Helpers.h"

IO::Location Zuru_Tech_AC::Helpers::GetSpecialFolderLocation(API_SpecFolderID id)
{
    IO::Location folder;
    ACAPI_Environment(APIEnv_GetSpecFolderID, &id, &folder);
    return folder;
}

//GS::UniString GetProjectName()
//{
//    GS::UniString projectName = RSGetIndString(AddOnPropStrsID, UntitledID, ACAPI_GetOwnResModule());
//
//    API_ProjectInfo projectInfo = {};
//    GSErrCode err = ACAPI_Environment(APIEnv_ProjectID, &projectInfo);
//    if (err != NoError || projectInfo.untitled || projectInfo.projectName == nullptr) {
//        return projectName;
//    }
//
//    return *projectInfo.projectName;
//}