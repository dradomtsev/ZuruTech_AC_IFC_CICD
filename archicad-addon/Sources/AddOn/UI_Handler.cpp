#include "UI.hpp"
#include "UI_Handler.hpp"
#include "Helpers.h"
#include "ACAPinc.h"
#include "DG.h"
#include "DGSystemDialog.hpp"


GSErrCode Zuru_Tech_AC::UIHandler::MenuCommandHandler(const API_MenuParams* menuParams)
{
	switch (menuParams->menuItemRef.menuResID) {
	case AddOnMenuID:
		switch (menuParams->menuItemRef.itemIndex) {
		case AddOnCommandID:
		{
            DG::FileDialog diagSaveFile(DG::FileDialog::Save); // Create standard Save dialog
            FTM::FileTypeManager fileTypeManager("ifcFileManager"); // Init file type manager for type checking

            // Setup default folder for "Save" dilaog
            IO::Location pathOutputIFCFolder(Zuru_Tech_AC::Helpers::GetSpecialFolderLocation(API_UserDocumentsFolderID));

            // Init file extensions and text to show in dialog drop-down panel
            const char* fileExtensIFC = "ifc";
            const GS::UniString& filterTextIFC = "IFC files(*.ifc)";

            // const char* fileExtensIFCXML = "ifcxml";
            // const GS::UniString& filterTextIFCXML = "IFC XML files(*.ifcxml)";

            // Init file types
            FTM::FileType typeIFC   (nullptr, fileExtensIFC, 0, 0, 0);
            //FTM::FileType typeIFCXML(nullptr, fileExtensIFCXML, 0, 0, 0);

            // Check file types for compability
            FTM::TypeID	idIFC       = FTM::FileTypeManager::SearchForType(typeIFC);
            //FTM::TypeID	idIFCXML    = FTM::FileTypeManager::SearchForType(typeIFCXML);

            // Add file type to file manager
            if (idIFC == FTM::UnknownType) // || idIFCXML == FTM::UnknownType)
            {
                idIFC = fileTypeManager.AddType(typeIFC);
                //idIFCXML = fileTypeManager.AddType(typeIFCXML);
            }
            
            UIndex UIdIFC = diagSaveFile.AddFilter(idIFC, DG::FileDialog::DisplayExtensions); // Add file extension filter in "Save" dialog

            // Setup dialog
            diagSaveFile.EnablePreview();
            diagSaveFile.SetFilterText(UIdIFC, filterTextIFC);
            diagSaveFile.SetTitle("Save as IFC...");
            diagSaveFile.SetFolder(pathOutputIFCFolder);

            // Setup file name and full path
            IO::Location pathOutputIFCFile = diagSaveFile.GetSelectedFolder();
            pathOutputIFCFile.AppendToLocal(IO::Name("Zuru.Tech-TestIFC-ExportFromAddon"));
            diagSaveFile.SelectFile(pathOutputIFCFile);

            // Call "Save" dialog. Check if diagSaveFile was cancelled
            if (!diagSaveFile.Invoke())
                return NoError;

            // Get last file location
            IO::Location location = diagSaveFile.GetSelectedFile();

            // Call file saver function
            Zuru_Tech_AC::FileExportIFC* exporter = new Zuru_Tech_AC::FileExportIFC();
            exporter->SaveFile(location);
            delete exporter;
            
            // Simple dialog, first iteration
			//UIIFCMainDialog dialog;
			//dialog.Invoke();
		}
		break;
		}
		break;
	}
	return NoError;
}