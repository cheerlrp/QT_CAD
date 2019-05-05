#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"opengl32.lib")
#include "openglwidget.h"
#include "ui_openglwidget.h"

openglwidget::openglwidget(QWidget *parent) :
	QOpenGLWidget(parent),
	ui(new Ui::openglwidget)
{
	m_x = 0.0;
	m_y = 0.0;
	m_z = 0.0;

	ui->setupUi(this);
}

openglwidget::~openglwidget()
{
	delete ui;
}



/**********************中键滚轮************************/
void openglwidget::wheelEvent(QWheelEvent *e)
{
	QPoint qpMag = e->angleDelta();
	int iMag = qpMag.y();
	bool bUpdate = false;
	if (iMag < 0)
	{
		// if(m_iMag < 16)
	   // {
		m_iMag *= 2;
		bUpdate = true;
		// }
	}

	if (iMag > 0)
	{
		//  if(m_iMag > 1)
		  //{

		m_iMag *= 0.5;
		bUpdate = true;
		// }
	}

	if (bUpdate)
	{
		update();
	}
}





void openglwidget::initializeGL()
{
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	m_iMag = 1;
}

void openglwidget::resizeGL(int width, int height)
{
	/*glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w / h, 0.01, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);*/

	//if(w > 0 && h >0)
 //   {
 //       glViewport(0, 0, (GLint)w, (GLint)h);//这句话把显示的范围跟glWindow范围划了等号
 //       m_iWidth = w;
 //       m_iHeight = h;
 //   }
	//



	if (0 == height)
		height = 1;//防止一条边为0
	glViewport(0, 0, (GLint)width, (GLint)height);//重置当前视口，本身不是重置窗口的，只不过是这里被Qt给封装好了

	m_width = width; m_height = height;

	/*double left		=  - m_width ;
	double right	=  m_width;
	double bottom	=  - m_height;
	double top		=  m_height;
	double m_near		=  - m_width ;
	double m_far	=  m_width;
	int a = 1;*/
	//glOrtho(left*a ,right*a ,bottom*a ,top*a ,1,100 );




	//gluLookAt(0.0 , 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);




}

void openglwidget::paintGL()
{
	//glClearColor(1, 1, 1,1);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    GLUnurbsObj *theNurb= gluNewNurbsRenderer();
//	
//	 gluNurbsProperty(theNurb,GLU_SAMPLING_TOLERANCE,25.0);
//    GLfloat ctrlpoints[9][3] = {{0.343,0.057,0},{0.804, 0.052,0},{0.655,0.146,0},
//                             {0.004,0.840,0}, {0.756,0.882,0},{0.930,0.988,0},
//                             {0.357,0.256,0},{0.178, 0.209,0},{0.149,0.720,0} };//控制点
//
//	   //Point2D        //new 一个动态二维数组
//    //ctrlpoints = new float [9*3];
//    // for(int i=0;i<9;i++)          //给二维数组赋值
//    //{
//    //    for(int j=0;j<3;j++)
//    //    {
//    //      ; //把控制点数据传给变量
//    //    }
//    //}
//
//    GLfloat knots[13] = {0,0,0,0,0.174058,0.386051,0.551328,0.693068,0.834781,1,1,1,1};
//
//   // 然后调用函数：
//               gluBeginCurve(theNurb);
//               glColor3f(0.0,0.0,0.0);
//               gluNurbsCurve(theNurb,13,knots,3,&ctrlpoints[0][0],4,GL_MAP1_VERTEX_3);
//               gluEndCurve(theNurb);
//			  
//			   if(theNurb)
//		        gluDeleteNurbsRenderer(theNurb);
//		
//	/*glBegin(GL_LINES);
//    glColor3f(0.0, 1.0,  0.0);
//	glVertex2f( 0.0f, 0.0f);
//    glVertex2f( -0.3f, 0.1f);
//	glEnd();*/
//

	//glMatrixMode(GL_PROJECTION);
 //   glLoadIdentity();
 //   
	////gluPerspective(10.0 /** m_iMag*/, m_iWidth / m_iHeight, -16.0, 16.0);

	////glOrtho(left,right,bottom,top,m_near,m_far);

 //   glMatrixMode(GL_MODELVIEW);
 //   glLoadIdentity();


	glMatrixMode(GL_PROJECTION);//选择投影矩阵
	glLoadIdentity();//单位化矩阵
	if (0 == m_height)
		m_height = 1;//防止一条边为0
	glViewport(0, 0, (GLint)m_width, (GLint)m_height);//重置当前视口，本身不是重置窗口的，只不过是这里被Qt给封装好了
	



	GLfloat nRange = 100.0f*m_iMag;
	if (m_width <= m_height)
		glOrtho(-nRange, nRange, -nRange*m_height / m_width, nRange*m_height / m_width, -nRange, nRange);
	else
		glOrtho(-nRange*m_width / m_height, nRange*m_width / m_height, -nRange, nRange, 0, 500);
	
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//单位化矩阵

	gluLookAt((GLdouble)m_x, (GLdouble)m_y, 0.5, (GLdouble)m_x, (GLdouble)m_y, 0.0, 0.0, 1.0, 0.0);



	//三角形
	/* glBegin(GL_TRIANGLES);
		 glColor3f(1.0, 0.0, 0.0);
		 glVertex3f(-500, -500, 0);
		 glColor3f(0.0, 1.0, 0.0);
		 glVertex3f( 500, -500, 0);
		 glColor3f(0.0, 0.0, 1.0);
		 glVertex3f( 0.0,  500, 0);
	 glEnd();*/



	//坐标轴
	 /*glBegin( GL_LINES );
		   {
				x-axis
		  glColor3f(0.0, 0.0, 0.0);
			   glVertex3f( -100.0f, 0.0f, 0.0f);
			   glVertex3f( 100.0f, 0.0f, 0.0f);

				x-axis arrow

			   glVertex3f( 100.0f, 0.0f, 0.0f);
			   glVertex3f( 93.0f, 3.0f, 0.0f);
			   glVertex3f( 100.0f, 0.0f, 0.0f);
			   glVertex3f( 93.0f,-3.0f, 0.0f);

				y-axis

			   glVertex3f( 0.0f, -100.0f, 0.0f);
			   glVertex3f( 0.0f, 100.0f, 0.0f);

				y-axis arrow
			   glVertex3f( 0.0f, 100.0f, 0.0f);
			   glVertex3f( 3.0f, 93.0f, 0.0f);
			   glVertex3f( 0.0f, 100.0f, 0.0f);
			   glVertex3f( -3.0f, 93.0f, 0.0f);
		   }
		   glEnd();
*/









	GLfloat ctrlpoints[9][3] = { {47.343,23.057,0.0},{46.804,23.052,0},{45.655,23.146,0},
							 {44.004,23.84,0}, {42.756,24.882,0},{41.93,25.988,0},
							{41.357,27.256,0},{41.178,28.209,0},{41.149,28.72,0} };//控制点

	std::vector<Point2D>pt;
	pt.resize(20);
	for (int i = 0; i < 9; i++)          //给二维数组赋值
	{
		int j = 0;
		pt[i + 1].x = ctrlpoints[i][j];
		pt[i + 1].y = ctrlpoints[i][j + 1];
		pt[i + 1].z = ctrlpoints[i][j + 2];

	}
	GLfloat knot[13] = { 0,0,0,0,0.174058,0.386051,0.551328,0.693068,0.834781,1,1,1,1 };



	DrawNurbsCurve(pt, 9, knot);
}





/******************************画nurbs曲线*********************************/
void openglwidget::DrawNurbsCurve(std::vector<Point2D> pts, int size, float* knots)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLUnurbsObj *theNurb = gluNewNurbsRenderer();

	gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 25.0);


	GLfloat* ctrlPts = new GLfloat[size * 3];
	for (int i = 0; i < size; i++) {
		ctrlPts[i * 3] = pts[i].x;
		ctrlPts[i * 3 + 1] = pts[i].y;
		ctrlPts[i * 3 + 2] = pts[i].z;
	}
	glLineWidth(3.0);
	gluBeginCurve(theNurb);
	glColor3f(0.0, 0.0, 0.0);
	gluNurbsCurve(theNurb, 13, knots, 3, ctrlPts, 4, GL_MAP1_VERTEX_3);
	gluEndCurve(theNurb);

	if (theNurb)
		gluDeleteNurbsRenderer(theNurb);
	delete[] ctrlPts;



	//GLfloat ctrlpoints[9][3] = {{0.343,0.057,0},{0.804, 0.052,0},{0.655,0.146,0},
	//                         {0.004,0.840,0}, {0.756,0.882,0},{0.930,0.988,0},
	//                         {0.357,0.256,0},{0.178, 0.209,0},{0.149,0.720,0} };//控制点

	   //Point2D        //new 一个动态二维数组
	//ctrlpoints = new float [9*3];
	// for(int i=0;i<9;i++)          //给二维数组赋值
	//{
	//    for(int j=0;j<3;j++)
	//    {
	//      ; //把控制点数据传给变量
	//    }
	//}

	//GLfloat knots[13] = {0,0,0,0,0.174058,0.386051,0.551328,0.693068,0.834781,1,1,1,1};

   // 然后调用函数：


}


/*************************平移按键***********************/
void openglwidget::XCooridinateAdd()
{
	m_x -= 10;
}

void openglwidget::XCooridinateSub()
{
	m_x += 10;
}

void openglwidget::YCooridinateAdd()
{
	m_y -= 10;
}

void openglwidget::YCooridinateSub()
{
	m_y += 10;
}

