#include "MainWindow.h"
#include "Plot.h"

MainWindow::MainWindow()
{
    m_plot = new Plot;
    setCentralWidget(m_plot);
}
