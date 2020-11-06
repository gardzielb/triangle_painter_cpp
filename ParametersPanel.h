//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_PARAMETERSPANEL_H
#define TRIANGLE_PAINTER_PARAMETERSPANEL_H


#include <QtWidgets/QWidget>
#include "ui_parameters.h"

class ParametersPanel : public QWidget
{
private:
	Ui_ParametersPanel ui;

	const static int DEFAULT_ROW_COUNT = 10;
	const static int DEFAULT_COL_COUNT = 10;
//	const static QColor DEFAULT_PAINT_COLOR;
//	const static QColor DEFAULT_LIGHT_COLOR;

public:
	ParametersPanel() : ui()
	{
		ui.setupUi( this );

		ui.row_spin->setValue( DEFAULT_ROW_COUNT );
		ui.col_spin->setValue( DEFAULT_COL_COUNT );
	}
};

//const QColor ParametersPanel::DEFAULT_PAINT_COLOR = QColor( 120, 255, 120 );
//const QColor ParametersPanel::DEFAULT_LIGHT_COLOR = QColor( 255, 255, 255 );


#endif //TRIANGLE_PAINTER_PARAMETERSPANEL_H
