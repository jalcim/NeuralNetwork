#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <vector>
#include "Controller.h"
#include "Console.h"
#include "ControllersManager.h"
#include <qfuturewatcher.h>

namespace Ui
{
	class MainWindow;
}

enum DisplayedSet
{
	testing = 0,
	training
};

class MainWindow : public QMainWindow
{
Q_OBJECT
public:

	explicit MainWindow(QWidget* parent = 0);
	void write(std::string text, bool onlyConsole = true);
	~MainWindow();


private:

	Ui::MainWindow* ui;
	Console* console;
	Controller* currentController;
	ControllersManager manager;

	int indexController = 0;

	std::vector<float> input;
	std::vector<float> desired;

	//list<std::vector<float>> desired_outputs;

	DisplayedSet displayedSet = testing;

	QMovie *loadingLogo = nullptr;
	QFutureWatcher<void> watcher;

	void compute();
	void initialize();
	void initializeNeuralNetwork();
	void refreshDataUI();
	void displayImage(int value);

	void StartLoadingLogo();

	int getLabel(int value, DisplayedSet displayedSet);
	void graphClusteringRate();

	unsigned char getImages(int number, int x, int y);
	bool flag_graph = true;

	QVector<double> clusteringRates;
	QVector<double> x;

private slots:

	void on_spinBoxImageId_valueChanged(int value);
	void on_pushButtonCompute_clicked();
	void on_comboBoxSet_currentIndexChanged(int index);
	void on_pushButtonConsole_clicked();

	void StopLoadingLogo();

	/* DATA */
	void on_comboBoxData_currentIndexChanged(int index);
};

#endif // MAINWINDOW_H
