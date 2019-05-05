#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include<vector>
#include <QGLWidget>
#include <QWheelEvent>

namespace Ui {
	class openglwidget;
}



class Point2D
{
public:

	double x, y, z;

private:

};






class openglwidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	explicit openglwidget(QWidget *parent = 0);
	~openglwidget();

	
	double          m_iMag;     //中键滚轮的变量  

	double	 	m_width, m_height;   //正交参数

	//////按键操作////////
	void XCooridinateAdd();
	void XCooridinateSub();
	void YCooridinateAdd();
	void YCooridinateSub();

	void DrawNurbsCurve(std::vector<Point2D> pts, int size, float* knots = NULL);//画nurbs曲线
private:
	Ui::openglwidget *ui;
	float m_x;
	float m_y;
	float m_z;


protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	virtual void wheelEvent(QWheelEvent *);
};

#endif // OPENGLWIDGET_H
