#include "stdafx.h"
#include "CNodeQWORD.h"

CNodeQWORD::CNodeQWORD()
{
	m_nodeType = nt_uint64;
}

void CNodeQWORD::Update(CHotSpot & Spot)
{
	StandardUpdate(Spot);
	DWORD64 v = _ttoi64(Spot.Text.GetString());
	if (Spot.ID == 0)
		ReClassWriteMemory((LPVOID)Spot.Address, &v, sizeof(unsigned long long));
}

int CNodeQWORD::Draw(ViewInfo & View, int x, int y)
{
	if (m_bHidden)
		return DrawHidden(View, x, y);

	DWORD64* pMemory = (DWORD64*)&View.pData[m_Offset];
	AddSelection(View, 0, y, g_FontHeight);
	AddDelete(View, x, y);
	AddTypeDrop(View, x, y);
	//AddAdd(View,x,y);

	int tx = x + TXOFFSET;
	tx = AddIcon(View, tx, y, ICON_UNSIGNED, HS_NONE, HS_NONE);
	tx = AddAddressOffset(View, tx, y);
	tx = AddText(View, tx, y, crType, HS_NONE, _T("QWORD "));
	tx = AddText(View, tx, y, crName, HS_NAME, _T("%s"), m_strName);
	tx = AddText(View, tx, y, crName, HS_NONE, _T(" = "));
	tx = AddText(View, tx, y, crValue, HS_EDIT, _T("%llu"), pMemory[0]) + g_FontWidth;
	tx = AddComment(View, tx, y);

	return y += g_FontHeight;
}
