#ifndef _FSM_TEXT_UI_H_
#define _FSM_TEXT_UI_H_

#include "framework_UI_if.h"

#include <vector>
using namespace std;

class framework_controler;

class FSM_TextUi: public framework_UI_if
{
	public:
		FSM_TextUi(void);
		void run(void);

		// Methods inherited from framework_UI_if
		void displayLoadedFsm(vector<string> *p_fsm_list);
		void displayLoadedFsmUi(vector<string> *p_fsm_ui_list);
		void displayLoadedAlgorithm(vector<string> *p_algorithm_list);
		void displayWarningMessage(string p_message);
		void displayErrorMessage(string p_message);

	private:
		unsigned int displayMenu(void);
		framework_controler *m_framework;
};
#endif
