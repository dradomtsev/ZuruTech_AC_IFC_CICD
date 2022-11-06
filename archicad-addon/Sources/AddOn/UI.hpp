#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"

#include "ResourceIds.hpp"
#include "DGModule.hpp"
#include "DG.h"
#include "DGSystemDialog.hpp"

static const GSResID AddOnInfoID = ID_ADDON_INFO;
static const Int32 AddOnNameID = 1;
static const Int32 AddOnDescriptionID = 2;

static const short AddOnMenuID = ID_UIIFCMainMenu;
static const Int32 AddOnCommandID = 1;

namespace Zuru_Tech_AC
{
	class [[deprecated("DG::FileDialog::Save used")]] UIIFCMainDialog : public DG::ModalDialog,
		public DG::PanelObserver,
		public DG::ButtonItemObserver,
		public DG::CompoundItemObserver
	{
	public:
		enum DialogResourceIds
		{
			DialogResourceId = ID_UIIFCMainDialog,
			OKButtonId = 1,
			CancelButtonId = 2,
			SeparatorId = 3
		};

		UIIFCMainDialog() :
			DG::ModalDialog(ACAPI_GetOwnResModule(), DialogResourceId, ACAPI_GetOwnResModule()),
			okButton(GetReference(), OKButtonId),
			cancelButton(GetReference(), CancelButtonId),
			separator(GetReference(), SeparatorId)
		{
			AttachToAllItems(*this);
			Attach(*this);
		}

		~UIIFCMainDialog();
	private:
		DG::Button		okButton;
		DG::Button		cancelButton;
		DG::Separator	separator;

		virtual void PanelResized(const DG::PanelResizeEvent& ev) override;
		virtual void ButtonClicked(const DG::ButtonClickEvent& ev) override;
	};
}



