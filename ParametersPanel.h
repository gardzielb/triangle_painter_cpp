//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_PARAMETERSPANEL_H
#define TRIANGLE_PAINTER_PARAMETERSPANEL_H


#include <QtWidgets/QWidget>
#include <QObject>
#include <QtWidgets/QColorDialog>
#include <QFileDialog>
#include "ui_parameters.h"
#include "PainterSettings.h"

class ParametersPanel : public QWidget
{
Q_OBJECT

signals:

	void rowCountChanged( int row_count );

	void colCountChanged( int col_count );

	void gridReset();

	void settingsChanged( PainterSettings & settings );

private:
	Ui_ParametersPanel ui;
	PainterSettings settings;

	const static int DEFAULT_ROW_COUNT = 10;
	const static int DEFAULT_COL_COUNT = 10;
//	const static QColor DEFAULT_PAINT_COLOR;
//	const static QColor DEFAULT_LIGHT_COLOR;

public:
	ParametersPanel() : ui(), settings()
	{
		ui.setupUi( this );

		ui.row_spin->setValue( DEFAULT_ROW_COUNT );
		ui.col_spin->setValue( DEFAULT_COL_COUNT );

		connect_signals();
	}

private:
	void connect_signals()
	{
		QObject::connect(
				ui.row_spin, QOverload<int>::of( &QSpinBox::valueChanged ),
				[ = ]( int val ) { emit rowCountChanged( val ); }
		);
		QObject::connect(
				ui.col_spin, QOverload<int>::of( &QSpinBox::valueChanged ),
				[ = ]( int val ) { emit colCountChanged( val ); }
		);
		QObject::connect( ui.reset_grid_button, &QPushButton::clicked, [ = ]() { emit gridReset(); } );

		QObject::connect( ui.paint_texture_button, &QPushButton::clicked, this, &ParametersPanel::choose_paint_image );
		QObject::connect( ui.paint_color_button, &QPushButton::clicked, this, &ParametersPanel::choose_paint_color );
		QObject::connect( ui.light_color_button, &QPushButton::clicked, this, &ParametersPanel::choose_light_color );
	}

private slots:

	void choose_light_color()
	{
		settings.light_color = QColorDialog::getColor();
		emit settingsChanged( settings );
	};

	void choose_paint_color()
	{
		settings.fill_color = QColorDialog::getColor();
		emit settingsChanged( settings );
	};

	void choose_paint_image()
	{
		QString img_file = QFileDialog::getOpenFileName();
		delete settings.image;
		auto img = new QImage( img_file );
		settings.image = new QImage( std::move( img->scaled( 800, 800, Qt::IgnoreAspectRatio ) ) );
		delete img;
		emit settingsChanged( settings );
	};
};

//const QColor ParametersPanel::DEFAULT_PAINT_COLOR = QColor( 120, 255, 120 );
//const QColor ParametersPanel::DEFAULT_LIGHT_COLOR = QColor( 255, 255, 255 );


#endif //TRIANGLE_PAINTER_PARAMETERSPANEL_H
