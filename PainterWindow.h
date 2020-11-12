//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_PAINTERWINDOW_H
#define TRIANGLE_PAINTER_PAINTERWINDOW_H


#include <QtWidgets/QMainWindow>
#include "ParametersPanel.h"
#include "TriangleSurface.h"

class PainterWindow : public QMainWindow
{
private:
	ParametersPanel * params_panel = nullptr;
	TriangleSurface * triangle_surface = nullptr;
	QWidget * central_widget = new QWidget();

public:
	PainterWindow()
	{
		triangle_surface = new TriangleSurface( 10, 10 );
		params_panel = new ParametersPanel();
		connect_signals();

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

private:
	void connect_signals()
	{
		QObject::connect(
				params_panel, &ParametersPanel::gridReset, triangle_surface, &TriangleSurface::reset_grid
		);
		QObject::connect(
				params_panel, &ParametersPanel::settingsChanged, triangle_surface, &TriangleSurface::change_settings
		);
	}
};


#endif //TRIANGLE_PAINTER_PAINTERWINDOW_H
