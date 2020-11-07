//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_PAINTERWINDOW_H
#define TRIANGLE_PAINTER_PAINTERWINDOW_H


#include <QtWidgets/QMainWindow>
#include "ParametersPanel.h"
#include "TriangleSurface.h"
#include "TriangleSurfaceController.h"

class PainterWindow : public QMainWindow
{
private:
	ParametersPanel * params_panel = nullptr;
	TriangleSurface * triangle_surface = nullptr;
	TriangleSurfaceController * controller = nullptr;
	QWidget * central_widget = new QWidget();

public:
	PainterWindow()
	{
		triangle_surface = new TriangleSurface( 10, 10 );
		params_panel = new ParametersPanel();
		controller = new TriangleSurfaceController( triangle_surface, params_panel );

		auto layout = new QHBoxLayout();
		layout->addWidget( triangle_surface );
		layout->addWidget( params_panel );

		central_widget->setLayout( layout );
		setCentralWidget( central_widget );

		setFixedSize( 1180, 840 );
	}

	~PainterWindow() override
	{
		delete params_panel;
		delete triangle_surface;
		delete central_widget;
	}
};


#endif //TRIANGLE_PAINTER_PAINTERWINDOW_H
