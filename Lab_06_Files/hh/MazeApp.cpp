#include "wx/wx.h"
#include "wx/sizer.h"

#include "MazeGUI.h"

class MazeApp: public wxApp
{
	public:
		bool OnInit();
};

IMPLEMENT_APP(MazeApp)
 
bool MazeApp::OnInit()
{
	Matrix* mat = Matrix::readMatrix("maze.txt");
	Maze* maze = new Maze(mat);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    MazeGUI* maze_frame = new MazeGUI(maze);
	maze->addListener((Update*) maze_frame);
 
 	DrawPanel* maze_display_panel = new DrawPanel(maze_frame, maze);
	maze_frame->setDrawPanel(maze_display_panel);

	wxButton* maze_solve_button = new wxButton(maze_frame, wxID_HIGHEST + 1, wxT("Solve Maze"), wxPoint(25,375), wxSize(100, 25), 0);
	maze_solve_button->SetBackgroundColour(*wxWHITE);
    sizer->Add(maze_display_panel, 9, wxEXPAND);
	sizer->Add(maze_solve_button, 1, wxEXPAND);
 
    maze_frame->SetSizer(sizer);
    maze_frame->SetAutoLayout(true);
 
    maze_frame->Show();
    return true;
} 
