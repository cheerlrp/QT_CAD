#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
	class MainWindow;
}



/************************iges�Ľṹ��******************/
typedef struct IgesData//IGES���ݵĻ�����Ϣ
{
	int version, S_Num, G_Num, D_Num, P_Num, Count126;
	char Argument_Separator, Record_Separator;//�����ָ���Ĭ��Ϊһ���ַ�,��¼�ָ���Ĭ��Ϊһ���ַ�
};








class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();


	void DataGetInit(std::string filename, IgesData &Data);//��ȡIGES����Ϣ
	IgesData Data;



	private slots:

	void on_actionopen_triggered(); //OPEN�Ĳ��ļ�

	/*************************�����ƶ�����*******************************/
	void on_leftPushButton_clicked();
	void on_rightPushButton_clicked();
	void on_upPushButton_clicked();
	void on_downPushButton_clicked();




private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
