#include "FileProcessCommands.hpp"
#include "ObjectState.hpp"
#include "FileSystem.hpp"
#include "OnExit.hpp"
#include <iostream>

// --- ReloadLibrariesCommand ----------------------------------------------------------------------------------

GS::String IFCExportCommandV01::GetName () const
{
    return "IFCExport";
}

GS::ObjectState IFCExportCommandV01::Execute (const GS::ObjectState& /*parameters*/, GS::ProcessControl& /*processControl*/) const
{
    Zuru_Tech_AC::FileProcessv01::FileExportIFC* exporter = new Zuru_Tech_AC::FileProcessv01::FileExportIFC();
    GSErrCode lastError;
    GS::UniString filePath;
    GS::UniString translatorName;
    GS::UniString elementFilter;
    std::tie(lastError, filePath, translatorName, elementFilter) = exporter->SaveFile();

    if (lastError != NoError) {
        return CreateErrorResponse(lastError, "Failed to save file as IFC");
    }

    GS::ObjectState response;
    response.Add("filePath",            filePath);
    response.Add("exportTranslator",    translatorName);
    response.Add("exportElementFilter", elementFilter);

    delete exporter;
    return response;
}

bool IFCExportCommandV01::IsUsingCommonSchemaDefinitions() const
{
    return false;
}

GS::Optional<GS::UniString> IFCExportCommandV01::GetResponseSchema() const
{
    return R"({
        "type": "object",
        "properties": {
            "filePath": {
                "type": "string",
                "description": "Saved file path"
            },
            "exportTranslator": {
                "type": "string",
                "description": "Used export translator"
            },
            "exportElementFilter": {
                "type": "string",
                "description": "Used export element filter"
            }
        },
        "additionalProperties": false,
        "required": [
            "filePath",
            "exportTranslator",
            "exportElementFilter"
        ]
    })";
}