//
// Created by bartosz on 11/7/20.
//

#ifndef TRIANGLE_PAINTER_COLORBUTTONWRAPPER_H
#define TRIANGLE_PAINTER_COLORBUTTONWRAPPER_H

#include <QObject>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <utility>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QColorDialog>

class ColorButtonWrapper : public QObject
{
Q_OBJECT

signals:

	void colorChosen( QColor & color );

private:
	QLabel label;
	QPixmap pixmap;
	const int BUTTON_SIZE = 25;

public:
	ColorButtonWrapper( QPushButton & button, const QColor & color )
			: label(), pixmap( button.width(), button.height() )
	{
		pixmap.fill( color );

		button.setFixedSize( BUTTON_SIZE, BUTTON_SIZE );
		label.setFixedSize( button.width(), button.height() );
		label.setPixmap( pixmap );

		QVBoxLayout layout;
		layout.addWidget( &label );
		button.setLayout( &layout );

		QObject::connect( &button, &QPushButton::clicked, this, &ColorButtonWrapper::choose_color );
	}

private slots:

	void choose_color()
	{
		QColor color = QColorDialog::getColor();
		if ( color.isValid() )
		{
			pixmap.fill( color );
			label.setPixmap( pixmap );
			emit colorChosen( color );
		}
	};
};


#endif //TRIANGLE_PAINTER_COLORBUTTONWRAPPER_H
