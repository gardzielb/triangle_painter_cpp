#include <QtGui/QScreen>
#include <QtCore/QUrl>
#include <QDebug>
#include <QtWidgets/QApplication>
#include "PainterWindow.h"

int main( int argc, char * argv[] )
{
	QApplication app( argc, argv );

	PainterWindow window;
	window.show();

	return QApplication::exec();
}