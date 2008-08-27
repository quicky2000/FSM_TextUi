#ifndef FSM_TEXT_UI_H
#define FSM_TEXT_UI_H

#include "framework_UI_if.h"

#include <vector>

class framework_controler;

class FSM_TextUi: public framework_UI_if
{
 public:
  FSM_TextUi(void);
  void run(void);

  // Methods inherited from framework_UI_if
  void displayLoadedFsm(std::vector<std::string> *p_fsm_list);
  void displayLoadedFsmUi(std::vector<std::string> *p_fsm_ui_list);
  void displayLoadedAlgorithm(std::vector<std::string> *p_algorithm_list);
  void displayWarningMessage(std::string p_message);
  void displayErrorMessage(std::string p_message);

 private:
  unsigned int displayMenu(void);
  framework_controler *m_framework;
};
#endif /* FSM_TEXT_UI_H */
