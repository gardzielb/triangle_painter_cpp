//
// Created by bartosz on 11/9/20.
//

#ifndef TRIANGLE_PAINTER_PAINTCOMMAND_H
#define TRIANGLE_PAINTER_PAINTCOMMAND_H


#include <QtGui/QColor>
#include <QtGui/QPainter>

class PaintCommand
{
public:
	virtual void execute( int x, int y, const QColor & color ) = 0;

	virtual ~PaintCommand() = default;
};


class QPainterPaintCommand : public PaintCommand
{
private:
	QPainter * painter = nullptr;

public:
	explicit QPainterPaintCommand( QPainter * painter )
	{
		this->painter = painter;
	}

	void execute( int x, int y, const QColor & color ) override
	{
		painter->setPen( color );
		painter->drawPoint( x, y );
	}
};

class ImagePixelPaintCommand : public PaintCommand
{
private:
	QRgb * pixels = nullptr;
	int img_height = 0;

public:
	explicit ImagePixelPaintCommand( QRgb * pixels, int img_height )
			: img_height( img_height )
	{
		this->pixels = pixels;
	}

	void execute( int x, int y, const QColor & color ) override
	{
		pixels[x + y * img_height] = color.rgb();
	}
};


#endif //TRIANGLE_PAINTER_PAINTCOMMAND_H
