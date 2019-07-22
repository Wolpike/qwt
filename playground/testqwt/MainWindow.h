#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class Plot;

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
private:
    Plot* m_plot;
};
