//
// Created by bartosz on 11/3/20.
//

#ifndef TRIANGLE_PAINTER_PARAMETERSPANEL_H
#define TRIANGLE_PAINTER_PARAMETERSPANEL_H


#include <iostream>
#include <string>
#include <QtWidgets/QWidget>
#include <QObject>
#include <QtWidgets/QColorDialog>
#include <QFileDialog>
#include "ui_parameters.h"
#include "PainterSettings.h"
#include "ColorButtonWrapper.h"

class ParametersPanel : public QWidget
{
Q_OBJECT

signals:

//	void rowCountChanged( int row_count );
//	void colCountChanged( int col_count );

	void gridReset( int row_count, int col_count );

	void settingsChanged( PainterSettings & settings );

private:
	Ui_ParametersPanel ui;
	PainterSettings settings;
	ColorButtonWrapper * paint_color_chooser = nullptr;
	ColorButtonWrapper * light_color_chooser = nullptr;

	const static int DEFAULT_ROW_COUNT = 10;
	const static int DEFAULT_COL_COUNT = 10;

public:
	ParametersPanel() : ui(), settings()
	{
		ui.setupUi( this );

		ui.row_spin->setValue( DEFAULT_ROW_COUNT );
		ui.col_spin->setValue( DEFAULT_COL_COUNT );

		ui.kd_slider->setValue( 0.5 * ui.kd_slider->maximum() );
		ui.ks_slider->setValue( 0.5 * ui.ks_slider->maximum() );

		set_label_text( ui.m_label, ui.m_slider->value() );
		set_label_text( ui.kd_label, (float) ui.kd_slider->value() / ui.kd_slider->maximum() );
		set_label_text( ui.ks_label, (float) ui.ks_slider->value() / ui.ks_slider->maximum() );

		paint_color_chooser = new ColorButtonWrapper( *ui.paint_color_button, settings.fill_color );
		light_color_chooser = new ColorButtonWrapper( *ui.light_color_button, settings.light_color );

		connect_signals();
	}

	~ParametersPanel() override
	{
		delete paint_color_chooser;
		delete light_color_chooser;
	}

private:
	void connect_signals()
	{
//		QObject::connect(
//				ui.row_spin, QOverload<int>::of( &QSpinBox::valueChanged ),
//				[ = ]( int val ) { emit rowCountChanged( val ); }
//		);
//		QObject::connect(
//				ui.col_spin, QOverload<int>::of( &QSpinBox::valueChanged ),
//				[ = ]( int val ) { emit colCountChanged( val ); }
//		);
		QObject::connect(
				ui.reset_grid_button, &QPushButton::clicked,
				[ = ]() { emit gridReset( ui.row_spin->value(), ui.col_spin->value() ); }
		);

		QObject::connect( ui.paint_texture_button, &QPushButton::clicked, this, &ParametersPanel::load_paint_image );
		QObject::connect( ui.normal_map_button, &QPushButton::clicked, this, &ParametersPanel::load_normal_map );

		QObject::connect(
				paint_color_chooser, &ColorButtonWrapper::colorChosen, this, &ParametersPanel::change_paint_color
		);
		QObject::connect(
				light_color_chooser, &ColorButtonWrapper::colorChosen, this, &ParametersPanel::change_light_color
		);

		QObject::connect( ui.m_slider, &QSlider::valueChanged, [ = ]( int m ) { set_label_text( ui.m_label, m ); } );
		QObject::connect(
				ui.kd_slider, &QSlider::valueChanged,
				[ = ]( int kd ) { update_kd( (float) kd / ui.kd_slider->maximum(), true ); }
		);
		QObject::connect(
				ui.ks_slider, &QSlider::valueChanged,
				[ = ]( int ks ) { update_ks( (float) ks / ui.ks_slider->maximum(), true ); }
		);

		QObject::connect(
				ui.m_slider, &QSlider::sliderReleased,
				[ = ]() { change_slider_param( &settings.m, ui.m_slider->value() ); }
		);
		QObject::connect(
				ui.kd_slider, &QSlider::sliderReleased,
				[ = ]() {
					change_slider_param( &settings.kd, (float) ui.kd_slider->value() / ui.kd_slider->maximum() );
				}
		);
		QObject::connect(
				ui.ks_slider, &QSlider::sliderReleased,
				[ = ]() {
					change_slider_param( &settings.ks, (float) ui.ks_slider->value() / ui.ks_slider->maximum() );
				}
		);

		QObject::connect(
				ui.constant_paint_radio, &QRadioButton::clicked,
				[ = ]( bool checked ) { change_radio_param( &settings.texture_paint, !checked ); }
		);
		QObject::connect(
				ui.texture_paint_radio, &QRadioButton::clicked,
				[ = ]( bool checked ) { change_radio_param( &settings.texture_paint, checked ); }
		);
		QObject::connect(
				ui.constant_light_radio, &QRadioButton::clicked,
				[ = ]( bool checked ) { change_radio_param( &settings.spherical_light, !checked ); }
		);
		QObject::connect(
				ui.sphere_light_radio, &QRadioButton::clicked,
				[ = ]( bool checked ) { change_radio_param( &settings.spherical_light, checked ); }
		);
		QObject::connect(
				ui.precise_paint_radio, &QRadioButton::clicked,
				[ = ]( bool checked ) { change_radio_param( &settings.vertex_interpolation, !checked ); }
		);
		QObject::connect(
				ui.vertex_paint_radio, &QRadioButton::clicked,
				[ = ]( bool checked ) { change_radio_param( &settings.vertex_interpolation, checked ); }
		);
		QObject::connect(
				ui.constant_n_radio, &QRadioButton::clicked,
				[ = ]( bool checked ) { change_radio_param( &settings.texture_normal_map, !checked ); }
		);
		QObject::connect(
				ui.texture_n_radio, &QRadioButton::clicked,
				[ = ]( bool checked ) { change_radio_param( &settings.texture_normal_map, checked ); }
		);
	}

private slots:

	void change_light_color( const QColor & color )
	{
		settings.light_color = color;
		emit settingsChanged( settings );
	};

	void change_paint_color( const QColor & color )
	{
		settings.fill_color = color;
		emit settingsChanged( settings );
	};

	void change_radio_param( bool * param, bool value )
	{
		*param = value;
		emit settingsChanged( settings );
	}

	void load_paint_image()
	{
		QString img_file = QFileDialog::getOpenFileName();
		delete settings.image;
		auto img = new QImage( img_file );
		settings.image = new QImage( std::move( img->scaled( 810, 810, Qt::IgnoreAspectRatio ) ) );
		delete img;
		ui.texture_paint_radio->setEnabled( true );
	}

	void load_normal_map()
	{
		QString img_file = QFileDialog::getOpenFileName();
		delete settings.normal_map;
		auto img = new QImage( img_file );
		settings.normal_map = new NormalMap( img->scaled( 810, 810, Qt::IgnoreAspectRatio ) );
		delete img;
		ui.texture_n_radio->setEnabled( true );
	}

	void change_slider_param( int * param, int value )
	{
		*param = value;
		emit settingsChanged( settings );
	}

	void change_slider_param( float * param, float value )
	{
		*param = value;
		emit settingsChanged( settings );
	}

	void update_kd( float kd, bool user_call )
	{
		set_label_text( ui.kd_label, kd );
		settings.kd = kd;

		if ( user_call )
		{
			ui.ks_slider->setValue( ui.ks_slider->maximum() * (1 - kd) );
			update_ks( 1 - kd, false );
		}
	}

	void update_ks( float ks, bool user_call )
	{
		set_label_text( ui.ks_label, ks );
		settings.ks = ks;

		if ( user_call )
		{
			ui.kd_slider->setValue( ui.kd_slider->maximum() * (1 - ks) );
			update_kd( 1 - ks, false );
		}
	}

private:
	static void set_label_text( QLabel * label, float value )
	{
		label->setText( QString::fromStdString( std::to_string( value ) ) );
	}
};

#endif //TRIANGLE_PAINTER_PARAMETERSPANEL_H
