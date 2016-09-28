#ifndef MAZEGUI_H
#define MAZEGUI_H

#include "Maze.h"
#include "DrawPanel.h"

class MazeGUI: public wxFrame, Update
{
	private:
		Maze* maze;
		DrawPanel* maze_panel;
		
	public:
		MazeGUI(Maze* maze);
		void setDrawPanel(DrawPanel* draw_panel);
		void update();       
		void on_maze_button_click_event(wxCommandEvent& evt);

		void startMazeThread();
		void solve();
		
		DECLARE_EVENT_TABLE()
};

#endif 
