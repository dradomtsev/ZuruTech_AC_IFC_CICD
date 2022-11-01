#pragma once
//#include "pch.h"
//#include "FileExportBase.hpp"
//#include "FileTypes.hpp"
#include <iostream>

#include	"APIEnvir.h"
#include	"ACAPinc.h"		// also includes APIdefs.h
#include	"APICommon.h"	// Helper functions for Add-On development


//#include	"DGModule.hpp"

//#include "UniString.hpp"
//#include "APIdefs_Properties.h"

//#include "Definitions.hpp"
//#include	"DGNativeContexts.hpp"

//#include	"NativeImage.hpp"

//#define ZURUTECHACIFC_EXPORT
//
//#ifdef ZURUTECHACIFC_EXPORT
//#define ZURUTECHACIFC_API __declspec(dllexport)
//#else
//#define ZURUTECHACIFC_API __declspec(dllimport)
//#endif

namespace Zuru_Tech_AC
{
    //GSErrCode errLast = NoError;
	//template <class T>
	//class ZURUTECHACIFC_API FileExporter
	//{
	//public:
	//	virtual void SaveFile();
	//	virtual ~FileExporter();
	//};

	//template<>
	//class ZURUTECHACIFC_API FileExporter <fileTypeIFC>
	//{
	//public:
	//	virtual void SaveFile();
	//	virtual ~FileExporter();
	//};

	namespace FileProcessv01
	{
		class FileExportIFC// : public FileExportBase//: public FileExporter <fileTypeIFC>
		{
		public:
            FileExportIFC() {};
            ~FileExportIFC() {};
            void SaveFile();
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
            void SaveFile(IO::Location pathOutputIFCFile);
            //virtual ~FileExportIFC();
        };
    }

    //static IO::Location GetSpecialFolderLocation(API_SpecFolderID id);
}