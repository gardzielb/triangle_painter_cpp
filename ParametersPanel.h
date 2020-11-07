//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_PARAMETERSPANEL_H
#define TRIANGLE_PAINTER_PARAMETERSPANEL_H


#include <QtWidgets/QWidget>
#include <QObject>
#include "ui_parameters.h"

class ParametersPanel : public QWidget
{
Q_OBJECT

signals:

	void rowCountChanged( int row_count );

	void colCountChanged( int col_count );

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

		QObject::connect(
				ui.row_spin, QOverload<int>::of( &QSpinBox::valueChanged ),
				[ = ]( int val ) { emit rowCountChanged( val ); }
		);
		QObject::connect(
				ui.col_spin, QOverload<int>::of( &QSpinBox::valueChanged ),
				[ = ]( int val ) { emit colCountChanged( val ); }
		);
	}

public slots:

	void change_row_count( int row_count )
	{
		emit rowCountChanged( row_count );
	};
};

//const QColor ParametersPanel::DEFAULT_PAINT_COLOR = QColor( 120, 255, 120 );
//const QColor ParametersPanel::DEFAULT_LIGHT_COLOR = QColor( 255, 255, 255 );


#endif //TRIANGLE_PAINTER_PARAMETERSPANEL_H
