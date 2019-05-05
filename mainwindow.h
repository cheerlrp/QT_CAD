#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
	class MainWindow;
}



/************************iges的结构体******************/
typedef struct IgesData//IGES数据的基本信息
{
	int version, S_Num, G_Num, D_Num, P_Num, Count126;
	char Argument_Separator, Record_Separator;//参数分隔符默认为一个字符,记录分隔符默认为一个字符
};








class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();


	void DataGetInit(std::string filename, IgesData &Data);//获取IGES的信息
	IgesData Data;



	private slots:

	void on_actionopen_triggered(); //OPEN的槽文件

	/*************************按键移动定义*******************************/
	void on_leftPushButton_clicked();
	void on_rightPushButton_clicked();
	void on_upPushButton_clicked();
	void on_downPushButton_clicked();




private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
