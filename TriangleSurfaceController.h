//
// Created by bartosz on 11/7/20.
//

#ifndef TRIANGLE_PAINTER_TRIANGLESURFACECONTROLLER_H
#define TRIANGLE_PAINTER_TRIANGLESURFACECONTROLLER_H

#include "TriangleSurface.h"
#include "ParametersPanel.h"
#include <QObject>

class TriangleSurfaceController
{
private:
	TriangleSurface * surface = nullptr;
	ParametersPanel * params_panel = nullptr;

public:
	TriangleSurfaceController( TriangleSurface * surface, ParametersPanel * params_panel )
	{
		this->surface = surface;
		this->params_panel = params_panel;

		QObject::connect(
				params_panel, &ParametersPanel::rowCountChanged, surface, &TriangleSurface::change_row_count
		);

		QObject::connect(
				params_panel, &ParametersPanel::colCountChanged, surface, &TriangleSurface::change_column_count
		);
	}
};


#endif //TRIANGLE_PAINTER_TRIANGLESURFACECONTROLLER_H
