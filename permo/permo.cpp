
// permo.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "permo.h"
#include "permoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpermoApp

BEGIN_MESSAGE_MAP(CpermoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CpermoApp ����

CpermoApp::CpermoApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴����ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CpermoApp ����

CpermoApp theApp;


// CpermoApp ��ʼ��

BOOL CpermoApp::InitInstance()
{
	m_hMutex = CreateMutex(NULL, TRUE, _T("permo"));
	// ����Ƿ��Ѿ�����Mutex
	// ����Ѿ�����������ֹ���̵�����
	if ((m_hMutex != NULL) && (GetLastError() == ERROR_ALREADY_EXISTS))
	{
		ReleaseMutex(m_hMutex);
		AfxMessageBox(_T("�ף������Ѿ���������:)"));
		return FALSE;
	}
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();



	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CpermoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO:  �ڴ˷��ô�����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO:  �ڴ˷��ô�����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
	}


	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}



int CpermoApp::ExitInstance()
{
	// TODO:  �ڴ�����ר�ô����/����û���

	if (m_hMutex != NULL)
	{
		ReleaseMutex(m_hMutex);
		CloseHandle(m_hMutex);
	}

	return CWinApp::ExitInstance();
}