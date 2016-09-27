#include "MazeGUI.h"

DWORD WINAPI traverseMaze(LPVOID* parameters)
{
   MazeGUI* maze_frame = (MazeGUI*) (parameters[0]);
   maze_frame->solve();
}

void MazeGUI::startMazeThread()
{
   //start a new thread to solve the maze
   LPVOID* params = new LPVOID[1];
   params[0] = this;
   CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) traverseMaze, params, 0, NULL);
}

BEGIN_EVENT_TABLE (MazeGUI, wxFrame)
	EVT_BUTTON (wxID_HIGHEST + 1, MazeGUI::on_maze_button_click_event) 
END_EVENT_TABLE() 
  
MazeGUI::MazeGUI(Maze* m) : wxFrame((wxFrame *)NULL, -1,  wxT("Maze"), wxPoint(500,300), wxSize(875,438))
{
	maze = m;
}

void MazeGUI::setDrawPanel(DrawPanel* draw_panel)
{
   maze_panel = draw_panel;
}

void MazeGUI::update()
{
	Refresh();
}

void MazeGUI::solve()
{
   maze->solve();
}

void MazeGUI::on_maze_button_click_event(wxCommandEvent& evt)
{
   startMazeThread();
}

