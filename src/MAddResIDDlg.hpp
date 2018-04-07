// MAddResIDDlg.hpp --- "Add Resource ID" Dialog
//////////////////////////////////////////////////////////////////////////////
// RisohEditor --- Another free Win32 resource editor
// Copyright (C) 2017-2018 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////////////

#ifndef MZC4_MADDRESIDDLG_HPP_
#define MZC4_MADDRESIDDLG_HPP_

#include "MWindowBase.hpp"
#include "ConstantsDB.hpp"
#include "Res.hpp"
#include "resource.h"
#include "RisohSettings.hpp"

std::vector<INT> GetPrefixIndexes(RisohSettings& settings, ConstantsDB& db, const MString& prefix);
void ReplaceFullWithHalf(MStringW& strText);

//////////////////////////////////////////////////////////////////////////////

class MAddResIDDlg : public MDialogBase
{
public:
    RisohSettings& m_settings;
    ResEntries& m_entries;
    ConstantsDB& m_db;
    MString m_str1;
    MString m_str2;
    BOOL m_bChanging;

    MAddResIDDlg(RisohSettings& settings, ResEntries& entries, ConstantsDB& db)
        : MDialogBase(IDD_ADDRESID), m_settings(settings), m_entries(entries), m_db(db)
    {
        m_bChanging = FALSE;
    }

    BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
    {
        ConstantsDB::TableType table;
        table = m_db.GetTable(L"RESOURCE.ID.TYPE");

        const INT IDTYPE_default = IDTYPE_COMMAND;

        INT i = 0;
        ConstantsDB::TableType::iterator it, end = table.end();
        for (it = table.begin(); it != end; ++it)
        {
            INT k = (INT)SendDlgItemMessage(hwnd, cmb1, CB_ADDSTRING, 0, (LPARAM)it->name.c_str());
            if (k == IDTYPE_default)
            {
                m_bChanging = TRUE;
                SendDlgItemMessage(hwnd, cmb1, CB_SETCURSEL, k, 0);
                m_bChanging = FALSE;
            }
            ++i;
        }

        table = m_db.GetTable(L"RESOURCE.ID.PREFIX");
        m_bChanging = TRUE;
        SetDlgItemTextW(hwnd, edt1, table[IDTYPE_default].name.c_str());
        m_bChanging = FALSE;

        SendDlgItemMessage(hwnd, scr1, UDM_SETRANGE, 0, MAKELPARAM(SHRT_MAX, SHRT_MIN));

        CenterWindowDx();
        return TRUE;
    }

    void OnOK(HWND hwnd)
    {
        MString str1 = GetDlgItemText(hwnd, edt1);
        ReplaceFullWithHalf(str1);
        mstr_trim(str1);
        CharUpper(&str1[0]);
        if (str1.empty())
        {
            HWND hEdt1 = GetDlgItem(hwnd, edt1);
            Edit_SetSel(hEdt1, 0, -1);
            SetFocus(hEdt1);
            ErrorBoxDx(IDS_ENTERTEXT);
            return;
        }
        m_str1 = str1;

        MString str2 = GetDlgItemText(hwnd, edt2);
        ReplaceFullWithHalf(str2);
        mstr_trim(str2);
        if (str2.empty())
        {
            HWND hEdt2 = GetDlgItem(hwnd, edt2);
            Edit_SetSel(hEdt2, 0, -1);
            SetFocus(hEdt2);
            ErrorBoxDx(IDS_ENTERINT);
            return;
        }
        m_str2 = str2;

        MStringA str1a = MTextToAnsi(CP_ACP, str1).c_str();
        if (m_settings.id_map.find(str1a) != m_settings.id_map.end())
        {
            HWND hEdt1 = GetDlgItem(hwnd, edt1);
            Edit_SetSel(hEdt1, 0, -1);
            SetFocus(hEdt1);
            ErrorBoxDx(IDS_ALREADYEXISTS);
            return;
        }

        EndDialog(IDOK);
    }

    void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
    {
        switch (id)
        {
        case IDOK:
            OnOK(hwnd);
            break;
        case IDCANCEL:
            EndDialog(IDCANCEL);
            break;
        case edt1:
            if (codeNotify == EN_CHANGE && !m_bChanging)
            {
                MString name = GetDlgItemText(hwnd, edt1);
                mstr_trim(name);

                MString prefix = name.substr(0, name.find(L'_') + 1);

                std::vector<INT> indexes;
                indexes = GetPrefixIndexes(m_settings, m_db, prefix);
                if (indexes.empty() || indexes.size() >= 2)
                {
                    m_bChanging = TRUE;
                    SendDlgItemMessage(hwnd, cmb1, CB_SETCURSEL, -1, 0);
                    m_bChanging = FALSE;
                    break;
                }

                ConstantsDB::TableType table;
                table = m_db.GetTable(L"RESOURCE.ID.PREFIX");

                m_bChanging = TRUE;
                SendDlgItemMessage(hwnd, cmb1, CB_SETCURSEL, indexes[0], 0);
                m_bChanging = FALSE;
            }
            break;
        case cmb1:
            if (codeNotify == CBN_SELCHANGE && !m_bChanging)
            {
                HWND hCmb1 = GetDlgItem(hwnd, cmb1);
                INT k = INT(SendMessage(hCmb1, CB_GETCURSEL, 0, 0));
                if (k != -1)
                {
                    ConstantsDB::TableType table;
                    table = m_db.GetTable(L"RESOURCE.ID.PREFIX");

                    MString name = GetDlgItemText(hwnd, cmb1);
                    m_bChanging = TRUE;
                    SetDlgItemText(hwnd, edt1, table[k].name.c_str());
                    m_bChanging = FALSE;
                }
            }
            break;
        case psh1:
            {
                SetDlgItemTextW(hwnd, edt2, NULL);

                MString name = GetDlgItemText(hwnd, edt1);
                mstr_trim(name);

                MString prefix = name.substr(0, name.find(L'_') + 1);
                if (prefix.size())
                {
                    ConstantsDB::TableType table;
                    table = m_db.GetTableByPrefix(L"RESOURCE.ID", prefix);

                    UINT nMax = 0;
                    {
                        ConstantsDB::TableType::iterator it, end = table.end();
                        for (it = table.begin(); it != end; ++it)
                        {
                            if (it->name == L"IDC_STATIC")
                                continue;
                            if (nMax < it->value)
                                nMax = it->value;
                        }
                    }

                    INT nIDTYPE_ = IDTYPE_UNKNOWN;
                    {
                        assoc_map_type::iterator it, end = m_settings.assoc_map.end();
                        for (it = m_settings.assoc_map.begin(); it != end; ++it)
                        {
                            if (it->second == prefix)
                            {
                                nIDTYPE_ = INT(m_db.GetValue(L"RESOURCE.ID.TYPE", it->first));
                                break;
                            }
                        }
                    }

                    INT nNextID = nMax + 1;

                    switch (nIDTYPE_)
                    {
                    case IDTYPE_UNKNOWN:
                    case IDTYPE_MESSAGE:
                    case IDTYPE_WINDOW:
                        break;
                    default:
                        if (nNextID < 100)
                            nNextID = 100;
                        break;
                    }

                    SetDlgItemInt(hwnd, edt2, nNextID, TRUE);
                }
            }
            break;
        }
    }

    virtual INT_PTR CALLBACK
    DialogProcDx(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
            HANDLE_MSG(hwnd, WM_INITDIALOG, OnInitDialog);
            HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
        }
        return DefaultProcDx();
    }
};

//////////////////////////////////////////////////////////////////////////////

#endif  // ndef MZC4_MADDRESIDDLG_HPP_
