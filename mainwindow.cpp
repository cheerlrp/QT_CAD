#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"openglwidget.h"
#include<QTextStream>
#include<QStringList>
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}






/*****************************平移按键的声明******************************/

void MainWindow::on_leftPushButton_clicked()
{
	ui->widget->XCooridinateSub();
	ui->widget->update();
}

void MainWindow::on_rightPushButton_clicked()
{
	ui->widget->XCooridinateAdd();
	ui->widget->update();
}

void MainWindow::on_upPushButton_clicked()
{
	ui->widget->YCooridinateAdd();
	ui->widget->update();
}

void MainWindow::on_downPushButton_clicked()
{
	ui->widget->YCooridinateSub();
	ui->widget->update();
}






/***************************************打开文件*****************************************/
void MainWindow::on_actionopen_triggered() {

	QString filename = QFileDialog::getOpenFileName(this, "get file", "../open_file/",
		"IGES (*.iges *.igs);;HEADER (*.h);;TXT (*.txt)");
	if (filename.isEmpty()) {
		QMessageBox::warning(this, "warning", "open err");
		return;
	}
	std::string str_name = filename.toStdString();
	std::ifstream infile;
	infile.open(str_name);


	DataGetInit(str_name, Data);   //IGES获取信息
	int a = Data.Count126;

}









/**********************************获取IGES的信息*************************************/
void MainWindow::DataGetInit(std::string filename, IgesData &Data)
{
	std::ifstream infile(filename, std::ios::in);
	int test = 0, element;
	Data.Count126 = 0;
	char elem, S[7], G[7], D[7], P[7];
	infile.seekg(-82, std::ios::end);

	infile >> elem;
	for (int i = 0; i < 7; i++)
	{
		infile >> S[i];
	}

	infile >> elem;
	for (int i = 0; i < 7; i++)
	{
		infile >> G[i];
	}

	infile >> elem;
	for (int i = 0; i < 7; i++)
	{
		infile >> D[i];
	}

	infile >> elem;
	for (int i = 0; i < 7; i++)
	{
		infile >> P[i];
	}

	Data.S_Num = std::atoi(S);//将字符转换为整数S段行数
	Data.G_Num = std::atoi(G);//将字符转换为整数G段行数
	Data.D_Num = std::atoi(D);//将字符转换为整数D段行数
	Data.P_Num = std::atoi(P);//将字符转换为整数P段行数

	infile.seekg(82 * Data.S_Num, std::ios::beg);
	for (int i = 0; i < 3; i++)
		infile >> elem;
	Data.Argument_Separator = elem;
	for (int i = 0; i < 4; i++)
		infile >> elem;
	Data.Record_Separator = elem;

	int count = 0, count_num = 14, k = 1;
	if (Data.Record_Separator == ',')//若为“，”则加一
		count_num++;

	infile.seekg(0, std::ios::beg);

	while (count != count_num)
	{
		for (int i = 0; i < 81; i++)
		{
			infile >> elem;
			if (elem == Data.Argument_Separator)
			{
				count++;
				//printf("\n%d",count);
			}
			if (count == count_num)
				break;
		}
		if (count != count_num)
		{
			infile.seekg(82 * (k + 1), std::ios::beg);
			k++;
		}
	}
	infile.seekg(-3, std::ios::cur);
	infile >> elem;

	if (elem == 'D')
		Data.version = 1;
	else
		Data.version = 0;


	for (int i = 0; i < Data.D_Num / 2; i++)
	{
		infile.seekg(82 * (Data.S_Num + Data.G_Num + test), std::ios::beg);
		infile >> element;
		if (element == 126)
		{
			Data.Count126++;
		}
		test = test + 2;
	}

}