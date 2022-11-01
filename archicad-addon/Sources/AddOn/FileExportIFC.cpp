//#include "pch.h"
#include "FileExportIFC.hpp"
#include "Helpers.h"
#include <iostream>

#include	"APIEnvir.h"
#include	"ACAPinc.h"		// also includes APIdefs.h
#include	"APICommon.h"	// Helper functions for Add-On development

void Zuru_Tech_AC::FileExportIFC::SaveFile(IO::Location pathOutputIFCFile)
{
    API_IFCTranslatorIdentifier ifcExportTranslatorFirst;			// First IFC export translator in list
    //std::multimap<GS::UniString,API_IFCTranslatorIdentifier> ifcExportTranslators_multimap;
    GS::Array<API_IFCTranslatorIdentifier> ifcExportTranslators;	// List of IFC export translators
    GSErrCode errLast;
    errLast = ACAPI_IFC_GetIFCExportTranslatorsList(ifcExportTranslators); // Get translators list
    if (errLast != NoError)
    {
        WriteReport("Can't get IFC export translator");
    }

    // Check IFC export translators list
    if (DBVERIFY(!ifcExportTranslators.IsEmpty())) {
        ifcExportTranslatorFirst = ifcExportTranslators.GetFirst();
    }

    // Set parameters to save the current project as an Ifc file.
    API_SavePars_Ifc paramsSaveIFC = {};     // Init IFC save parameters
    paramsSaveIFC.subType = API_IFC;    // set IFC file type to "IFC". Selected from enum "API_IfcTypeID"
    paramsSaveIFC.translatorIdentifier = ifcExportTranslatorFirst;  // Use specific IFC export translator
    paramsSaveIFC.elementsToIfcExport = API_EntireProject;          // Select element group fronm enum "API_ElementsToIfcExportID"
    paramsSaveIFC.elementsSet = nullptr; // use only when the elementsToIfcExport is set API_FilteredElements

    // Set parameters to save the current project file.
    API_FileSavePars paramsSaveFile = {}; // Init file save parameters
    paramsSaveFile.fileTypeID = APIFType_IfcFile; // Choose file type from enum "API_FTypeID"
    //IO::Location pathOutputIFCFile(Zuru_Tech_AC::Helpers::GetSpecialFolderLocation(API_UserDocumentsFolderID), IO::Name("Zuru.Tech-TestIFC-ExportFromAddon.ifc")); // Get specific location. As an example - User document folder
    paramsSaveFile.file = &pathOutputIFCFile; // Setup folder location for file output

    // Call automation function with parameters for file saving
    errLast = ACAPI_Automate(APIDo_SaveID, &paramsSaveFile, &paramsSaveIFC); // USe APIDo_SaveID automation code from enum "API_AutomateID"
    if (errLast != NoError) {
        //ACAPI_WriteReport("Error in ACAPI_Automate(APIDo_SaveID,...) (IFC): %s", true, ErrID_To_Name(errLast));
        ACAPI_WriteReport("Error in ACAPI_Automate(APIDo_SaveID,...) (IFC)", true, "IFC saving error");
    }
};

void Zuru_Tech_AC::FileProcessv01::FileExportIFC::SaveFile()
{
    API_IFCTranslatorIdentifier ifcExportTranslatorFirst;			// First IFC export translator in list
    //std::multimap<GS::UniString,API_IFCTranslatorIdentifier> ifcExportTranslators_multimap;
    GS::Array<API_IFCTranslatorIdentifier> ifcExportTranslators;	// List of IFC export translators
    GSErrCode errLast;
    errLast = ACAPI_IFC_GetIFCExportTranslatorsList(ifcExportTranslators); // Get translators list
    if (errLast != NoError)
    {
        WriteReport("Can't get IFC export translator");
    }

    // Check IFC export translators list
    if (DBVERIFY(!ifcExportTranslators.IsEmpty())) {
        ifcExportTranslatorFirst = ifcExportTranslators.GetFirst();
    }

    // Set parameters to save the current project as an Ifc file.
    API_SavePars_Ifc paramsSaveIFC = {};     // Init IFC save parameters
    paramsSaveIFC.subType = API_IFC;    // set IFC file type to "IFC". Selected from enum "API_IfcTypeID"
    paramsSaveIFC.translatorIdentifier = ifcExportTranslatorFirst;  // Use specific IFC export translator
    paramsSaveIFC.elementsToIfcExport = API_EntireProject;          // Select element group fronm enum "API_ElementsToIfcExportID"
    paramsSaveIFC.elementsSet = nullptr; // use only when the elementsToIfcExport is set API_FilteredElements

    // Set parameters to save the current project file.
    API_FileSavePars paramsSaveFile = {}; // Init file save parameters
    paramsSaveFile.fileTypeID = APIFType_IfcFile; // Choose file type from enum "API_FTypeID"
    IO::Location pathOutputIFCFile(Zuru_Tech_AC::Helpers::GetSpecialFolderLocation(API_UserDocumentsFolderID), IO::Name("Zuru.Tech-TestIFC-ExportFromAddon.ifc")); // Get specific location. As an example - User document folder
    paramsSaveFile.file = &pathOutputIFCFile; // Setup folder location for file output

    // Call automation function with parameters for file saving
    errLast = ACAPI_Automate(APIDo_SaveID, &paramsSaveFile, &paramsSaveIFC); // USe APIDo_SaveID automation code from enum "API_AutomateID"
    if (errLast != NoError) {
        //ACAPI_WriteReport("Error in ACAPI_Automate(APIDo_SaveID,...) (IFC): %s", true, ErrID_To_Name(errLast));
        ACAPI_WriteReport("Error in ACAPI_Automate(APIDo_SaveID,...) (IFC)", true, "IFC saving error");
    }
};

//static IO::Location Zuru_Tech_AC::GetSpecialFolderLocation(API_SpecFolderID id)
//{
//    IO::Location folder;
//    ACAPI_Environment(APIEnv_GetSpecFolderID, &id, &folder);
//    return folder;
//}