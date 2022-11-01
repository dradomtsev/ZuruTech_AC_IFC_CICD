#include "APIEnvir.h"
#include "ACAPinc.h"

#include "ResourceIds.hpp"
#include "DGModule.hpp"

#include "UI.hpp"
#include "FileExportIFC.hpp"
//#include "fileTypes.hpp"
#include "Helpers.h"

Zuru_Tech_AC::UIIFCMainDialog::~UIIFCMainDialog()
{
	Detach(*this);
	DetachFromAllItems(*this);
}

void Zuru_Tech_AC::UIIFCMainDialog::PanelResized(const DG::PanelResizeEvent& ev)
{
	BeginMoveResizeItems();
	okButton.Move(ev.GetHorizontalChange(), ev.GetVerticalChange());
	cancelButton.Move(ev.GetHorizontalChange(), ev.GetVerticalChange());
	separator.MoveAndResize(0, ev.GetVerticalChange(), ev.GetHorizontalChange(), 0);
	EndMoveResizeItems();
}

void Zuru_Tech_AC::UIIFCMainDialog::ButtonClicked(const DG::ButtonClickEvent& ev)
{
	Zuru_Tech_AC::FileProcessv01::FileExportIFC *exporter = new Zuru_Tech_AC::FileProcessv01::FileExportIFC();
	//Zuru_Tech_AC::FileExportIFC* exporter = Zuru_Tech_AC::createFileExportIFC();
	if (ev.GetSource() == &okButton) {
		
		exporter->SaveFile();
		PostCloseRequest(DG::ModalDialog::Accept);
	}
	else if (ev.GetSource() == &cancelButton) {
		PostCloseRequest(DG::ModalDialog::Cancel);
	}
	delete exporter;
}