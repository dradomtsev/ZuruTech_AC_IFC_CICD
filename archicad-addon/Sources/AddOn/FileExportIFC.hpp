#pragma once
#include <iostream>

#include	"APIEnvir.h"
#include	"ACAPinc.h"		// also includes APIdefs.h
#include	"APICommon.h"	// Helper functions for Add-On development

namespace Zuru_Tech_AC
{
	namespace FileProcessv01
	{
		class FileExportIFC// : public FileExportBase//: public FileExporter <fileTypeIFC>
		{
		public:
            FileExportIFC() {};
            ~FileExportIFC() {};
            std::tuple<GSErrCode, GS::UniString, GS::UniString, GS::UniString> SaveFile();
			//virtual ~FileExportIFC();
		};
	}

    inline namespace FileProcessv02
    {
        class FileExportIFC// : public FileExportBase//: public FileExporter <fileTypeIFC>
        {
        public:
            FileExportIFC() {};
            ~FileExportIFC() {};
            void SaveFile(IO::Location pathOutputIFCFile, API_Guid& viewGuid, API_IFCTranslatorIdentifier& ifcExportTranslator);
            //virtual ~FileExportIFC();
        };
    }
}