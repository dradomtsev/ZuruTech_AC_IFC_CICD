#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"		// also includes APIdefs.h
#include "APICommon.h"	// Helper functions for Add-On development
#include "RS.hpp"

namespace Zuru_Tech_AC
{
    class Helpers
    {
    public:
        Helpers() {};
        ~Helpers() {};
        static IO::Location GetSpecialFolderLocation(API_SpecFolderID id);
        /*static GS::UniString GetProjectName();*/
    };
}


