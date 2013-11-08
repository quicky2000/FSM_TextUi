/*    This file is part of FSM_framework
      The aim of this software is to provided generic facilities for FSM analyzis
      Copyright (C) 2013  Julien Thevenon ( julien_thevenon at yahoo.fr )

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "FSM_TextUi.h"
#include "framework_controler.h"

#include <iostream>
using namespace std;

namespace FSM_TextUi
{
  //----------------------------------------------------------------------------
  FSM_TextUi::FSM_TextUi(void)
  {
    m_framework = new FSM_framework::framework_controler(this);
  }

  //----------------------------------------------------------------------------
  FSM_TextUi::~FSM_TextUi(void)
  {
    delete m_framework;
  }

  //----------------------------------------------------------------------------
  void FSM_TextUi::run(void)
  {
    unsigned int l_result = 0;
    bool l_continu = true;
    while(l_continu)
      {
        l_result = display_menu();
        switch(l_result)
          {
          case 1:
            {
              cout << " Enter library ?" << endl;
              string l_library ;
              cin >> l_library;
              m_framework->load_library(l_library);
            }
            break;
          case 2:
            {
              cout << " Enter fsm name ?" << endl;
              string l_fsm ;
              cin >> l_fsm;
              m_framework->select_fsm(l_fsm);
            }
            break;
          case 3:
            {
              cout << " Enter fsm ui name ?" << endl;
              string l_fsm_ui ;
              cin >> l_fsm_ui;
              m_framework->select_fsm_ui(l_fsm_ui);
            }
            break;
          case 4:
            {
              cout << " Enter algorithm name ?" << endl;
              string l_algorithm ;
              cin >> l_algorithm;
              m_framework->select_algorithm(l_algorithm);
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

  //----------------------------------------------------------------------------
  unsigned int FSM_TextUi::display_menu(void)
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


  //----------------------------------------------------------------------------
  void FSM_TextUi::display_loaded_fsm(const vector<string> & p_fsm_list)
  {
    cout << endl <<  "Loaded FSMs : " << endl;
    for(vector<string>::const_iterator l_iter = p_fsm_list.begin();
        p_fsm_list.end() != l_iter;
        ++l_iter)
      {
        cout << *l_iter << endl;
      }
    cout << "---------------" << endl << endl ;
  }

  //----------------------------------------------------------------------------
  void FSM_TextUi::display_loaded_fsm_ui(const vector<string> & p_fsm_ui_list)
  {
    cout << endl <<  "Loaded FSM_UIs : " << endl;
    for(vector<string>::const_iterator l_iter = p_fsm_ui_list.begin();
        p_fsm_ui_list.end() != l_iter;
        ++l_iter)
      {
        cout << *l_iter << endl;
      }
    cout << "---------------" << endl << endl ;
  }

  //----------------------------------------------------------------------------
  void FSM_TextUi::display_loaded_algorithm(const vector<string> & p_algorithm_list)
  {
    cout << endl <<  "Loaded algorithm : " << endl;
    for(vector<string>::const_iterator l_iter = p_algorithm_list.begin();
        p_algorithm_list.end() != l_iter;
        ++l_iter)
      {
        cout << *l_iter << endl;
      }
    cout << "---------------" << endl << endl ;
  }

  //----------------------------------------------------------------------------
  void FSM_TextUi::display_warning_message(const std::string & p_message)
  {
    cout << "WARNING : " << p_message << endl ;
  }

  //----------------------------------------------------------------------------
  void FSM_TextUi::display_error_message(const std::string & p_message)
  {
    cout << "ERROR : " << p_message << endl ;
  }
}
//EOF
