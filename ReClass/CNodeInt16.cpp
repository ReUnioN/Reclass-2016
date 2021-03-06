#include "stdafx.h"
#include "CNodeInt16.h"

CNodeInt16::CNodeInt16()
{
	m_nodeType = nt_int16;
}

void CNodeInt16::Update(CHotSpot & Spot)
{
	StandardUpdate(Spot);
	__int16 v = _ttoi(Spot.Text.GetString());
	if (Spot.ID == 0)
		ReClassWriteMemory((LPVOID)Spot.Address, &v, sizeof(short));
}

int CNodeInt16::Draw(ViewInfo & View, int x, int y)
{
	if (m_bHidden)
		return DrawHidden(View, x, y);

	__int16* pMemory = (__int16*)&View.pData[m_Offset];
	AddSelection(View, 0, y, g_FontHeight);
	AddDelete(View, x, y);
	AddTypeDrop(View, x, y);
	//AddAdd(View,x,y);

	int tx = x + TXOFFSET;
	tx = AddIcon(View, tx, y, ICON_INTEGER, HS_NONE, HS_NONE);
	tx = AddAddressOffset(View, tx, y);
	tx = AddText(View, tx, y, crType, HS_NONE, _T("Int16 "));
	tx = AddText(View, tx, y, crName, HS_NAME, _T("%s"), m_strName);
	tx = AddText(View, tx, y, crName, HS_NONE, _T(" = "));
	tx = AddText(View, tx, y, crValue, HS_EDIT, _T("%i"), pMemory[0]) + g_FontWidth;
	tx = AddComment(View, tx, y);

	return y += g_FontHeight;
}
