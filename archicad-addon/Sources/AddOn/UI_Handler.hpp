#pragma once
#include "ACAPinc.h"
#include "FileExportIFC.hpp"

namespace Zuru_Tech_AC
{
	class UIHandler
	{
	public:
		UIHandler() {};
		~UIHandler() {};
		static GSErrCode MenuCommandHandler(const API_MenuParams* menuParams);
	};
}

