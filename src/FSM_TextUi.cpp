#include "FSM_TextUi.h"
#include "framework_controler.h"

#include <iostream>
using namespace std;

FSM_TextUi::FSM_TextUi(void)
{
	m_framework = new framework_controler(this);
}

FSM_TextUi::~FSM_TextUi(void)
{
  delete m_framework;
}

void FSM_TextUi::run(void)
{
	unsigned int l_result = 0;
	bool l_continu = true;
	while(l_continu)
	{
		l_result = displayMenu();
		switch(l_result)
		{
			case 1:
			{
				cout << " Enter library ?" << endl;
				string l_library ;
				cin >> l_library;
				m_framework->loadLibrary(l_library);
			}
			break;
			case 2:
			{
				cout << " Enter fsm name ?" << endl;
				string l_fsm ;
				cin >> l_fsm;
				m_framework->selectFsm(l_fsm);
			}
			break;
			case 3:
			{
				cout << " Enter fsm ui name ?" << endl;
				string l_fsm_ui ;
				cin >> l_fsm_ui;
				m_framework->selectFsmUi(l_fsm_ui);
			}
			break;
			case 4:
			{
				cout << " Enter algorithm name ?" << endl;
				string l_algorithm ;
				cin >> l_algorithm;
				m_framework->selectAlgorithm(l_algorithm);
			}
			break;
			case 5:
				m_framework->run();
			break;
			case 6:
				l_continu = false;
			break;
		}
	}
}

unsigned int FSM_TextUi::displayMenu(void)
{
	unsigned int l_result = 0;
	cout << "-------------------------------" << endl ;
	cout << "1 - Load Library" << endl ;
	cout << "2 - Select FSM" << endl ;
	cout << "3 - Select FSM_UI" << endl ;
	cout << "4 - Select Algorithm" << endl ;
	cout << "5 - Run" << endl ;
	cout << "6 - Exit" << endl ;
	cout << "-------------------------------" << endl ;
	cin >> l_result;
	return l_result;
}


void FSM_TextUi::displayLoadedFsm(vector<string> *p_fsm_list)
{
	cout << endl <<  "Loaded FSMs : " << endl;
	vector<string>::iterator l_iter = p_fsm_list->begin();
	vector<string>::iterator l_iter_end = p_fsm_list->end();
	while(l_iter != l_iter_end)
	{
		cout << *l_iter << endl;
		l_iter++;
	}
	cout << "---------------" << endl << endl ;
}

void FSM_TextUi::displayLoadedFsmUi(vector<string> *p_fsm_ui_list)
{
	cout << endl <<  "Loaded FSM_UIs : " << endl;
	vector<string>::iterator l_iter = p_fsm_ui_list->begin();
	vector<string>::iterator l_iter_end = p_fsm_ui_list->end();
	while(l_iter != l_iter_end)
	{
		cout << *l_iter << endl;
		l_iter++;
	}
	cout << "---------------" << endl << endl ;
}

void FSM_TextUi::displayLoadedAlgorithm(vector<string> *p_algorithm_list)
{
	cout << endl <<  "Loaded algorithm : " << endl;
	vector<string>::iterator l_iter = p_algorithm_list->begin();
	vector<string>::iterator l_iter_end = p_algorithm_list->end();
	while(l_iter != l_iter_end)
	{
		cout << *l_iter << endl;
		l_iter++;
	}
	cout << "---------------" << endl << endl ;
}

void FSM_TextUi::displayWarningMessage(string p_message)
{
	cout << "WARNING : " << p_message << endl ;
}

void FSM_TextUi::displayErrorMessage(string p_message)
{
	cout << "ERROR : " << p_message << endl ;
}
