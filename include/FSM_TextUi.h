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
#ifndef FSM_TEXT_UI_H
#define FSM_TEXT_UI_H

#include "framework_UI_if.h"

#include <vector>

namespace FSM_framework
{
  class framework_controler;
}

namespace FSM_TextUi
{
  class FSM_TextUi: public FSM_framework::framework_UI_if
  {
  public:
    FSM_TextUi(void);
    ~FSM_TextUi(void);
    void run(void);

    // Methods inherited from framework_UI_if
    void display_loaded_fsm(const std::vector<std::string> & p_fsm_list);
    void display_loaded_fsm_ui(const std::vector<std::string> & p_fsm_ui_list);
    void display_loaded_algorithm(const std::vector<std::string> & p_algorithm_list);
    void display_warning_message(const std::string & p_message);
    void display_error_message(const std::string & p_message);

  private:
    unsigned int display_menu(void);
    FSM_framework::framework_controler *m_framework;
  };
}
#endif /* FSM_TEXT_UI_H */
//EOF
